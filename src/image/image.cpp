#include "image.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
namespace buddy {

Image::Image(const char *imagePath) {
    int width, height, channels;

    this->data = reinterpret_cast<Color *>(stbi_load(imagePath, &width, &height, &channels, 4));
    if (!this->data) {
        std::stringstream ss;
        ss << "Failed to load image " << imagePath; 
        throw std::runtime_error(ss.str());
    }

    if (channels != 4) {
        std::stringstream ss;
        ss << "Image " << imagePath << " doesn't have 4 colors channels";
        throw std::runtime_error(ss.str());
    }
    this->dimensions.width = width;
    this->dimensions.height = height;
}

Image::Image(unsigned width, unsigned height) : data(new Color[width * height]), dimensions{width, height} {}

Image::~Image() {
    delete[] this->data;
}

void Image::save(const char *fileName) const {
    if (!stbi_write_png(fileName, width(), height(), 4, this->data, width() * 4)) {
        std::stringstream ss;
        ss << "Failed to save image " << fileName;
        throw std::runtime_error(ss.str());
    }
}

void Image::merge(const Image &image, unsigned offsetX, unsigned offsetY, Color color) {
    Color pixel;
    for (unsigned x = 0; x < image.width(); x++) {
        for (unsigned y = 0; y < image.height(); y++) {
            pixel = image.getColorAt(x, y);
            if (pixel.a > 0) {
                if (pixel.r == pixel.g && pixel.g == pixel.b) {
                    pixel.r = pixel.r / 255.0 * color.r;
                    pixel.g = pixel.g / 255.0 * color.g;
                    pixel.b = pixel.b / 255.0 * color.b;
                }
                
                getColorAt(x + offsetX, y + offsetY) = pixel;
            }         
        }
    }
}

void Image::copy(const Image &image, unsigned offsetX, unsigned offsetY) {
    for (auto x = 0; x < width(); x++) {
        for (auto y = 0; y < height(); y++) {
            getColorAt(x, y) = image.getColorAt(x + offsetX, y + offsetY);
        }
    }
}

};