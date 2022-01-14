#include "image.hpp"
#include <iostream>

namespace buddy {

void deleteImage(raylib_image *image) {
    UnloadImage(*image);
    delete image;
}

Image::Image(const char *imagePath) : image(new raylib_image(LoadImage(imagePath))) {
    if (this->image->data == nullptr) {
        std::cout << "invalid image " << imagePath << std::endl;
        exit(1);
    }
}

void Image::save(const char *fileName) const {
    ExportImage(*this->image, fileName);
}

Color Image::getColorAt(const int &x, const int &y) const {
    unsigned char *data = (unsigned char *) this->image->data;
    int pixelPos = (y * this->image->width + x) * 4;
    Color color;
    color.r = data[pixelPos    ];
    color.g = data[pixelPos + 1];
    color.b = data[pixelPos + 2];
    color.a = data[pixelPos + 3];
    return color;
}

void Image::merge(const Image &image, const int &offsetX, const int &offsetY, const Color &color) {
    Color pixel;
    for (auto x = 0; x < image.width(); x++) {
        for (auto y = 0; y < image.height(); y++) {
            pixel = image.getColorAt(x, y);
            if (pixel.a > 0) {
                if (pixel.r == pixel.g && pixel.g == pixel.b) {
                    pixel.r = pixel.r / 255.0 * color.r;
                    pixel.g = pixel.g / 255.0 * color.g;
                    pixel.b = pixel.b / 255.0 * color.b;
                }
                
                ImageDrawPixel(this->image.get(), x + offsetX, y + offsetY, pixel);
            }         
        }
    }
}

void Image::copy(const Image &image, const int &offsetX, const int &offsetY) {
    for (auto x = 0; x < this->image->width; x++) {
        for (auto y = 0; y < this->image->height; y++) {
            ImageDrawPixel(this->image.get(), x, y, image.getColorAt(x + offsetX, y + offsetY));
        }
    }
}

};