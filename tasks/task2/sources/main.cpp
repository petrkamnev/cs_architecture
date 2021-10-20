#include <iostream>
#include <fstream>
#include <chrono>
#include <stdlib.h>
#include <string.h>

#include "container.h"
#include "wisdom.h"
#include "aphorism.h"
#include "proverb.h"
#include "riddle.h"
#include "wisdomGenerator.h"
#include "wisdomsSorter.h"

int main(int argc, char *argv[]) {
    std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
    Container<Wisdom *> wisdoms;
    if (!std::strcmp(argv[1], "-r")) {
        WisdomGenerator generator;
        int wisdomsCount = std::atoi(argv[2]);
        for (int i = 0; i < wisdomsCount; i++) {
            wisdoms.push_back(generator.generateRandomWisdom());
        }
    } else {
        std::ifstream input(argv[2]);
        while (!input.eof()) {
            std::string type;
            std::string title;
            std::string content;
            getline(input, type);
            getline(input, title);
            getline(input, content);
            if (type == "0") {
                wisdoms.push_back(new Wisdom(Aphorism(title, content)));
            } else if (type == "1") {
                wisdoms.push_back(new Wisdom(Proverb(title, content)));
            } else {
                wisdoms.push_back(new Wisdom(Riddle(title, content)));
            }
        }
    }
    WisdomsSorter sorter;
    std::ofstream output1(argv[3]);
    for (int i = 0; i < wisdoms.size(); i++) {
        output1 << wisdoms[i]->getType() + '\n' + wisdoms[i]->getTitle() + '\n' +
                   wisdoms[i]->getContent() + '\n' << wisdoms[i]->getCharacteristic() << '\n';
    }
    sorter.sort(wisdoms);
    std::ofstream output2(argv[4]);
    for (int i = 0; i < wisdoms.size(); i++) {
        output2 << wisdoms[i]->getType() + '\n' + wisdoms[i]->getTitle() + '\n' +
                   wisdoms[i]->getContent() + '\n' << wisdoms[i]->getCharacteristic() << '\n';
    }
    std::chrono::steady_clock::time_point finishTime = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(
            finishTime - startTime).count() << "[microseconds]"
              << std::endl;// вывод времени исполнения
}
