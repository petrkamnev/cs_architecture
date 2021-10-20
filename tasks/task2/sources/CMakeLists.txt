cmake_minimum_required(VERSION 3.17)
project(avs2)

set(CMAKE_CXX_STANDARD 17)

add_executable(avs2 main.cpp wisdom.h riddle.h proverb.h aphorism.h wisdomGenerator.h container.h wisdomsSorter.h informationPiece.h wisdom.cpp aphorism.cpp proverb.cpp riddle.cpp wisdomGenerator.cpp wisdomsSorter.cpp)