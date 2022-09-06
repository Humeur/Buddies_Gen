#include "generation.hpp"

namespace buddy {

static void generateBackground(Buddy &buddy, random &rdm) {
    auto background = background::BACKGROUNDS(rdm);
    buddy.addAttribute(background::ATTRIBUTE_NAME, background->name);
    buddy.addLayer(background->image);
    buddy.addAttribute(type::ATTRIBUTE_NAME, type::MONKEY_ATTRIBUTE_VALUE);
    buddy.addLayer(special::MONKEY);
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

static void generateTop(Buddy &buddy, random &rdm) {
    auto top = top::MALE(rdm);
    buddy.addAttribute(top::ATTRIBUTE_NAME, top->name);
    if (top->colors) {
        auto topColor = top->colors->operator()(rdm);
        buddy.addAttribute(top::COLOR_ATTRIBUTE_NAME, topColor->name);
        buddy.addLayer(top->image, *topColor);
    } else {
        buddy.addLayer(top->image);
    }
}

Buddy generateMonkey(random &rdm) {
    Buddy buddy;
    generateBackground(buddy, rdm);
    generateTop(buddy, rdm);
    generateEyes(buddy, rdm);
    return buddy;
}

}