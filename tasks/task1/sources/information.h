//
// Created by petrkamnev on 23.09.2021.
//
#include "aphorism.h"
#include "proverb.h"
#include "riddle.h"

#ifndef ABC_TASK_INFORMATION_H
#define ABC_TASK_INFORMATION_H

struct Information {
    enum InformationType {
        APHORISM, PROVERB, RIDDLE
    };
    InformationType t;

    Aphorism a;
    Proverb p;
    Riddle r;

};

Information input_information(std::ifstream &input) {
    Information outputInformation;
    std::string informationType;
    getline(input, informationType);
    if (informationType == "0") {
        outputInformation.t = Information::APHORISM;
        outputInformation.a = input_aphorism(input);
    } else if (informationType == "1") {
        outputInformation.t = Information::PROVERB;
        outputInformation.p = input_proverb(input);
    } else if (informationType == "2") {
        outputInformation.t = Information::RIDDLE;
        outputInformation.r = input_riddle(input);
    }
    return outputInformation;
}

//Information generate_information();

void print_information(Information &info, std::ofstream &output) {
    Information::InformationType informationType = info.t;
    if (informationType == Information::APHORISM) {
        output << "Aphorism:\n";
        print_aphorism(info.a, output);
        output << get_aphorism_characteristic(info.a) << '\n';
    } else if (informationType == Information::PROVERB) {
        output << "Proverb:\n";
        print_proverb(info.p, output);
        output << get_proverb_characteristic(info.p) << '\n';
    } else if (informationType == Information::RIDDLE) {
        output << "Riddle:\n";
        print_riddle(info.r, output);
        output << get_riddle_characteristic(info.r) << '\n';
    }
}

double get_information_characterictic(Information &info) {
    int informationType = info.t;
    if (informationType == 0) {
        return get_aphorism_characteristic(info.a);
    } else if (informationType == 1) {
        return get_proverb_characteristic(info.p);
    } else if (informationType == 2) {
        return get_riddle_characteristic(info.r);
    }
}

#endif //ABC_TASK_INFORMATION_H
