//
// Created by petrkamnev on 19.10.2021.
//
#include "proverb.h"

std::string Proverb::getTitle() {
    return m_country;
}

std::string Proverb::getContent() {
    return m_text;
}

double Proverb::getCharacteristic() {
    double counter = 0;
    for (int i = 0; i < m_country.length(); i++) {
        if (!(m_country[i] >= 'a' && m_country[i] <= 'z' ||
              m_country[i] >= 'A' && m_country[i] <= 'Z' || m_country[i] == ' ')) {
            counter += 1;
        }
    }
    return counter / m_country.length();
}

std::string Proverb::getType() {
    return "Proverb";
}
