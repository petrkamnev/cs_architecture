#include <iostream>
#include <fstream>
#include <chrono>
#include <stdlib.h>
#include <string.h>
#include <random>
#include <string>
#include "extrn.h"


template<typename T>
class Container {
public:

    Container() : m_currentSize(0) {}

    void push_back(T value) {
        m_array[m_currentSize] = value;
        m_currentSize++;
    }

    void pop_back() {
        m_currentSize--;
    }

    T& operator[](size_t position) {
        return m_array[position];
    }

    size_t size() {
        return m_currentSize;
    }

private:
    static constexpr size_t kCapacity = 10000;
    T m_array[kCapacity];
    size_t m_currentSize;
};

class InformationPiece {
public:
    virtual std::string getTitle() = 0;

    virtual std::string getContent() = 0;

    virtual double getCharacteristic() = 0;

    virtual std::string getType() = 0;
};


class Aphorism : public InformationPiece {
public:
    Aphorism() = default;

    Aphorism(std::string author, std::string text) : m_author(author), m_text(text) {}

    std::string getTitle();

    std::string getContent();

    double getCharacteristic();

    std::string getType();

private:
    std::string m_author;
    std::string m_text;
};


class Proverb : public InformationPiece {
public:
    Proverb() = default;

    Proverb(std::string country, std::string text) : m_country(country), m_text(text) {}

    std::string getTitle();

    std::string getContent();

    double getCharacteristic();

    std::string getType();

private:
    std::string m_country;
    std::string m_text;
};

class Riddle : public InformationPiece {
public:
    Riddle() = default;

    Riddle(std::string answer, std::string text) : m_answer(answer), m_text(text) {}

    std::string getTitle();

    std::string getContent();

    double getCharacteristic();

    std::string getType();

private:
    std::string m_answer;
    std::string m_text;
};

class Wisdom : public InformationPiece {
public:
    Wisdom(Aphorism aphorism) : m_type(aphorism.getType()), m_aphorism(aphorism) {}

    Wisdom(Proverb proverb) : m_type(proverb.getType()), m_proverb(proverb) {}

    Wisdom(Riddle riddle) : m_type(riddle.getType()), m_riddle(riddle) {}

    std::string getTitle();

    std::string getContent();

    double getCharacteristic();

    std::string getType();

private:
    std::string m_type;
    Aphorism m_aphorism;
    Proverb m_proverb;
    Riddle m_riddle;
};

std::string Wisdom::getTitle() {
    if (m_type == m_aphorism.getType()) {
        return m_aphorism.getTitle();
    }
    else if (m_type == m_proverb.getType()) {
        return m_proverb.getTitle();
    }
    else {
        return m_riddle.getTitle();
    }
}

std::string Wisdom::getContent() {
    if (m_type == m_aphorism.getType()) {
        return m_aphorism.getContent();
    }
    else if (m_type == m_proverb.getType()) {
        return m_proverb.getContent();
    }
    else {
        return m_riddle.getContent();
    }
}

double Wisdom::getCharacteristic() {
    if (m_type == m_aphorism.getType()) {
        return m_aphorism.getCharacteristic();
    }
    else if (m_type == m_proverb.getType()) {
        return m_proverb.getCharacteristic();
    }
    else {
        return m_riddle.getCharacteristic();
    }
}

std::string Wisdom::getType() {
    return m_type;
}


std::string Aphorism::getTitle() {
    return m_author;
}

std::string Aphorism::getContent() {
    return m_text;
}

double Aphorism::getCharacteristic() {
    return getCharacteristicF(m_text.data(), m_text.length());
}

std::string Aphorism::getType() {
    return "Aphorism";
}


std::string Proverb::getTitle() {
    return m_country;
}

std::string Proverb::getContent() {
    return m_text;
}

double Proverb::getCharacteristic() {
    return getCharacteristicF(m_text.data(), m_text.length());
}

std::string Proverb::getType() {
    return "Proverb";
}



std::string Riddle::getTitle() {
    return m_answer;
}

std::string Riddle::getContent() {
    return m_text;
}

double Riddle::getCharacteristic() {
    return getCharacteristicF(m_text.data(), m_text.length());
}

std::string Riddle::getType() {
    return "Riddle";
}


class WisdomGenerator {
public:
    WisdomGenerator();

    Wisdom* generateRandomWisdom();

private:
    static const std::string kAlphabet;
};

const std::string WisdomGenerator::kAlphabet = "abcdefghijklmnopqrstuvwxyz!#$%^&*()_-+=.,/?";

WisdomGenerator::WisdomGenerator() {
    srand(time(0));
}

Wisdom* WisdomGenerator::generateRandomWisdom() {
    int type = rand() % 3;
    std::string title;
    std::string content;
    int titleLength = (rand() % 10) + 1;
    int contentLength = (rand() % 100) + 1;
    for (int i = 0; i < titleLength; i++) {
        title += kAlphabet[rand() % 43];
    }
    for (int i = 0; i < contentLength; i++) {
        content += kAlphabet[rand() % 43];
    }
    if (type == 0) {
        return new Wisdom(Aphorism(title, content));
    }
    else if (type == 1) {
        return new Wisdom(Proverb(title, content));
    }
    else {
        return new Wisdom(Riddle(title, content));
    }
}

class WisdomsSorter {
public:
    void sort(Container<Wisdom*>& container);
};

void WisdomsSorter::sort(Container<Wisdom*>& container) {
    for (int i = 1; i < container.size(); i++) {
        int index = i;
        while (index != 0 &&
            container[index - 1]->getCharacteristic() >
            container[index]->getCharacteristic()) {
            Wisdom* temp = container[index];
            container[index] = container[index - 1];
            container[index - 1] = temp;
            index--;
        }
    }
}


int main(int argc, char *argv[]) {
    std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
    Container<Wisdom *> wisdoms;
    if (!strcmp(argv[1], "-r")) {
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
