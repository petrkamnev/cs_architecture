//
// Created by petrkamnev on 19.10.2021.
//
#include "wisdom.h"

std::string Wisdom::getTitle() {
    if (m_type == m_aphorism.getType()) {
        return m_aphorism.getTitle();
    } else if (m_type == m_proverb.getType()) {
        return m_proverb.getTitle();
    } else {
        return m_riddle.getTitle();
    }
}

std::string Wisdom::getContent() {
    if (m_type == m_aphorism.getType()) {
        return m_aphorism.getContent();
    } else if (m_type == m_proverb.getType()) {
        return m_proverb.getContent();
    } else {
        return m_riddle.getContent();
    }
}

double Wisdom::getCharacteristic() {
    if (m_type == m_aphorism.getType()) {
        return m_aphorism.getCharacteristic();
    } else if (m_type == m_proverb.getType()) {
        return m_proverb.getCharacteristic();
    } else {
        return m_riddle.getCharacteristic();
    }
}

std::string Wisdom::getType() {
    return m_type;
}
