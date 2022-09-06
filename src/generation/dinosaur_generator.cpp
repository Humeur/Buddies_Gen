#include "generation.hpp"

namespace buddy {

static void generateBackground(Buddy &buddy, random &rdm) {
    auto background = background::BACKGROUNDS(rdm);
    buddy.addAttribute(background::ATTRIBUTE_NAME, background->name);
    buddy.addLayer(background->image);
}

static void generateSkin(Buddy &buddy, random &rdm) {
    auto skin = skin::SKINS(rdm);
    buddy.addAttribute(skin::ATTRIBUTE_NAME, skin->name);
    buddy.addLayer(skin::SKIN, *skin);
    buddy.addAttribute(type::ATTRIBUTE_NAME, type::DINOSAUR_ATTRIBUTE_VALUE);
    buddy.addLayer(special::DINOSAUR);
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

Buddy generateDinosaur(random &rdm) {
    Buddy buddy;
    generateBackground(buddy, rdm);
    generateSkin(buddy, rdm);
    generateEyes(buddy, rdm);
    return buddy;
}

};