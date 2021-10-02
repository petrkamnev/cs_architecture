//
// Created by petrkamnev on 23.09.2021.
//
#include <fstream>
#include <string.h>

#ifndef ABC_TASK_APHORISM_H
#define ABC_TASK_APHORISM_H
struct Aphorism {
    std::string author;
    std::string text;
};

Aphorism input_aphorism(std::ifstream &input) {

    Aphorism outputAphorism;
    std::getline(input, outputAphorism.author);
    std::getline(input, outputAphorism.text);
    return outputAphorism;
}

//Aphorism generate_aphorism();

void print_aphorism(Aphorism &a, std::ofstream &output) {
    output << a.author << '\n' << a.text << '\n';
}

int get_aphorism_characteristic(Aphorism &a) {
    double counter = 0;
    std::string text = a.text;
    for (int i = 0; i < text.length(); i++) {
        if (!(text[i] >= 'a' && text[i] <= 'z' || text[i] >= 'A' && text[i] <= 'Z' || text[i] == ' ')) {
            counter += 1;
        }
    }
    return counter / text.size();
}

#endif //ABC_TASK_APHORISM_H
