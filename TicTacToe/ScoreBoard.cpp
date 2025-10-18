//
// Created by Jassvanthh Kunjeti on 18/10/25.
//

#include "headers/ScoreBoard.h"

#include <iostream>

#include "headers/Game.h"

void ScoreBoard::update(Game *g) {
    if (g->getWinner() != nullptr) {
        std::string winner = g->getWinner()->getName();
        scores[winner]++;
    }
}

void ScoreBoard::printScores() {
    for (auto& [player, score]: scores)
        std::cout << player << " " << score << "\n";
}

