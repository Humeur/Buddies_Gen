#include "attribute.hpp"

namespace buddy {
namespace skin {

constexpr std::string_view ATTRIBUTE_NAME("Skin color");

const Image BASE("assets/skin/base.png");
const Image SKIN("assets/skin/skin.png");
const inline ImageAttribute GHOST("Ghost", "assets/skin/ghost.png");

constexpr inline ColorAttribute SKIN_BLACK("Black", 0x000000FF);
constexpr inline ColorAttribute SKIN_WHITE("White", 0xFFFFFFFF);
constexpr inline ColorAttribute SKIN_GREEN("Green", 0xCAFFBFFF);
constexpr inline ColorAttribute SKIN_BLUE("Blue", 0xA0C4FFFF);
constexpr inline ColorAttribute SKIN_PURPLE("Purple", 0xBDB2FFFF);
constexpr inline ColorAttribute SKIN_PORCELAIN("Porcelain", 0xFFE0BDFF);
constexpr inline ColorAttribute SKIN_IVORY("Ivory", 0xFFDBACFF);
constexpr inline ColorAttribute SKIN_SAND("Sand", 0xFFCD94FF);
constexpr inline ColorAttribute SKIN_BEIGE("Beige", 0xF1C37DFF);
constexpr inline ColorAttribute SKIN_WARM_BEIGE("Warm Beige", 0xEAC086FF);
constexpr inline ColorAttribute SKIN_HONEY("Honey", 0xE0AD69FF);
constexpr inline ColorAttribute SKIN_GOLDEN("Golden", 0xC68642FF);
constexpr inline ColorAttribute SKIN_ALMOND("Almond", 0x765339FF);
constexpr inline ColorAttribute SKIN_CHESTNUT("Chestnut", 0x8d5524FF);
constexpr inline ColorAttribute SKIN_ESPRESSO("Espresso", 0x351606FF);

const inline AttributeList<ColorAttribute> SKINS {
    { 1.0, &SKIN_WHITE },
    { 1.0, &SKIN_BLACK },
    { 2.0, &SKIN_GREEN },
    { 3.5, &SKIN_BLUE },
    { 3.5, &SKIN_PURPLE },
    { 9.0, &SKIN_PORCELAIN },
    { 9.0, &SKIN_IVORY },
    { 9.0, &SKIN_SAND },
    { 9.0, &SKIN_BEIGE },
    { 9.0, &SKIN_WARM_BEIGE },
    { 9.0, &SKIN_HONEY },
    { 9.0, &SKIN_GOLDEN },
    { 9.0, &SKIN_ALMOND },
    { 9.0, &SKIN_CHESTNUT },
    { 9.0, &SKIN_ESPRESSO },
};

}
}