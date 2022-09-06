#pragma once

#include "nocopy.hpp"
#include <sstream>
#include <stdexcept>
#include "../attribute/color.hpp"

namespace buddy {

class Image : private NoCopy {
public:
    Image(const char *imagePath);
    Image(unsigned width, unsigned height);
    ~Image();
    void save(const char *fileName) const;
    constexpr unsigned width() const { return this->dimensions.width; }
    constexpr unsigned height() const { return this->dimensions.height; }
    void merge(const Image &image, unsigned offsetX, unsigned offsetY, Color color = WHITE);
    void copy(const Image &image, unsigned offsetX, unsigned offsetY);
    constexpr Color &getColorAt(unsigned x, unsigned y) {
        unsigned index = y * width() + x;
        return this->data[index];
    }
    constexpr const Color &getColorAt(unsigned x, unsigned y) const {
        unsigned index = y * width() + x;
        return this->data[index];
    }
private:
    Color *data;
    struct {
        unsigned width;
        unsigned height;
    } dimensions;
};

};