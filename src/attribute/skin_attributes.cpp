#include "attributes.hpp"

namespace buddy {
namespace skin {

const std::string ATTRIBUTE_NAME("Skin color");
const std::string GHOST_ATTRIBUTE_VALUE("Ghost");

const Image BASE("assets/skin/base.png");
const Image SKIN("assets/skin/skin.png");
const Image GHOST("assets/skin/ghost.png");

HexColor SKIN_BLACK("Black", 0x000000);
HexColor SKIN_WHITE("White", 0xFFFFFF);
HexColor SKIN_GREEN("Green", 0xCAFFBF);
HexColor SKIN_BLUE("Blue", 0xA0C4FF);
HexColor SKIN_PURPLE("Purple", 0xBDB2FF);
HexColor SKIN_PORCELAIN("Porcelain", 0xFFE0BD);
HexColor SKIN_IVORY("Ivory", 0xFFDBAC);
HexColor SKIN_SAND("Sand", 0xFFCD94);
HexColor SKIN_BEIGE("Beige", 0xF1C37D);
HexColor SKIN_WARM_BEIGE("Warm Beige", 0xEAC086);
HexColor SKIN_HONEY("Honey", 0xE0AD69);
HexColor SKIN_GOLDEN("Golden", 0xC68642);
HexColor SKIN_ALMOND("Almond", 0x765339);
HexColor SKIN_CHESTNUT("Chestnut", 0x8d5524);
HexColor SKIN_ESPRESSO("Espresso", 0x351606);

const AttributeList<HexColor> SKINS {
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