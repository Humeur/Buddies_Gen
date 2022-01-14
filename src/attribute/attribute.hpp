#pragma once

#include "../image/image.hpp"

namespace buddy {

struct Attribute {
    std::string name;
    Image image;
};

struct HexColor : Color {
    std::string name;
    HexColor() {}
    HexColor(const char *name, unsigned int &&hex) : name(name) {
        for (unsigned char *ref : { &b, &g, &r }) {
            *ref = hex & 0xFF;
            hex >>= 8;
        }
        a = 255;
    }
};


};
