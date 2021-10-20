//
// Created by petrkamnev on 19.10.2021.
//
#include "riddle.h"

std::string Riddle::getTitle() {
    return m_answer;
}

std::string Riddle::getContent() {
    return m_text;
}

double Riddle::getCharacteristic() {
    double counter = 0;
    for (int i = 0; i < m_answer.length(); i++) {
        if (!(m_answer[i] >= 'a' && m_answer[i] <= 'z' ||
              m_answer[i] >= 'A' && m_answer[i] <= 'Z' || m_answer[i] == ' ')) {
            counter += 1;
        }
    }
    return counter / m_answer.length();
}

std::string Riddle::getType() {
    return "Riddle";
}
