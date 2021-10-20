//
// Created by petrkamnev on 19.10.2021.
//
#include "aphorism.h"

std::string Aphorism::getTitle() {
    return m_author;
}

std::string Aphorism::getContent() {
    return m_text;
}

double Aphorism::getCharacteristic() {
    double counter = 0;
    for (int i = 0; i < m_author.length(); i++) {
        if (!(m_author[i] >= 'a' && m_author[i] <= 'z' ||
              m_author[i] >= 'A' && m_author[i] <= 'Z' || m_author[i] == ' ')) {
            counter += 1;
        }
    }
    return counter / m_author.length();
}

std::string Aphorism::getType() {
    return "Aphorism";
}