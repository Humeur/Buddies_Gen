#include "attributes.hpp"

namespace buddy {
namespace background {

const std::string ATTRIBUTE_NAME("Background");

Attribute BACKGROUND_FIRE { "Fire", "assets/background/fire.png" };
Attribute BACKGROUND_GREEN_SPACE { "Green space", "assets/background/green_space.png" };
Attribute BACKGROUND_NATURE { "Nature", "assets/background/nature.png" };
Attribute BACKGROUND_GREEN { "Green", "assets/background/green.png" };
Attribute BACKGROUND_LIGHT_BLUE { "Light blue", "assets/background/light_blue.png" };
Attribute BACKGROUND_LIGHT_GREEN { "Light green", "assets/background/light_green.png" };
Attribute BACKGROUND_LIGHT_PINK { "Light pink", "assets/background/light_pink.png" };
Attribute BACKGROUND_PASTEL_BLUE { "Pastel blue", "assets/background/pastel_blue.png" };
Attribute BACKGROUND_PASTEL_ORANGE { "Pastel orange", "assets/background/pastel_orange.png" };
Attribute BACKGROUND_PURPLE { "Purple", "assets/background/purple.png" };
Attribute BACKGROUND_WHITE_PINK { "White pink", "assets/background/white_pink.png" };
Attribute BACKGROUND_CLOUD { "Cloud", "assets/background/cloud.png" };

const AttributeList<Attribute> BACKGROUNDS {
    { 2.0, &BACKGROUND_FIRE },
    { 2.0, &BACKGROUND_GREEN_SPACE },
    { 2.0, &BACKGROUND_NATURE },
    { 2.0, &BACKGROUND_CLOUD },
    { 9.5, &BACKGROUND_GREEN },
    { 9.5, &BACKGROUND_LIGHT_BLUE },
    { 9.5, &BACKGROUND_LIGHT_GREEN },
    { 9.5, &BACKGROUND_LIGHT_PINK },
    { 9.5, &BACKGROUND_PASTEL_BLUE },
    { 9.5, &BACKGROUND_PASTEL_ORANGE },
    { 9.5, &BACKGROUND_PURPLE },
    { 9.5, &BACKGROUND_WHITE_PINK }
};

}
}