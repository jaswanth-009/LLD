//
// Created by Jassvanthh Kunjeti on 19/10/25.
//

#include "headers/Snake.h"
#include <iostream>
#include <valarray>

Snake::Snake(int startPosition, int endPosition): BoardEntity(startPosition, endPosition) {
    if (!arePositionsValid(startPosition, endPosition)) {
        throw std::invalid_argument("Invalid startPosition or endPosition for a Snake");
    }
}

bool Snake::arePositionsValid(int start, int end) {
    if (start <= end) {
        std::cout << "Snake head must be high than tail\n";
        return false;
    }
    return true;
}
