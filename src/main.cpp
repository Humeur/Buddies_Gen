#include <iostream>
#include "generation/generation.hpp"

int main() {
    buddy::BuddyGenerator generator(0xDEADCA);
    generator.generateBuddies();
}