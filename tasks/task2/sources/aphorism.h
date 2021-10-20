//
// Created by petrkamnev on 15.10.2021.
//
#ifndef AVS2_APHORISM_H
#define AVS2_APHORISM_H

#include "informationPiece.h"

class Aphorism : public InformationPiece {
public:
    Aphorism() = default;

    Aphorism(std::string author, std::string text) : m_author(author), m_text(text) {}

    std::string getTitle();

    std::string getContent();

    double getCharacteristic();

    std::string getType();

private:
    std::string m_author;
    std::string m_text;
};

#endif //AVS2_APHORISM_H
