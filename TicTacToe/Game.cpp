//
// Created by Jassvanthh Kunjeti on 14/10/25.
//

#include "headers/Game.h"
#include <iostream>

Game::Game(int size, Player *p1, Player *p2) {
    board = new Board(size);
    player1 = p1;
    player2 = p2;

    curPlayer = winner = nullptr;
    status = Status::InProgress;
    winningStrategy = nullptr;
    std::cout << "Started game\n";
}

void Game::setWinningStrategy(WinningStrategy* ws) {
    this->winningStrategy = ws;
}

void Game::makeMove(int x, int y, Player *p) {
    if (status == Status::Draw || status == Status::Winner) {
        std::cout << "Game is already over\n";
        return;
    }

    std::cout << "Trying to make move for [" << x << ", " << y << "]\n";

    if (curPlayer == nullptr) {
        curPlayer = p;
    }
    else if (curPlayer == p) {
        std::cout << "Player " << p->getName() << " can not make 2 moves in a row\n";
        return;
    }

    if (!board->placeSymbol(x,y,p)) {
        std::cout << "Failed to make the move by " << p->getName() << "\n";
    }

    // after making move, check for winner
    if (winningStrategy->isWinner(p, board)) {
        status = Status::Winner;
        std::cout << "Game won by player: " << p->getName() << "\n";
        winner = p;
        board->printBoard();
    }
    else if (board->getMovesCount() == board->getBoardSize()*board->getBoardSize()) {
        status = Status::Draw;
    }

    curPlayer = p;
}

void Game::printBoard() {
    board->printBoard();
}