#include "generation.hpp"

namespace buddy {

void ElephantBuddyGenerator::generateBackground(Buddy &buddy, random_type &random) {
    auto background = background::BACKGROUNDS.random(random);
    buddy.addAttribute(background::ATTRIBUTE_NAME, background->name);
    buddy.addLayer(background->image);
    buddy.addAttribute(type::ATTRIBUTE_NAME, type::ELEPHANT_ATTRIBUTE_VALUE);
    buddy.addLayer(special::ELEPHANT);
}

void ElephantBuddyGenerator::generateEyes(Buddy &buddy, random_type &random) {
    auto *eyes = eye::RARE_EYES.random(random);
    buddy.addAttribute(eye::ATTRIBUTE_NAME, eyes->name);
    if (eyes->colors != nullptr) {
        auto eyeColor = eyes->colors->random(random);
        buddy.addAttribute(eye::COLOR_ATTRIBUTE_NAME, eyeColor->name);
        buddy.addLayer(eyes->image, *eyeColor);
    } else {
        buddy.addLayer(eyes->image);
    }
}

Buddy ElephantBuddyGenerator::generateBuddy(random_type &random) {
    Buddy buddy;
    generateBackground(buddy, random);
    generateEyes(buddy, random);
    return buddy;
}

};