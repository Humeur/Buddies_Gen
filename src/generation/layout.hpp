#pragma once

#include <array>
#include <random>

namespace buddy {

enum class BuddyType : unsigned char {
    MALE,
    FEMALE,
    DINOSAUR,
    ELEPHANT,
    MONKEY,
    JAR
};

std::array<BuddyType, 10000> generateLayout();

}