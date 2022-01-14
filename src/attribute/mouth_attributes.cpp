#include "attributes.hpp"

namespace buddy {
namespace mouth {

const std::string ATTRIBUTE_NAME("Mouth");
const std::string FACIAL_HAIR_NAME("Facial hair");

Attribute NO_MOUTH { "No mouth", "assets/mouth/no_mouth.png" };
Attribute CLOWN_MEAN { "Clown mean", "assets/mouth/clown_mean.png" };
Attribute CLOWN_SAD { "Clown sad", "assets/mouth/clown_sad.png" };
Attribute CLOWN_SMILE { "Clown smile", "assets/mouth/clown_smile.png" };
Attribute CREEPY { "Creepy", "assets/mouth/creepy.png" };
Attribute PACIFIER { "Pacifier", "assets/mouth/pacifier.png" };
Attribute COVID_MASK { "Covid mask", "assets/mouth/covid_mask.png" };
Attribute MEAN { "Mean", "assets/mouth/mean.png" };
Attribute PIPE { "Pipe", "assets/mouth/pipe.png" };
Attribute CIGARETTE { "Cigarette ", "assets/mouth/cigarette.png" };
Attribute NEUTRAL { "Neutral", "assets/mouth/neutral.png" };
Attribute SAD { "Sad", "assets/mouth/sad.png" };
Attribute SMILE { "Smile", "assets/mouth/smile.png" };
Attribute TURTLENECK { "Smile", "assets/mouth/turtleneck.png" };
Attribute CUTE { "Cute", "assets/mouth/cute.png" };
Attribute RUNNY_NOSE { "Runny nose", "assets/mouth/runny_nose.png" };
Attribute BUBBLEGUM { "Bubblegum", "assets/mouth/bubblegum.png" };

Attribute BEARD { "Beard", "assets/mouth/beard.png" };
Attribute BEARD_SMILE { "Beard smile", "assets/mouth/beard_smile.png" };
Attribute LONG_BEARD { "Long beard", "assets/mouth/long_beard.png" };
Attribute LONG_BEARD_SMILE { "Long beard smile", "assets/mouth/long_beard_smile.png" };
Attribute MUSTACHE { "Mustache", "assets/mouth/mustache.png" };

const AttributeList<Attribute> MALE {
    { 5.0, &NO_MOUTH },
    { 10.0, &TURTLENECK },
    { 20.0, &CLOWN_MEAN },
    { 20.0, &CLOWN_SAD },
    { 20.0, &CLOWN_SMILE },
    { 20.0, &CREEPY },
    { 20.0, &PACIFIER },
    { 25.0, &BUBBLEGUM },
    { 30.0, &COVID_MASK },
    { 50.0, &MEAN },
    { 50.0, &PIPE },
    { 50.0, &RUNNY_NOSE },
    { 75.0, &CIGARETTE },
    { 100.0, &NEUTRAL },
    { 100.0, &SAD },
    { 100.0, &SMILE }
};

const AttributeList<Attribute> FACIAL_HAIR {
    { 1.0, &BEARD },
    { 1.0, &LONG_BEARD },
    { 1.0, &BEARD_SMILE },
    { 1.0, &LONG_BEARD_SMILE },
    { 1.0, &MUSTACHE }
};

const AttributeList<Attribute> FEMALE {
    { 5.0, &NO_MOUTH },
    { 10.0, &TURTLENECK },
    { 20.0, &CLOWN_MEAN },
    { 20.0, &CLOWN_SAD },
    { 20.0, &CLOWN_SMILE },
    { 20.0, &CREEPY },
    { 20.0, &PACIFIER },
    { 30.0, &COVID_MASK },
    { 35.0, &BUBBLEGUM },
    { 50.0, &MEAN },
    { 75.0, &CIGARETTE },
    { 75.0, &CUTE },
    { 100.0, &NEUTRAL },
    { 100.0, &SAD },
    { 100.0, &SMILE }
};

}
}