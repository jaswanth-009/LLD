//
// Created by Jassvanthh Kunjeti on 19/10/25.
//

#include "headers/Game.h"

#include <iostream>
#include <ostream>

State Game::getCurrentState() const {
    return state;
}

Game::Builder::Builder(int size, std::vector<BoardEntity *> snl) {
    this->board = new Board(size, snl);
}

Game::Builder &Game::Builder::setDice(Dice *d) {
    this->dice = d;
    return *this;
}

Game::Builder& Game::Builder::setPlayers(std::vector<Player*> p) {
    this->players = p;
    return *this;
}

Game* Game::Builder::build() {
    return new Game(this->board, this->dice, this->players);
}

Game::Game(Board *board, Dice *dice, std::vector<Player *> players) {
    this->board = board;
    this->dice = dice;
    this->state = State::InProgress;
    this->winner = nullptr;
    this->gid = generateHash();
    for (auto p: players) {
        this->players.push(p);
    }
}

std::string Game::generateHash() {
    return "g123";
}

std::string Game::getGameId() const {
    return this->gid;
}

Player* Game::getWinner() {
    return winner;
}

void Game::setState(State s) {
    this->state = s;
}

void Game::setWinner(Player* p) {
    this->winner = p;
}

void Game::play() {

    if (this->players.size() < 2) {
        std::cout << "Minimum 2 players are needed to play games\n";
        return;
    }

    if (getCurrentState() == State::Winner) {
        std::cout << "Game won by: " << getWinner()->getName() << "\n";
        return;
    }

    while (getCurrentState() != State::Winner) {
        Player *p = this->players.front();
        this->players.pop();
        this->players.push(p);

        int initialPos = p->getPosition();

        int newPos = initialPos + this->dice->rollDice();
        int finalPos = this->board->getFinalPosition(newPos);

        std::cout << p->getName() << " Obtained final Position: " << finalPos << "\n";

        if (finalPos > this->board->getBoardSize()) {
            std::cout << "New Position: " << finalPos << " is out of bounds for board. Better luck next time\n";
            continue;
        }

        if (finalPos == this->board->getBoardSize()) {
            this->setState(State::Winner);
            this->setWinner(p);
        }

        p->setPosition(finalPos);
    }
}



