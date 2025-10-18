//
// Created by Jassvanthh Kunjeti on 18/10/25.
//

#include "headers/InProgressState.h"
#include <iostream>
#include "headers/Game.h"
#include "headers/Player.h"

void InProgressState::makeMove(Game *game, Player *p, int r, int c) {

    if (game->getCurrenPlayer() == nullptr) {
        game->setCurrentPlayer(p);
    }

    Board* board = game->getBoard();
    if (!board->placeSymbol(r,c, p)) {
        std::cout << "Failed to make the move by " << p->getName() << "\n";
        return;
    }

    if (game->checkWinner()) {
        game->setState(game->getWinnerState());
        game->setWinner(p);
        std::cout << "Game won by player: " << p->getName() << "\n";
        board->printBoard();
    }
    else if (board->getMovesCount() == board->getBoardSize()*board->getBoardSize()) {
        game->setState(game->getDrawState());
    }

    game->switchCurrentPlayer();
}

