//
// Created by petrkamnev on 15.10.2021.
//
#include "wisdom.h"
#include "proverb.h"
#include "riddle.h"
#include "aphorism.h"
#include <ranlib.h>
#include <time.h>

#ifndef AVS2_WISDOMGENERATOR_H
#define AVS2_WISDOMGENERATOR_H

class WisdomGenerator {
public:
    WisdomGenerator();

    Wisdom *generateRandomWisdom();

private:
    static const std::string kAlphabet;
};

const std::string WisdomGenerator::kAlphabet = "abcdefghijklmnopqrstuvwxyz!#$%^&*()_-+=.,/?";

#endif //AVS2_WISDOMGENERATOR_H
