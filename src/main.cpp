#include <iostream>
#include "generation/generation.hpp"

int main() {
    try {
        buddy::BuddyGenerator generator(0xDEADCA);
        generator.generateBuddies();
    } catch (const std::exception &e) {
        std::cerr << "A fatal error has been caught: " << e.what() << std::endl;
    }
    
}