#pragma once
#include "raylib_image.hpp"
#include <fstream>
#include <memory>

namespace buddy {

class Image {
    private:
        std::shared_ptr<raylib_image> image;
    public:
        Image(const char *imagePath);
        void save(const char *fileName) const;
        inline int width() const { return this->image->width; }
        inline int height() const { return this->image->height; }
        Color getColorAt(const int &x, const int &y) const;
        void merge(const Image &image, const int &offsetX, const int &offsetY, const Color &color = WHITE);
        void copy(const Image &image, const int &offsetX, const int &offsetY);
};

};