#include "attributes.hpp"

namespace buddy {
namespace hair {

const std::string ATTRIBUTE_NAME("Hair");
const std::string COLOR_ATTRIBUTE_NAME("Hair color");

HexColor HAIR_BROWN("Brown", 0x422919);
HexColor HAIR_GINGER("Ginger", 0xab6422);
HexColor HAIR_BLOND("Blond", 0xbd8d5d);
HexColor HAIR_BLACK("Black", 0x141414);
HexColor HAIR_RED("Red", 0xde3835);
HexColor HAIR_GREEN("Green", 0x11c404);
HexColor HAIR_LIGHT_BLUE("Light blue", 0x00FFFF);
HexColor HAIR_PURPLE("Pink", 0xa657c7);

const AttributeList<HexColor> NORMAL_HAIR_COLORS {
    { 1.0, &HAIR_BLACK },
    { 1.0, &HAIR_GINGER },
    { 1.0, &HAIR_BLOND },
    { 1.0, &HAIR_BROWN }
};

const AttributeList<HexColor> SPECIAL_HAIR_COLORS {
    { 1.0, &HAIR_BLACK },
    { 1.0, &HAIR_GINGER },
    { 1.0, &HAIR_BLOND },
    { 1.0, &HAIR_BROWN },
    { 1.0, &HAIR_RED },
    { 1.0, &HAIR_GREEN }
};

const AttributeList<HexColor> CURLY_COLORS {
    { 1.0, &HAIR_BLACK },
    { 1.0, &HAIR_BROWN }
};

const AttributeList<HexColor> BOB_COLORS {
    { 1.0, &HAIR_PURPLE },
    { 2.5, &HAIR_BLACK },
    { 2.5, &HAIR_BROWN }
};

ColoredAttribute BALD { "Bald", "assets/hair/bald.png" };
ColoredAttribute CURLY { "Curly", "assets/hair/curly_hair.png", &CURLY_COLORS };
ColoredAttribute LONG { "Long", "assets/hair/long_hair.png", &NORMAL_HAIR_COLORS };
ColoredAttribute MEDIUM { "Medium", "assets/hair/medium_hair.png", &NORMAL_HAIR_COLORS };
ColoredAttribute MESSY { "Messy", "assets/hair/messy_hair.png", &NORMAL_HAIR_COLORS };
ColoredAttribute PONYTAIL { "Ponytail", "assets/hair/ponytail.png", &NORMAL_HAIR_COLORS };
ColoredAttribute SEMI { "Semi", "assets/hair/semi_hair.png", &SPECIAL_HAIR_COLORS };
ColoredAttribute SHORT { "Short", "assets/hair/short_hair.png", &NORMAL_HAIR_COLORS };
ColoredAttribute TWIN_BUNS { "Twin buns", "assets/hair/twin_buns.png", &NORMAL_HAIR_COLORS };
ColoredAttribute MERMAID { "Mermaid ", "assets/hair/mermaid.png", nullptr };
ColoredAttribute PIGTAILS { "Pigtails" , "assets/hair/pigtails.png", &NORMAL_HAIR_COLORS };
ColoredAttribute SPLIT { "Split", "assets/hair/split.png", &NORMAL_HAIR_COLORS };
ColoredAttribute BOB { "Bob", "assets/hair/bob.png", &BOB_COLORS };
ColoredAttribute BUBBLEGUM { "Bubblegum", "assets/hair/bubblegum.png", nullptr };

const AttributeList<ColoredAttribute> MALE {
    { 1.0, &BALD },
    { 1.0, &CURLY },
    { 1.0, &MESSY },
    { 1.0, &SEMI },
    { 1.0, &SHORT },
    { 1.0, &SPLIT }
};

const AttributeList<ColoredAttribute> FEMALE {
    { 1.0, &MERMAID },
    { 1.0, &BUBBLEGUM },
    { 25.0, &PONYTAIL },
    { 25.0, &TWIN_BUNS },
    { 25.0, &LONG },
    { 25.0, &MEDIUM },
    { 25.0, &BOB },
    { 25.0, &PIGTAILS }
};

}
}