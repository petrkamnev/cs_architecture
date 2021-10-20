//
// Created by petrkamnev on 19.10.2021.
//
#include "wisdomsSorter.h"

void WisdomsSorter::sort(Container<Wisdom *> &container) {
    for (int i = 1; i < container.size(); i++) {
        int index = i;
        while (index != 0 &&
               container[index - 1]->getCharacteristic() >
               container[index]->getCharacteristic()) {
            Wisdom *temp = container[index];
            container[index] = container[index - 1];
            container[index - 1] = temp;
            index--;
        }
    }
}

