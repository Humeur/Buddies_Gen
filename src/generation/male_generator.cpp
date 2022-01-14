#include "generation.hpp"

namespace buddy {

void MaleBuddyGenerator::generateBackground(Buddy &buddy, random_type &random) {
    const Attribute *background = background::BACKGROUNDS.random(random);
    buddy.addLayer(background->image);
    buddy.addAttribute(background::ATTRIBUTE_NAME, background->name);
}

void MaleBuddyGenerator::generateSkin(Buddy &buddy, random_type &random) {
    if (random() % 50 == 0) {
        buddy.addAttribute(skin::ATTRIBUTE_NAME, skin::GHOST_ATTRIBUTE_VALUE);
        buddy.addLayer(skin::GHOST);
    } else {
        auto skin = skin::SKINS.random(random);
        buddy.addAttribute(skin::ATTRIBUTE_NAME, skin->name);
        buddy.addLayer(skin::SKIN, *skin);
        buddy.addLayer(skin::BASE);
    }
}

void MaleBuddyGenerator::generateMouth(Buddy &buddy, random_type &random) {
    bool beard = random() & 1;
    if (beard) {
        auto beard = mouth::FACIAL_HAIR.random(random);
        if (!buddy.getHairColor()) {
            buddy.setHairColor(*hair::NORMAL_HAIR_COLORS.random(random));
            buddy.addAttribute(hair::COLOR_ATTRIBUTE_NAME, buddy.getHairColor()->name);
        }
        buddy.addAttribute(mouth::FACIAL_HAIR_NAME, beard->name);
        buddy.addLayer(beard->image, *buddy.getHairColor());
    } else {
        auto mouth = mouth::MALE.random(random);
        buddy.addAttribute(mouth::ATTRIBUTE_NAME, mouth->name);
        buddy.addLayer(mouth->image);
    }
}

void MaleBuddyGenerator::generateHair(Buddy &buddy, random_type &random) {
    bool hair = random() & 1;
    if (hair) {
        ColoredAttribute *hair = hair::MALE.random(random);
        if (hair->colors != nullptr) {
            HexColor *hairColor = hair->colors->random(random);
            buddy.setHairColor(*hairColor);
            buddy.addAttribute(hair::ATTRIBUTE_NAME, hair->name);
            buddy.addAttribute(hair::COLOR_ATTRIBUTE_NAME, hairColor->name);
            buddy.addLayer(hair->image, *hairColor);
        } else {
            buddy.addAttribute(hair::ATTRIBUTE_NAME, hair->name);
            buddy.addLayer(hair->image);
        }
    } else {
        auto *top = top::MALE.random(random);
        buddy.addAttribute(top::ATTRIBUTE_NAME, top->name);
        if (top->colors) {
            auto topColor = top->colors->random(random);
            buddy.addAttribute(top::COLOR_ATTRIBUTE_NAME, topColor->name);
            buddy.addLayer(top->image, *topColor);
        } else {
            buddy.addLayer(top->image);
        }
    }
}

void MaleBuddyGenerator::generateEyes(Buddy &buddy, random_type &random) {
    auto *eyes = eye::EYES.random(random);
    buddy.addAttribute(eye::ATTRIBUTE_NAME, eyes->name);
    if (eyes->colors != nullptr) {
        auto eyeColor = eyes->colors->random(random);
        buddy.addAttribute(eye::COLOR_ATTRIBUTE_NAME, eyeColor->name);
        buddy.addLayer(eyes->image, *eyeColor);
    } else {
        buddy.addLayer(eyes->image);
    }
}

Buddy MaleBuddyGenerator::generateBuddy(random_type &random) {
    Buddy buddy;
    buddy.addAttribute(type::ATTRIBUTE_NAME, type::HUMAN_ATTRIBUTE_VALUE);
    generateBackground(buddy, random);
    generateSkin(buddy, random);
    generateHair(buddy, random);
    generateMouth(buddy, random);
    generateEyes(buddy, random);
    return buddy;
}

}
