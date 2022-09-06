#include "attribute.hpp"

namespace buddy::eye {

constexpr inline std::string_view ATTRIBUTE_NAME("Eyes");
constexpr inline std::string_view COLOR_ATTRIBUTE_NAME("Eyes color");

constexpr inline ColorAttribute EYE_GREEN("Green", 0x7EFC62FF);
constexpr inline ColorAttribute EYE_BLUE("Blue", 0x5A9AFBFF);
constexpr inline ColorAttribute EYE_BROWN("Brown", 0x674A35FF);
constexpr inline ColorAttribute EYE_RED("Red", 0xB01A0CFF);
constexpr inline ColorAttribute EYE_PURPLE("Purple", 0x913591FF);
constexpr inline ColorAttribute EYE_WHITE("White", 0xFFFFFFFF);

const inline AttributeList<ColorAttribute> NORMAL_EYE_COLORS {
    { 1.0f, &EYE_RED },
    { 10.0f, &EYE_GREEN },
    { 10.0f, &EYE_BLUE },
    { 15.0f, &EYE_BROWN },
    { 15.0f, &EYE_WHITE }
};

const inline AttributeList<ColorAttribute> ALIEN_EYE_COLORS {
    { 1.0f, &EYE_PURPLE },
    { 1.0f, &EYE_GREEN }
};

const inline AttributeList<ColorAttribute> CYBER_EYE_COLORS {
    { 1.0f, &EYE_RED },
    { 1.0f, &EYE_PURPLE }
};

const inline AttributeList<ColorAttribute> REPTILE_EYE_COLORS {
    { 1.0f, &EYE_RED },
    { 1.0f, &EYE_BLUE },
    { 3.0f, &EYE_GREEN }
};

const inline ColoredImageAttribute DEMON { "Demon", "assets/eye/demon.png" };
const inline ColoredImageAttribute CRYING { "Crying", "assets/eye/crying.png" };
const inline ColoredImageAttribute CYBORG { "Cyborg", "assets/eye/cyborg.png" };
const inline ColoredImageAttribute NO_PUPIL { "No pupil", "assets/eye/no_pupil.png", &NORMAL_EYE_COLORS };
const inline ColoredImageAttribute SQUINT { "Squint", "assets/eye/squint.png", &NORMAL_EYE_COLORS };
const inline ColoredImageAttribute FUTURE_RAINBOW { "Future rainbow", "assets/eye/future_rainbow.png" };
const inline ColoredImageAttribute ALIEN { "Alien", "assets/eye/alien.png", &ALIEN_EYE_COLORS };
const inline ColoredImageAttribute CYBER { "Cyber", "assets/eye/cyber.png", &CYBER_EYE_COLORS };
const inline ColoredImageAttribute SWIMMING_GOGGLES { "Swimming goggles", "assets/eye/swimming_goggles.png" };
const inline ColoredImageAttribute TRIPLE_EYES { "Triple eyes", "assets/eye/triple_eyes.png", &NORMAL_EYE_COLORS };
const inline ColoredImageAttribute WEIRD_GLASSES { "Weird glasses", "assets/eye/weird_glasses.png" };
const inline ColoredImageAttribute SUNGLASSES { "Sunglasses", "assets/eye/sunglasses.png" };
const inline ColoredImageAttribute ZORO { "Zoro", "assets/eye/zoro.png" };
const inline ColoredImageAttribute REPTILE { "Reptile", "assets/eye/reptile.png", &REPTILE_EYE_COLORS };
const inline ColoredImageAttribute LOOKING_RIGHT { "Looking right", "assets/eye/looking_right.png", &NORMAL_EYE_COLORS };
const inline ColoredImageAttribute LOOKING_UP { "Looking up", "assets/eye/looking_up.png", &NORMAL_EYE_COLORS };
const inline ColoredImageAttribute CLASSIC { "Classic", "assets/eye/classic.png", &NORMAL_EYE_COLORS };
const inline ColoredImageAttribute BIG_SUNGLASSES { "Big sunglasses", "assets/eye/big_sunglasses.png" };
const inline ColoredImageAttribute NERD_GLASSES { "Nerg glasses", "assets/eye/nerd_glasses.png" };
const inline ColoredImageAttribute HEART_GLASSES { "Heart glasses", "assets/eye/heart_glasses.png" };
const inline ColoredImageAttribute VILAIN { "Vilain", "assets/eye/vilain.png" };
const inline ColoredImageAttribute LASER { "Laser", "assets/eye/laser.png" };
const inline ColoredImageAttribute CUTE { "Cute", "assets/eye/cute.png" };
const inline ColoredImageAttribute CRAZY("Crazy", "assets/eye/crazy.png");

const inline AttributeList<ColoredImageAttribute> EYES {
    { 5.0f, &DEMON },
    { 5.0f, &VILAIN },
    { 5.0f, &LASER },
    { 5.0f, &TRIPLE_EYES },
    { 10.0f, &SWIMMING_GOGGLES },
    { 10.0f, &CRYING },
    { 10.0f, &CYBORG },
    { 10.0f, &NO_PUPIL },
    { 15.0f, &FUTURE_RAINBOW },
    { 15.0f, &ALIEN },
    { 15.0f, &CYBER },
    { 15.0f, &CRAZY },
    { 15.0f, &SQUINT },
    { 20.0f, &NERD_GLASSES },
    { 20.0f, &HEART_GLASSES },
    { 20.0f, &WEIRD_GLASSES },
    { 20.0f, &LOOKING_UP },
    { 20.0f, &LOOKING_RIGHT },
    { 20.0f, &SUNGLASSES },
    { 20.0f, &BIG_SUNGLASSES },
    { 20.0f, &ZORO },
    { 20.0f, &CLASSIC }
};

const inline AttributeList<ColoredImageAttribute> RARE_EYES {
    { 5.0f, &DEMON },
    { 5.0f, &VILAIN },
    { 5.0f, &LASER },
    { 10.0f, &CRYING },
    { 10.0f, &CYBORG },
    { 10.0f, &NO_PUPIL },
    { 10.0f, &CUTE },
    { 15.0f, &FUTURE_RAINBOW },
    { 15.0f, &ALIEN },
    { 15.0f, &CYBER },
    { 15.0f, &CRAZY },
    { 15.0f, &SQUINT }
};

}