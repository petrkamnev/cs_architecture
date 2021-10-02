//
// Created by petrkamnev on 23.09.2021.
//
#include <fstream>
#include <string.h>

#ifndef ABC_TASK_RIDDLE_H
#define ABC_TASK_RIDDLE_H
struct Riddle {
    std::string answer;
    std::string text;
};

Riddle input_riddle(std::ifstream &input) {
    Riddle outputRiddle;
    std::getline(input, outputRiddle.answer);
    std::getline(input, outputRiddle.text);
    return outputRiddle;
}

//Riddle generate_riddle();

void print_riddle(Riddle r, std::ofstream &output) {
    output << r.answer << '\n' << r.text << '\n';
}

double get_riddle_characteristic(Riddle &r) {
    double counter = 0;
    std::string text = r.text;
    for (int i = 0; i < text.length(); i++) {
        if (!(text[i] >= 'a' && text[i] <= 'z' || text[i] >= 'A' && text[i] <= 'Z' || text[i] == ' ')) {
            counter += 1;
        }
    }
    return counter / text.size();
}

#endif //ABC_TASK_RIDDLE_H
