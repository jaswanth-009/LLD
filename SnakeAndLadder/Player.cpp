//
// Created by Jassvanthh Kunjeti on 19/10/25.
//

#include "headers/Player.h"

Player::Player(std::string name) {
    this->name = name;
    this->position = 0;
}

std::string Player::getName() {
    return this->name;
}

void Player::setPosition(int position) {
    this->position = position;
}

int Player::getPosition() const {
    return this->position;
}


