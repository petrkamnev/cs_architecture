//
// Created by petrkamnev on 02.10.2021.
//
#include <fstream>
#include <ranlib.h>
#include <time.h>

#ifndef ABC_TASK_GENERATOR_H
#define ABC_TASK_GENERATOR_H
char *alphabet = "abcdefghijklmnopqrstuvwxyz!#$%^&*()_-+=.,/?";

void generate_input_file(int number, std::ofstream &inputFile) {
    std::srand(time(0));
    for (int i = 0; i < number; i++) {
        inputFile << (rand() % 3) << '\n';
        int length1 = (rand() % 10) + 1;
        int length2 = (rand() % 100) + 1;
        for (int j = 0; j < length1; j++) {
            inputFile << alphabet[rand() % 43];
        }
        inputFile << '\n';
        for (int j = 0; j < length2; j++) {
            inputFile << alphabet[rand() % 43];
        }
        if (i < number - 1) { inputFile << '\n'; }
    }
    return;
}

#endif //ABC_TASK_GENERATOR_H
