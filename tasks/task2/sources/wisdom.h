//
// Created by petrkamnev on 15.10.2021.
//

#ifndef AVS2_WISDOM_H
#define AVS2_WISDOM_H

#include <string.h>
#include "informationPiece.h"
#include "aphorism.h"
#include "proverb.h"
#include "riddle.h"

class Wisdom : public InformationPiece {
public:
    Wisdom(Aphorism aphorism) : m_type(aphorism.getType()), m_aphorism(aphorism) {}

    Wisdom(Proverb proverb) : m_type(proverb.getType()), m_proverb(proverb) {}

    Wisdom(Riddle riddle) : m_type(riddle.getType()), m_riddle(riddle) {}

    std::string getTitle();

    std::string getContent();

    double getCharacteristic();

    std::string getType();

private:
    std::string m_type;
    Aphorism m_aphorism;
    Proverb m_proverb;
    Riddle m_riddle;
};

#endif //AVS2_WISDOM_H
