//
// Created by petrkamnev on 25.09.2021.
//
#include "information.h"

#ifndef ABC_TASK_CONTAINER_H
#define ABC_TASK_CONTAINER_H
struct container {
    static const int MAX_LEN = 10000;
    int len;
    Information array[MAX_LEN];
};

void init(container &c) {
    c.len = 0;
}

void input_container(container &c, std::ifstream &input) {
    while (!input.eof()) {
        c.array[c.len] = input_information(input);
        c.len++;
    }
}

void print_container(container &c, std::ofstream &output) {
    for (int i = 0; i < c.len; i++) {
        print_information(c.array[i], output);
        output << '\n';
    }
}

void sort_container(container &c) {
    for (int i = 1; i < c.len; i++) {
        int index = i;
        while (index != 0 &&
               get_information_characterictic(c.array[index - 1]) > get_information_characterictic(c.array[index])) {
            Information temp = c.array[index];
            c.array[index] = c.array[index - 1];
            c.array[index - 1] = temp;
            index--;
        }
    }
}


#endif //ABC_TASK_CONTAINER_H
