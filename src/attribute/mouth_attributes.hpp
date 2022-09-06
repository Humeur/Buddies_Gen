#include "attribute.hpp"

namespace buddy::mouth {

constexpr inline std::string_view ATTRIBUTE_NAME("Mouth");
constexpr inline std::string_view FACIAL_HAIR_NAME("Facial hair");

const inline ImageAttribute NO_MOUTH("No mouth", "assets/mouth/no_mouth.png");
const inline ImageAttribute CLOWN_MEAN("Clown mean", "assets/mouth/clown_mean.png");
const inline ImageAttribute CLOWN_SAD("Clown sad", "assets/mouth/clown_sad.png");
const inline ImageAttribute CLOWN_SMILE("Clown smile", "assets/mouth/clown_smile.png");
const inline ImageAttribute CREEPY("Creepy", "assets/mouth/creepy.png");
const inline ImageAttribute PACIFIER("Pacifier", "assets/mouth/pacifier.png");
const inline ImageAttribute COVID_MASK("Covid mask", "assets/mouth/covid_mask.png");
const inline ImageAttribute MEAN("Mean", "assets/mouth/mean.png");
const inline ImageAttribute PIPE("Pipe", "assets/mouth/pipe.png");
const inline ImageAttribute CIGARETTE("Cigarette ", "assets/mouth/cigarette.png");
const inline ImageAttribute NEUTRAL("Neutral", "assets/mouth/neutral.png");
const inline ImageAttribute SAD("Sad", "assets/mouth/sad.png");
const inline ImageAttribute SMILE("Smile", "assets/mouth/smile.png");
const inline ImageAttribute TURTLENECK("Turtleneck", "assets/mouth/turtleneck.png");
const inline ImageAttribute CUTE("Cute", "assets/mouth/cute.png");
const inline ImageAttribute RUNNY_NOSE("Runny nose", "assets/mouth/runny_nose.png");
const inline ImageAttribute BUBBLEGUM("Bubblegum", "assets/mouth/bubblegum.png");

const inline ImageAttribute BEARD { "Beard", "assets/mouth/beard.png" };
const inline ImageAttribute BEARD_SMILE { "Beard smile", "assets/mouth/beard_smile.png" };
const inline ImageAttribute LONG_BEARD { "Long beard", "assets/mouth/long_beard.png" };
const inline ImageAttribute LONG_BEARD_SMILE { "Long beard smile", "assets/mouth/long_beard_smile.png" };
const inline ImageAttribute MUSTACHE { "Mustache", "assets/mouth/mustache.png" };

const inline AttributeList<ImageAttribute> MALE {
    { 5.0f, &NO_MOUTH },
    { 10.f, &TURTLENECK },
    { 20.f, &CLOWN_MEAN },
    { 20.f, &CLOWN_SAD },
    { 20.0f, &CLOWN_SMILE },
    { 20.0f, &CREEPY },
    { 20.0f, &PACIFIER },
    { 25.0f, &BUBBLEGUM },
    { 30.0f, &COVID_MASK },
    { 50.0f, &MEAN },
    { 50.0f, &PIPE },
    { 50.0f, &RUNNY_NOSE },
    { 75.0f, &CIGARETTE },
    { 100.0f, &NEUTRAL },
    { 100.0f, &SAD },
    { 100.0f, &SMILE }
};

const inline AttributeList<ImageAttribute> FACIAL_HAIR {
    { 1.0f, &BEARD },
    { 1.0f, &LONG_BEARD },
    { 1.0f, &BEARD_SMILE },
    { 1.0f, &LONG_BEARD_SMILE },
    { 1.0f, &MUSTACHE }
};

const inline AttributeList<ImageAttribute> FEMALE {
    { 5.0f, &NO_MOUTH },
    { 10.0f, &TURTLENECK },
    { 20.0f, &CLOWN_MEAN },
    { 20.0f, &CLOWN_SAD },
    { 20.0f, &CLOWN_SMILE },
    { 20.0f, &CREEPY },
    { 20.0f, &PACIFIER },
    { 30.0f, &COVID_MASK },
    { 35.0f, &BUBBLEGUM },
    { 50.0f, &MEAN },
    { 75.0f, &CIGARETTE },
    { 75.0f, &CUTE },
    { 100.0f, &NEUTRAL },
    { 100.0f, &SAD },
    { 100.0f, &SMILE }
};

}