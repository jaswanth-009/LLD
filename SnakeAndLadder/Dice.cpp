//
// Created by Jassvanthh Kunjeti on 19/10/25.
//
#include "headers/Dice.h"
#include <random>
#include <iostream>

Dice::Dice(int minVal, int maxVal) {
    this->minVal = minVal;
    this->maxVal = maxVal;
}

int Dice::rollDice() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minVal, maxVal);
    int ranNum = dis(gen);
    std::cout << "Obatined: " << ranNum << " after rolling\n";
    return ranNum;
}
