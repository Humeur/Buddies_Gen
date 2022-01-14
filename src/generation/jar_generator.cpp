#include "generation.hpp"

namespace buddy {

Buddy JarBuddyGenerator::generateBuddy(random_type &random) {
    Buddy buddy;
    buddy.addAttribute(type::ATTRIBUTE_NAME, type::JAR_ATTRIBUTE_VALUE);
    buddy.addLayer(special::JARS[this->index++]);
    return buddy;
}

}
