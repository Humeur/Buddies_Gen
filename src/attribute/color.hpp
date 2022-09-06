#pragma once

#include <string_view>
#include <bit>

namespace buddy {

struct Color {
    unsigned char r, g, b, a;
    constexpr Color() : r(0), g(0), b(0), a(0) {}
    constexpr Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : r(r), g(g), b(b), a(a) {}
    constexpr Color(unsigned hex) : r(hex >> 24), g(hex >> 16), b(hex >> 8), a(hex) {}
    constexpr Color(const unsigned char *rgba) : r(rgba[0]), g(rgba[1]), b(rgba[2]), a(rgba[3]) {}
};

constexpr inline Color WHITE(0xFFFFFFFF);

}