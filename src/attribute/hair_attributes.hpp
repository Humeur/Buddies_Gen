#include "attribute.hpp"

namespace buddy::hair {

constexpr inline std::string_view ATTRIBUTE_NAME("Hair");
constexpr inline std::string_view COLOR_ATTRIBUTE_NAME("Hair color");

constexpr inline ColorAttribute HAIR_BROWN("Brown", 0x422919FF);
constexpr inline ColorAttribute HAIR_GINGER("Ginger", 0xab6422FF);
constexpr inline ColorAttribute HAIR_BLOND("Blond", 0xbd8d5dFF);
constexpr inline ColorAttribute HAIR_BLACK("Black", 0x141414FF);
constexpr inline ColorAttribute HAIR_RED("Red", 0xde3835FF);
constexpr inline ColorAttribute HAIR_GREEN("Green", 0x11c404FF);
constexpr inline ColorAttribute HAIR_LIGHT_BLUE("Light blue", 0x00FFFFFF);
constexpr inline ColorAttribute HAIR_PURPLE("Pink", 0xa657c7FF);

const inline AttributeList<ColorAttribute> NORMAL_HAIR_COLORS {
    { 1.0, &HAIR_BLACK },
    { 1.0, &HAIR_GINGER },
    { 1.0, &HAIR_BLOND },
    { 1.0, &HAIR_BROWN }
};

const inline AttributeList<ColorAttribute> SPECIAL_HAIR_COLORS {
    { 1.0, &HAIR_BLACK },
    { 1.0, &HAIR_GINGER },
    { 1.0, &HAIR_BLOND },
    { 1.0, &HAIR_BROWN },
    { 1.0, &HAIR_RED },
    { 1.0, &HAIR_GREEN }
};

const inline AttributeList<ColorAttribute> CURLY_COLORS {
    { 1.0, &HAIR_BLACK },
    { 1.0, &HAIR_BROWN }
};

const inline AttributeList<ColorAttribute> BOB_COLORS {
    { 1.0, &HAIR_PURPLE },
    { 2.5, &HAIR_BLACK },
    { 2.5, &HAIR_BROWN }
};

const inline ColoredImageAttribute BALD { "Bald", "assets/hair/bald.png" };
const inline ColoredImageAttribute  CURLY { "Curly", "assets/hair/curly_hair.png", &CURLY_COLORS };
const inline ColoredImageAttribute  LONG { "Long", "assets/hair/long_hair.png", &NORMAL_HAIR_COLORS };
const inline ColoredImageAttribute  MEDIUM { "Medium", "assets/hair/medium_hair.png", &NORMAL_HAIR_COLORS };
const inline ColoredImageAttribute  MESSY { "Messy", "assets/hair/messy_hair.png", &NORMAL_HAIR_COLORS };
const inline ColoredImageAttribute  PONYTAIL { "Ponytail", "assets/hair/ponytail.png", &NORMAL_HAIR_COLORS };
const inline ColoredImageAttribute  SEMI { "Semi", "assets/hair/semi_hair.png", &SPECIAL_HAIR_COLORS };
const inline ColoredImageAttribute  SHORT { "Short", "assets/hair/short_hair.png", &NORMAL_HAIR_COLORS };
const inline ColoredImageAttribute  TWIN_BUNS { "Twin buns", "assets/hair/twin_buns.png", &NORMAL_HAIR_COLORS };
const inline ColoredImageAttribute  MERMAID { "Mermaid ", "assets/hair/mermaid.png", nullptr };
const inline ColoredImageAttribute  PIGTAILS { "Pigtails" , "assets/hair/pigtails.png", &NORMAL_HAIR_COLORS };
const inline ColoredImageAttribute  SPLIT { "Split", "assets/hair/split.png", &NORMAL_HAIR_COLORS };
const inline ColoredImageAttribute  BOB { "Bob", "assets/hair/bob.png", &BOB_COLORS };
const inline ColoredImageAttribute  BUBBLEGUM { "Bubblegum", "assets/hair/bubblegum.png", nullptr };

const AttributeList<ColoredImageAttribute> MALE {
    { 1.0, &BALD },
    { 1.0, &CURLY },
    { 1.0, &MESSY },
    { 1.0, &SEMI },
    { 1.0, &SHORT },
    { 1.0, &SPLIT }
};

const AttributeList<ColoredImageAttribute> FEMALE {
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