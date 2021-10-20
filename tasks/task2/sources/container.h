//
// Created by petrkamnev on 18.10.2021.
//

#ifndef AVS2_CONTAINER_H
#define AVS2_CONTAINER_H

#include <iostream>

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

    T &operator[](size_t position) {
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

#endif //AVS2_CONTAINER_H
