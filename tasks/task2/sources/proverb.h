//
// Created by petrkamnev on 15.10.2021.
//
#ifndef AVS2_PROVERB_H
#define AVS2_PROVERB_H

#include "informationPiece.h"

class Proverb : public InformationPiece {
public:
    Proverb() = default;

    Proverb(std::string country, std::string text) : m_country(country), m_text(text) {}

    std::string getTitle();

    std::string getContent();

    double getCharacteristic();

    std::string getType();

private:
    std::string m_country;
    std::string m_text;
};

#endif //AVS2_PROVERB_H
