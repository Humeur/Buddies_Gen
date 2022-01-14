#pragma once

#include "../attribute/attributes.hpp"
#include <array>
#include "buddy.hpp"
#include <unordered_set>
#include <filesystem>

namespace buddy {

using id_type = unsigned int;
using random_type = std::mt19937;

class IBuddyGenerator {
    public:
        virtual Buddy generateBuddy(random_type &random) = 0;
};

class FemaleBuddyGenerator : public IBuddyGenerator {
    private:
        void generateBackground(Buddy &buddy, random_type &random);
        void generateHair(Buddy &buddy, random_type &random);
        void generateEyes(Buddy &buddy, random_type &random);
        void generateSkin(Buddy &buddy, random_type &random);
        void generateMouth(Buddy &buddy, random_type &random);
    public:
        Buddy generateBuddy(random_type &random) override;
};

class MaleBuddyGenerator : public IBuddyGenerator {
    private:
        void generateBackground(Buddy &buddy, random_type &random);
        void generateHair(Buddy &buddy, random_type &random);
        void generateEyes(Buddy &buddy, random_type &random);
        void generateSkin(Buddy &buddy, random_type &random);
        void generateMouth(Buddy &buddy, random_type &random);
    public:
        Buddy generateBuddy(random_type &random) override;
};

class JarBuddyGenerator : public IBuddyGenerator {
    private:
        size_t index = 0;
    public:
        Buddy generateBuddy(random_type &random) override;
};

class ElephantBuddyGenerator : public IBuddyGenerator {
    private:
        void generateBackground(Buddy &buddy, random_type &random);
        void generateEyes(Buddy &buddy, random_type &random);
    public:
        Buddy generateBuddy(random_type &random) override;
};

class MonkeyBuddyGenerator : public IBuddyGenerator {
    private:
        void generateBackground(Buddy &buddy, random_type &random);
        void generateEyes(Buddy &buddy, random_type &random);
        void generateTop(Buddy &buddy, random_type &random);
    public:
        Buddy generateBuddy(random_type &random) override;
};

class DinosaurBuddyGenerator : public IBuddyGenerator {
    private:
        void generateBackground(Buddy &buddy, random_type &random);
        void generateEyes(Buddy &buddy, random_type &random);
        void generateSkin(Buddy &buddy, random_type &random);
    public:
        Buddy generateBuddy(random_type &random) override;
};

class BuddyGenerator {
    public:
        using seed_type = unsigned int;
    private:
        IBuddyGenerator *maleGenerator = new MaleBuddyGenerator();
        IBuddyGenerator *femaleGenerator = new FemaleBuddyGenerator();
        IBuddyGenerator *dinosaurGenerator = new DinosaurBuddyGenerator();
        IBuddyGenerator *monkeyGenerator = new MonkeyBuddyGenerator();
        IBuddyGenerator *elephantGenerator = new ElephantBuddyGenerator();
        //static const JarBuddyGenerator jarGenerator;

        AttributeList<IBuddyGenerator> generators {
            { 50.0, elephantGenerator },
            { 250.0, monkeyGenerator },
            { 300.0, dinosaurGenerator },
            { 3000.0, femaleGenerator },
            { 6400.0, maleGenerator }
        };
        random_type random;
        Image canvas;
        std::unordered_set<Buddy> buddies;
        void generateBuddy(const int &id);
        size_t fails = 0;
    public:
        BuddyGenerator(seed_type &&seed);
        ~BuddyGenerator();
        void generateBuddies();

};

};
