#include "generation.hpp"

namespace buddy {

static void generateBackground(Buddy &buddy, random &rdm) {
    auto background = background::BACKGROUNDS(rdm);
    buddy.addAttribute(background::ATTRIBUTE_NAME, background->name);
    buddy.addLayer(background->image);
    buddy.addAttribute(type::ATTRIBUTE_NAME, type::ELEPHANT_ATTRIBUTE_VALUE);
    buddy.addLayer(special::ELEPHANT);
}

static void generateEyes(Buddy &buddy, random &rdm) {
    auto *eyes = eye::RARE_EYES(rdm);
    buddy.addAttribute(eye::ATTRIBUTE_NAME, eyes->name);
    if (eyes->colors != nullptr) {
        auto eyeColor = eyes->colors->operator()(rdm);
        buddy.addAttribute(eye::COLOR_ATTRIBUTE_NAME, eyeColor->name);
        buddy.addLayer(eyes->image, *eyeColor);
    } else {
        buddy.addLayer(eyes->image);
    }
}

Buddy generateElephant(random &rdm) {
    Buddy buddy;
    generateBackground(buddy, rdm);
    generateEyes(buddy, rdm);
    return buddy;
}

};