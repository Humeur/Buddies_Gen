#include "generation.hpp"

namespace buddy {

BuddyGenerator::BuddyGenerator(unsigned seed) : rdm(seed), canvas("assets/canvas.png") {
}

BuddyGenerator::~BuddyGenerator() {
    this->canvas.save("out/buddies.png");
}

void BuddyGenerator::generateBuddy(unsigned id, BuddyType type) {
    Buddy buddy;
    bool running = true;
    BuddyGeneratorPFN generator = GENERATOR_FUNCTIONS[static_cast<unsigned char>(type)];
    while (running) {
        buddy = generator(this->rdm);
        if (this->buddies.emplace(buddy).second) {
            running = false;
        } else {
            this->fails++;
        }
    }

    buddy.save(id, this->canvas);
}

void BuddyGenerator::generateBuddies() {
    if (std::filesystem::exists("out/")) {
        std::filesystem::remove_all("out/");
    }

    std::array<BuddyType, 10000> layout = generateLayout();

    std::filesystem::create_directory("out");
    std::filesystem::create_directory("out/metadatas");
    std::filesystem::create_directory("out/images");

    for (int i = 0; i < 10000; i++) {
        generateBuddy(i, layout[i]);
    }
    std::cout << "fails: " << this->fails << std::endl;
}

};