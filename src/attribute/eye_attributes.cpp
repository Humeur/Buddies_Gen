#include "attributes.hpp"

namespace buddy {
namespace eye {

const std::string ATTRIBUTE_NAME("Eyes");
const std::string COLOR_ATTRIBUTE_NAME("Eyes color");

HexColor EYE_GREEN("Green", 0x7EFC62);
HexColor EYE_BLUE("Blue", 0x5A9AFB);
HexColor EYE_BROWN("Brown", 0x674A35);
HexColor EYE_RED("Red", 0xB01A0C);
HexColor EYE_PURPLE("Purple", 0x913591);
HexColor EYE_WHITE("White", 0xFFFFFF);

const AttributeList<HexColor> NORMAL_EYE_COLORS {
    { 1.0, &EYE_RED },
    { 10.0, &EYE_GREEN },
    { 10.0, &EYE_BLUE },
    { 15.0, &EYE_BROWN },
    { 15.0, &EYE_WHITE }
};

const AttributeList<HexColor> ALIEN_EYE_COLORS {
    { 1.0, &EYE_PURPLE },
    { 1.0, &EYE_GREEN }
};

const AttributeList<HexColor> CYBER_EYE_COLORS {
    { 1.0, &EYE_RED },
    { 1.0, &EYE_PURPLE }
};

const AttributeList<HexColor> REPTILE_EYE_COLORS {
    { 1.0, &EYE_RED },
    { 1.0, &EYE_BLUE },
    { 3.0, &EYE_GREEN }
};

//TODO heterochroma
ColoredAttribute DEMON { "Demon", "assets/eye/demon.png" };
ColoredAttribute CRAZY { "Crazy", "assets/eye/crazy.png", &NORMAL_EYE_COLORS };
ColoredAttribute CRYING { "Crying", "assets/eye/crying.png" };
ColoredAttribute CYBORG { "Cyborg", "assets/eye/cyborg.png" };
ColoredAttribute NO_PUPIL { "No pupil", "assets/eye/no_pupil.png", &NORMAL_EYE_COLORS };
ColoredAttribute SQUINT { "Squint", "assets/eye/squint.png", &NORMAL_EYE_COLORS };
ColoredAttribute FUTURE_RAINBOW { "Future rainbow", "assets/eye/future_rainbow.png" };
ColoredAttribute ALIEN { "Alien", "assets/eye/alien.png", &ALIEN_EYE_COLORS };
ColoredAttribute CYBER { "Cyber", "assets/eye/cyber.png", &CYBER_EYE_COLORS };
ColoredAttribute SWIMMING_GOGGLES { "Swimming goggles", "assets/eye/swimming_goggles.png" };
ColoredAttribute TRIPLE_EYES { "Triple eyes", "assets/eye/triple_eyes.png", &NORMAL_EYE_COLORS };
ColoredAttribute WEIRD_GLASSES { "Weird glasses", "assets/eye/weird_glasses.png" };
ColoredAttribute SUNGLASSES { "Sunglasses", "assets/eye/sunglasses.png" };
ColoredAttribute ZORO { "Zoro", "assets/eye/zoro.png" };
ColoredAttribute REPTILE { "Reptile", "assets/eye/reptile.png", &REPTILE_EYE_COLORS };
ColoredAttribute LOOKING_RIGHT { "Looking right", "assets/eye/looking_right.png", &NORMAL_EYE_COLORS };
ColoredAttribute LOOKING_UP { "Looking up", "assets/eye/looking_up.png", &NORMAL_EYE_COLORS };
ColoredAttribute CLASSIC { "Classic", "assets/eye/classic.png", &NORMAL_EYE_COLORS };
ColoredAttribute BIG_SUNGLASSES { "Big sunglasses", "assets/eye/big_sunglasses.png" };
ColoredAttribute NERD_GLASSES { "Nerg glasses", "assets/eye/nerd_glasses.png" };
ColoredAttribute HEART_GLASSES { "Heart glasses", "assets/eye/heart_glasses.png" };
ColoredAttribute VILAIN { "Vilain", "assets/eye/vilain.png" };
ColoredAttribute LASER { "Laser", "assets/eye/laser.png" };
ColoredAttribute CUTE { "Cute", "assets/eye/cute.png" };

const AttributeList<ColoredAttribute> EYES {
    { 5.0, &DEMON },
    { 5.0, &VILAIN },
    { 5.0, &LASER },
    { 5.0, &TRIPLE_EYES },
    { 10.0, &SWIMMING_GOGGLES },
    { 10.0, &CRYING },
    { 10.0, &CYBORG },
    { 10.0, &NO_PUPIL },
    { 15.0, &FUTURE_RAINBOW },
    { 15.0, &ALIEN },
    { 15.0, &CYBER },
    { 15.0, &CRAZY },
    { 15.0, &SQUINT },
    { 20.0, &NERD_GLASSES },
    { 20.0, &HEART_GLASSES },
    { 20.0, &WEIRD_GLASSES },
    { 20.0, &LOOKING_UP },
    { 20.0, &LOOKING_RIGHT },
    { 20.0, &SUNGLASSES },
    { 20.0, &BIG_SUNGLASSES },
    { 20.0, &ZORO },
    { 20.0, &CLASSIC }
};

const AttributeList<ColoredAttribute> RARE_EYES {
    { 5.0, &DEMON },
    { 5.0, &VILAIN },
    { 5.0, &LASER },
    { 10.0, &CRYING },
    { 10.0, &CYBORG },
    { 10.0, &NO_PUPIL },
    { 10.0, &CUTE },
    { 15.0, &FUTURE_RAINBOW },
    { 15.0, &ALIEN },
    { 15.0, &CYBER },
    { 15.0, &CRAZY },
    { 15.0, &SQUINT }
};

}
}