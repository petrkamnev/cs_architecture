//
// Created by petrkamnev on 15.10.2021.
//
#ifndef AVS2_RIDDLE_H
#define AVS2_RIDDLE_H

#include "informationPiece.h"

class Riddle : public InformationPiece {
public:
    Riddle() = default;

    Riddle(std::string answer, std::string text) : m_answer(answer), m_text(text) {}

    std::string getTitle();

    std::string getContent();

    double getCharacteristic();

    std::string getType();

private:
    std::string m_answer;
    std::string m_text;
};

#endif //AVS2_RIDDLE_H
