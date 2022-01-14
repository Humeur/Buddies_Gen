#include "generation.hpp"

namespace buddy {

BuddyGenerator::BuddyGenerator(seed_type &&seed) : random(std::move(seed)), canvas("assets/canvas.png") {
}

BuddyGenerator::~BuddyGenerator() {
    this->canvas.save("buddies.png");
    delete this->dinosaurGenerator;
    delete this->elephantGenerator;
    delete this->maleGenerator;
    delete this->femaleGenerator;
    delete this->monkeyGenerator;
}

void BuddyGenerator::generateBuddy(const int &id) {
    auto generator = this->generators.random(this->random);
    Buddy buddy;
    bool running = true;
    while (running) {
        buddy = generator->generateBuddy(this->random);
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

    std::filesystem::create_directory("out");
    std::filesystem::create_directory("out/metadatas");
    std::filesystem::create_directory("out/images");

    for (int i = 0; i < 10000; i++) {
        generateBuddy(i);
    }
    std::cout << "fails: " << this->fails << std::endl;
}

};