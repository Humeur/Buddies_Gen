#include "attributes.hpp"

namespace buddy {
namespace top {

const std::string ATTRIBUTE_NAME("Top");
const std::string COLOR_ATTRIBUTE_NAME("Top color");

HexColor TOP_RED("Red", 0xB71C1C);
HexColor TOP_GREEN("Green", 0x1A6E1E);
HexColor TOP_BLUE("Blue", 0x01589B);
HexColor TOP_GREY("Grey", 0xB0B0B0);
HexColor TOP_PURPLE("Purple", 0x7002CF);

const AttributeList<HexColor> CAP_COLORS {
    { 1.0, &TOP_RED },
    { 1.0, &TOP_GREEN },
    { 1.0, &TOP_BLUE }
};

const AttributeList<HexColor> BEANIE_COLORS {
    { 1.0, &TOP_RED },
    { 1.0, &TOP_GREEN },
    { 1.0, &TOP_BLUE },
    { 1.0, &TOP_GREY }
};

const AttributeList<HexColor> HIGH_HAT_COLORS {
    { 1.0, &TOP_RED },
    { 1.0, &TOP_PURPLE }
};



ColoredAttribute CORRUPTED_CROWN { "Corrupted crown", "assets/top/corrupted_crown.png" };
ColoredAttribute CROWN { "Crown", "assets/top/crown.png" };
ColoredAttribute ANTENNA { "Antenna", "assets/top/antenna.png" };
ColoredAttribute DEMON_HORN { "Demon horn", "assets/top/demon_horn.png" };
ColoredAttribute ANGEL_RING { "Angel ring", "assets/top/angel_ring.png" };
ColoredAttribute ARROW { "Arrow", "assets/top/arrow.png" };
ColoredAttribute BUILDER_HAT { "Builder hat", "assets/top/builder_hat.png" };
ColoredAttribute DOCTOR_MIRROR { "Doctor mirror", "assets/top/doctor_mirror.png" };
ColoredAttribute HIGH_HAT { "High hat", "assets/top/high_hat.png", &HIGH_HAT_COLORS };
ColoredAttribute BRAIN { "Brain", "assets/top/brain.png" };
ColoredAttribute CAP { "Cap", "assets/top/cap.png", &CAP_COLORS };
ColoredAttribute BEANIE { "Beanie", "assets/top/beanie.png", &BEANIE_COLORS };
ColoredAttribute STRAW_HAT { "Straw hat", "assets/top/straw_hat.png" };
ColoredAttribute CHRISTMAS_HAT { "Christmas hat", "assets/top/christmas_hat.png" };

const AttributeList<ColoredAttribute> MALE {
    { 10.0, &CORRUPTED_CROWN },
    { 10.0, &CROWN },
    { 90.0, &ANTENNA },
    { 90.0, &DEMON_HORN },
    { 100.0, &ANGEL_RING },
    { 100.0, &ARROW },
    { 100.0, &BUILDER_HAT },
    { 100.0, &DOCTOR_MIRROR },
    { 100.0, &CHRISTMAS_HAT },
    { 200.0, &HIGH_HAT },
    { 250.0, &BEANIE },
    { 250.0, &STRAW_HAT },
    { 500.0, &BRAIN },
    { 500.0, &CAP }
};

const AttributeList<ColoredAttribute> FEMALE {
    { 10.0, &CORRUPTED_CROWN },
    { 10.0, &CROWN },
    { 30.0, &ANTENNA },
    { 50.0, &CHRISTMAS_HAT }
};

}
}      