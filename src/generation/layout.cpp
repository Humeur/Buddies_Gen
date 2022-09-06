#include "layout.hpp"

namespace buddy {

#define MALE_COUNT 6400
#define FEMALE_COUNT 2990
#define DINOSAUR_COUNT 300
#define MONKEY_COUNT 250
#define ELEPHANT_COUNT 50
#define JAR_COUNT 10
#define TOTAL_COUNT MALE_COUNT + FEMALE_COUNT + DINOSAUR_COUNT + MONKEY_COUNT + ELEPHANT_COUNT + JAR_COUNT

static_assert(TOTAL_COUNT == 10000);

#define POPULATE_ARRAY(count, value) for (unsigned i = 0; i < count; ++i, ++itr) *itr = value

std::array<BuddyType, 10000> generateLayout() {
    std::array<BuddyType, 10000> array;
    auto itr = array.begin();
    POPULATE_ARRAY(MALE_COUNT, BuddyType::MALE);
    POPULATE_ARRAY(FEMALE_COUNT, BuddyType::FEMALE);
    POPULATE_ARRAY(DINOSAUR_COUNT, BuddyType::DINOSAUR);
    POPULATE_ARRAY(MONKEY_COUNT, BuddyType::MONKEY);
    POPULATE_ARRAY(ELEPHANT_COUNT, BuddyType::ELEPHANT);
    POPULATE_ARRAY(JAR_COUNT, BuddyType::JAR);

    std::mt19937 random(1337);
    std::shuffle(array.begin(), array.end(), random);
    return array;
}
}