//
// Created by Jassvanthh Kunjeti on 14/10/25.
//

#include "headers/Player.h"

Player::Player(std::string name, Symbol sym) {
    this->name = name;
    this->symbol = sym;
}

Symbol Player::getSymbol() const {
    return symbol;
}

std::string Player::getName() const {
    return name;
}
