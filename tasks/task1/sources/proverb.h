//
// Created by petrkamnev on 23.09.2021.
//
#include <fstream>
#include <string.h>

#ifndef ABC_TASK_PROVERB_H
#define ABC_TASK_PROVERB_H
struct Proverb {
    std::string country;
    std::string text;
};

Proverb input_proverb(std::ifstream &input) {
    Proverb outputProverb;
    std::getline(input, outputProverb.country);
    std::getline(input, outputProverb.text);
    return outputProverb;
}

//Proverb generate_proverb();

void print_proverb(Proverb &p, std::ofstream &output) {
    output << p.country << '\n' << p.text << '\n';
}

double get_proverb_characteristic(Proverb &p) {
    double counter = 0;
    std::string text = p.text;
    for (int i = 0; i < text.length(); i++) {
        if (!(text[i] >= 'a' && text[i] <= 'z' || text[i] >= 'A' && text[i] <= 'Z' || text[i] == ' ')) {
            counter += 1;
        }
    }
    return counter / text.size();
}

#endif //ABC_TASK_PROVERB_H
