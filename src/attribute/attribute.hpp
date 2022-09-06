#pragma once

#include "../image/image.hpp"
#include "attribute_list.hpp"
#include <string_view>

namespace buddy {

struct ImageAttribute {
    std::string_view name;
    Image image;

    ImageAttribute(std::string_view name, std::string_view imagePath) : name(name), image(imagePath.data()) {}
};

struct ColorAttribute : Color {
    std::string_view name;
    constexpr ColorAttribute(std::string_view name, uint64_t hex) : Color(hex), name(name) {}
};

struct ColoredImageAttribute : ImageAttribute {
    const AttributeList<ColorAttribute> *colors;
    ColoredImageAttribute(std::string_view name, std::string_view imagePath, const AttributeList<ColorAttribute> *colors = nullptr) : ImageAttribute(name, imagePath), colors(colors) {}
};

};
