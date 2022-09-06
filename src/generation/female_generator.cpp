#include "generation.hpp"

namespace buddy {

static void generateBackground(Buddy &buddy, random &rdm) {
    const auto *background = background::BACKGROUNDS(rdm);
    buddy.addLayer(background->image);
    buddy.addAttribute(background::ATTRIBUTE_NAME, background->name);
}

static void generateSkin(Buddy &buddy, random &rdm) {
    if (rdm() % 50 == 0) {
        buddy.addAttribute(skin::ATTRIBUTE_NAME, skin::GHOST.name);
        buddy.addLayer(skin::GHOST.image);
    } else {
        auto skin = skin::SKINS(rdm);
        buddy.addAttribute(skin::ATTRIBUTE_NAME, skin->name);
        buddy.addLayer(skin::SKIN, *skin);
        buddy.addLayer(skin::BASE);
    }
}

static void generateMouth(Buddy &buddy, random &rdm) {
    auto mouth = mouth::FEMALE(rdm);
    buddy.addAttribute(mouth::ATTRIBUTE_NAME, mouth->name);
    buddy.addLayer(mouth->image);
}

static void generateHair(Buddy &buddy, random &rdm) {
    bool hair = true;
    if (hair) {
        const auto *hair = hair::FEMALE(rdm);
        if (hair->colors != nullptr) {
            const auto *hairColor = hair->colors->operator()(rdm);
            buddy.setHairColor(*hairColor);
            buddy.addAttribute(hair::ATTRIBUTE_NAME, hair->name);
            buddy.addAttribute(hair::COLOR_ATTRIBUTE_NAME, hairColor->name);
            buddy.addLayer(hair->image, *hairColor);
        } else {
            buddy.addAttribute(hair::ATTRIBUTE_NAME, hair->name);
            buddy.addLayer(hair->image);
        }
    } else {
        auto *top = top::FEMALE(rdm);
        buddy.addAttribute(top::ATTRIBUTE_NAME, top->name);
        if (top->colors) {
            auto topColor = top->colors->operator()(rdm);
            buddy.addAttribute(top::COLOR_ATTRIBUTE_NAME, topColor->name);
            buddy.addLayer(top->image, *topColor);
        } else {
            buddy.addLayer(top->image);
        }
    }
}

static void generateEyes(Buddy &buddy, random &rdm) {
    auto *eyes = eye::EYES(rdm);
    buddy.addAttribute(eye::ATTRIBUTE_NAME, eyes->name);
    if (eyes->colors != nullptr) {
        auto eyeColor = eyes->colors->operator()(rdm);
        buddy.addAttribute(eye::COLOR_ATTRIBUTE_NAME, eyeColor->name);
        buddy.addLayer(eyes->image, *eyeColor);
    } else {
        buddy.addLayer(eyes->image);
    }
}

Buddy generateFemale(random &rdm) {
    Buddy buddy;
    buddy.addAttribute(type::ATTRIBUTE_NAME, type::HUMAN_ATTRIBUTE_VALUE);
    generateBackground(buddy, rdm);
    generateSkin(buddy, rdm);
    generateHair(buddy, rdm);
    generateMouth(buddy, rdm);
    generateEyes(buddy, rdm);
    return buddy;
}

}
