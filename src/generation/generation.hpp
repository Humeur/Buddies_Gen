#pragma once

#include "../attribute/attributes.hpp"
#include <array>
#include "buddy.hpp"
#include <unordered_set>
#include <filesystem>
#include "layout.hpp"

namespace buddy {

using id_type = unsigned int;
using random = std::mt19937;
typedef Buddy (*BuddyGeneratorPFN) (random &);

Buddy generateMale(random &rdm);
Buddy generateFemale(random &rdm);
Buddy generateDinosaur(random &rdm);
Buddy generateElephant(random &rdm);
Buddy generateMonkey(random &rdm);
Buddy generateJar(random &rdm);

constexpr inline BuddyGeneratorPFN GENERATOR_FUNCTIONS[] {
    generateMale,
    generateFemale,
    generateDinosaur,
    generateElephant,
    generateMonkey,
    generateJar
};

class BuddyGenerator {
public:
    BuddyGenerator(unsigned seed);
    ~BuddyGenerator();
    void generateBuddies();
private:
    random rdm;
    Image canvas;
    std::unordered_set<Buddy> buddies;
    void generateBuddy(unsigned id, BuddyType type);
    size_t fails = 0;
};

};
