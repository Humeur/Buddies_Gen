#include "generation.hpp"

namespace buddy {

void DinosaurBuddyGenerator::generateBackground(Buddy &buddy, random_type &random) {
    auto background = background::BACKGROUNDS.random(random);
    buddy.addAttribute(background::ATTRIBUTE_NAME, background->name);
    buddy.addLayer(background->image);
}

void DinosaurBuddyGenerator::generateSkin(Buddy &buddy, random_type &random) {
    auto skin = skin::SKINS.random(random);
    buddy.addAttribute(skin::ATTRIBUTE_NAME, skin->name);
    buddy.addLayer(skin::SKIN, *skin);
    buddy.addAttribute(type::ATTRIBUTE_NAME, type::DINOSAUR_ATTRIBUTE_VALUE);
    buddy.addLayer(special::DINOSAUR);
}

void DinosaurBuddyGenerator::generateEyes(Buddy &buddy, random_type &random) {
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

Buddy DinosaurBuddyGenerator::generateBuddy(random_type &random) {
    Buddy buddy;
    generateBackground(buddy, random);
    generateSkin(buddy, random);
    generateEyes(buddy, random);
    return buddy;
}

};