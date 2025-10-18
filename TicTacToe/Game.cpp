//
// Created by Jassvanthh Kunjeti on 14/10/25.
//

#include "headers/Game.h"
#include <iostream>

Game::Game(int size, Player *p1, Player *p2) {
    board = new Board(size);
    player1 = p1;
    player2 = p2;

    uid = generateHash();

    curPlayer = winner = nullptr;
    setState(new InProgressState());
    winningStrategy = nullptr;
}

void Game::setWinningStrategy(WinningStrategy* ws) {
    this->winningStrategy = ws;
}

void Game::makeMove(int x, int y, Player *p) {
    gameState->makeMove(this, p, x, y);
}

void Game::printBoard() {
    board->printBoard();
}

void Game::setState(State* st) {
    gameState = st;
}

Board * Game::getBoard() const {
    return board;
}

Player* Game::getWinner() const {
    return winner;
}

void Game::setCurrentPlayer(Player *p) {
    curPlayer = p;
}

void Game::switchCurrentPlayer() {
    curPlayer = (curPlayer == player1) ? player1 : player2;
}

Player *Game::getCurrenPlayer() {
    return curPlayer;
}

bool Game::checkWinner() {
    Player* p = getCurrenPlayer();
    if (winningStrategy->isWinner(p, board))
        return true;
    return false;
}

State *Game::getDrawState() {
    return new DrawState();
}

State *Game::getWinnerState() {
    return new WinnerState();
}

void Game::setWinner(Player *p) {
    winner = p;
}

std::string Game::generateHash() {
    std::string name1 = player1->getName();
    std::string name2 = player2->getName();

    return name1 + "-" + name2;
}

std::string Game::getUid() const {
    return uid;
}

void Game::notifyObservers() {
    for (int i = 0 ; i < observers.size(); i++) {
        observers[i]->update(this);
    }
}