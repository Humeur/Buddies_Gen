#include "generation.hpp"

namespace buddy {

static size_t index = 0;

Buddy generateJar(random &rdm) {
    Buddy buddy;
    buddy.addAttribute(type::ATTRIBUTE_NAME, type::JAR_ATTRIBUTE_VALUE);
    auto color = special::JARS[index].getColorAt(10, 10);
    buddy.addLayer(special::JARS[index++]);
    return buddy;
}

}
