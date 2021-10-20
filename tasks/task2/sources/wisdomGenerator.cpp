//
// Created by petrkamnev on 19.10.2021.
//
#include "wisdomGenerator.h"

WisdomGenerator::WisdomGenerator() {
    srand(time(0));
}

Wisdom *WisdomGenerator::generateRandomWisdom() {
    int type = rand() % 3;
    std::string title;
    std::string content;
    int titleLength = (rand() % 10) + 1;
    int contentLength = (rand() % 100) + 1;
    for (int i = 0; i < titleLength; i++) {
        title += kAlphabet[rand() % 43];
    }
    for (int i = 0; i < contentLength; i++) {
        content += kAlphabet[rand() % 43];
    }
    if (type == 0) {
        return new Wisdom(Aphorism(title, content));
    } else if (type == 1) {
        return new Wisdom(Proverb(title, content));
    } else {
        return new Wisdom(Riddle(title, content));
    }
}
