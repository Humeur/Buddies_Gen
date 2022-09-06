#pragma once

#include "color.hpp"
#include "attribute_list.hpp"

namespace buddy::top {

constexpr inline std::string_view ATTRIBUTE_NAME = "Top";
constexpr inline std::string_view COLOR_ATTRIBUTE_NAME = "Top color";

constexpr inline ColorAttribute RED("Red", 0xB71C1CFF);
constexpr inline ColorAttribute GREEN("Green", 0x1A6E1EFF);
constexpr inline ColorAttribute BLUE("Blue", 0x01589BFF);
constexpr inline ColorAttribute GREY("Grey", 0xB0B0B0FF);
constexpr inline ColorAttribute PURPLE("Purple", 0x7002CFFF);

const inline AttributeList<ColorAttribute> CAP_COLORS {
    { 1.0f, &RED },
    { 1.0f, &GREEN },
    { 1.0f, &BLUE }
};

const inline AttributeList<ColorAttribute> BEANIE_COLORS {
    { 1.0f, &RED },
    { 1.0f, &GREEN },
    { 1.0f, &BLUE },
    { 1.0f, &GREY }
};

const inline AttributeList<ColorAttribute> HIGH_HAT_COLORS {
    { 1.0f, &RED },
    { 1.0f, &PURPLE }
};

const inline ColoredImageAttribute CORRUPTED_CROWN("Corrupted crown", "assets/top/corrupted_crown.png");
const inline ColoredImageAttribute CROWN("Crown", "assets/top/crown.png");
const inline ColoredImageAttribute ANTENNA("Antenna", "assets/top/antenna.png");
const inline ColoredImageAttribute DEMON_HORN("Demon horn", "assets/top/demon_horn.png");
const inline ColoredImageAttribute ANGEL_RING("Angel ring", "assets/top/angel_ring.png");
const inline ColoredImageAttribute ARROW("Arrow", "assets/top/arrow.png");
const inline ColoredImageAttribute BUILDER_HAT("Builder hat", "assets/top/builder_hat.png");
const inline ColoredImageAttribute DOCTOR_MIRROR("Doctor mirror", "assets/top/doctor_mirror.png");
const inline ColoredImageAttribute HIGH_HAT("High hat", "assets/top/high_hat.png", &HIGH_HAT_COLORS);
const inline ColoredImageAttribute BRAIN("Brain", "assets/top/brain.png");
const inline ColoredImageAttribute CAP("Cap", "assets/top/cap.png", &CAP_COLORS);
const inline ColoredImageAttribute BEANIE("Beanie", "assets/top/beanie.png", &BEANIE_COLORS);
const inline ColoredImageAttribute STRAW_HAT("Straw hat", "assets/top/straw_hat.png");
const inline ColoredImageAttribute CHRISTMAS_HAT("Christmas hat", "assets/top/christmas_hat.png");

const inline AttributeList<ColoredImageAttribute> MALE {
    { 10.0f, &CORRUPTED_CROWN },
    { 10.0f, &CROWN },
    { 90.0f, &ANTENNA },
    { 90.0f, &DEMON_HORN },
    { 100.0f, &ANGEL_RING },
    { 100.0f, &ARROW },
    { 100.0f, &BUILDER_HAT },
    { 100.0f, &DOCTOR_MIRROR },
    { 100.0f, &CHRISTMAS_HAT },
    { 200.0f, &HIGH_HAT },
    { 250.0f, &BEANIE },
    { 250.0f, &STRAW_HAT },
    { 500.0f, &BRAIN },
    { 500.0f, &CAP }
};

const inline AttributeList<ColoredImageAttribute> FEMALE {
    { 10.0f, &CORRUPTED_CROWN },
    { 10.0f, &CROWN },
    { 30.0f, &ANTENNA },
    { 50.0f, &CHRISTMAS_HAT }
};
}