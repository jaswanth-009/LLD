cmake_minimum_required(VERSION 4.0)
project(AutoCompleteSuggestion)

set(CMAKE_CXX_STANDARD 20)

add_executable(AutoCompleteSuggestion main.cpp
        AlphabeticalOrder.cpp
        SerachComplete.cpp
        FrequencyBasedOrder.cpp)
