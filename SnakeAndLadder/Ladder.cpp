//
// Created by Jassvanthh Kunjeti on 19/10/25.
//
#include "headers/Ladder.h"
#include <iostream>

Ladder::Ladder(int startPosition, int endPosition): BoardEntity(startPosition, endPosition) {
    if (!arePositionsValid(startPosition, endPosition)) {
        throw std::invalid_argument("Invalid startPosition or endPosition for Ladder");
    }
}

bool Ladder::arePositionsValid(int start, int end) {
    if (start >= end) {
        std::cout << "Ladder start must be less than the ladder end\n";
        return false;
    }
    return true;
}
