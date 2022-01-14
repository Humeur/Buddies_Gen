#include "generation.hpp"

namespace buddy {

void MonkeyBuddyGenerator::generateBackground(Buddy &buddy, random_type &random) {
    auto background = background::BACKGROUNDS.random(random);
    buddy.addAttribute(background::ATTRIBUTE_NAME, background->name);
    buddy.addLayer(background->image);
    buddy.addAttribute(type::ATTRIBUTE_NAME, type::MONKEY_ATTRIBUTE_VALUE);
    buddy.addLayer(special::MONKEY);
}

void MonkeyBuddyGenerator::generateEyes(Buddy &buddy, random_type &random) {
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

void MonkeyBuddyGenerator::generateTop(Buddy &buddy, random_type &random) {
    auto top = top::MALE.random(random);
    buddy.addAttribute(top::ATTRIBUTE_NAME, top->name);
    if (top->colors) {
        auto topColor = top->colors->random(random);
        buddy.addAttribute(top::COLOR_ATTRIBUTE_NAME, topColor->name);
        buddy.addLayer(top->image, *topColor);
    } else {
        buddy.addLayer(top->image);
    }
}

Buddy MonkeyBuddyGenerator::generateBuddy(random_type &random) {
    Buddy buddy;
    generateBackground(buddy, random);
    generateTop(buddy, random);
    generateEyes(buddy, random);
    return buddy;
}

}