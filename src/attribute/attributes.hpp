#pragma once
#include "attribute_list.hpp"

namespace buddy {
    extern Image EMPTY;
    
    namespace skin {
        extern const Image BASE, SKIN, GHOST;
        extern const std::string ATTRIBUTE_NAME;
        extern const AttributeList<HexColor> SKINS;
        extern const std::string GHOST_ATTRIBUTE_VALUE;
    }

    namespace eye {
        extern const std::string ATTRIBUTE_NAME, COLOR_ATTRIBUTE_NAME;
        extern const AttributeList<ColoredAttribute> EYES, RARE_EYES;
    }

    namespace background {
        extern const std::string ATTRIBUTE_NAME;
        extern const AttributeList<Attribute> BACKGROUNDS;
    }
    
    namespace top {
        extern const std::string ATTRIBUTE_NAME, COLOR_ATTRIBUTE_NAME;
        extern const AttributeList<ColoredAttribute> MALE, FEMALE;
    }
    
    namespace hair {
        extern const std::string ATTRIBUTE_NAME;
        extern const std::string COLOR_ATTRIBUTE_NAME;
        extern const AttributeList<ColoredAttribute> MALE, FEMALE;
        extern const AttributeList<HexColor> NORMAL_HAIR_COLORS;
    }

    namespace mouth {
        extern const std::string ATTRIBUTE_NAME;
        extern const std::string FACIAL_HAIR_NAME;
        extern const AttributeList<Attribute> MALE, FEMALE, FACIAL_HAIR;
    }

    namespace special {
        extern const Image MONKEY, ELEPHANT, DINOSAUR;
        extern const Image JARS[10];
    }
    
    namespace type {
        extern const std::string ATTRIBUTE_NAME;
        extern const std::string MONKEY_ATTRIBUTE_VALUE;
        extern const std::string ELEPHANT_ATTRIBUTE_VALUE;
        extern const std::string JAR_ATTRIBUTE_VALUE;
        extern const std::string DINOSAUR_ATTRIBUTE_VALUE;
        extern const std::string HUMAN_ATTRIBUTE_VALUE;
    }
}