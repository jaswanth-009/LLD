//
// Created by Jassvanthh Kunjeti on 18/10/25.
//

#include "headers/TicTacToeSystem.h"

#include <iostream>

#include "headers/ScoreBoard.h"

TicTacToeSystem* TicTacToeSystem::instance = nullptr;
std::mutex TicTacToeSystem::m;
std::unordered_map<std::string, Game*> TicTacToeSystem::games{};
ScoreBoard* TicTacToeSystem::sb = nullptr;

TicTacToeSystem::TicTacToeSystem() {
    // Create a scoreboard and this scoreboard should observe each game created
    sb = new ScoreBoard();
    std::cout << "Created instance for TicTacToeSystem\n";
}

TicTacToeSystem *TicTacToeSystem::getInstance() {
    if (instance == nullptr) {
        std::lock_guard<std::mutex> locking(m);
        if (instance == nullptr) {
            instance = new TicTacToeSystem();
        }
    }
    return instance;
}

std::string TicTacToeSystem::createGame(Player *p1, Player *p2, int n) {
    Game* g = new Game(n, p1, p2);
    g->addObserver(sb);
    std::string uid = g->getUid();
    games[uid] = g;
    return uid;
}

TicTacToeSystem::~TicTacToeSystem() {
    for (auto [_, g] : games) {
        delete g;
    }

    games.clear();
    if (sb != nullptr) {
        delete sb;
        sb = nullptr;
    }
}

void TicTacToeSystem::makeMove(std::string uid, Player* p, int x, int y) {
    if (games.find(uid) == games.end()) {
        std::cout << "Invalid game id: " << uid << std::endl;
        return;
    }

    games[uid]->makeMove(x, y, p);
}

Game* TicTacToeSystem::getGame(std::string gid) {
    if (games.find(gid) == games.end()) {return nullptr;}

    return games[gid];
}

void TicTacToeSystem::setWinningStrategy(std::string uid, WinningStrategy *ws) {
    if (games.find(uid) == games.end()) {
        std::cout << "Invalid game id: " << uid << std::endl;
        return;
    }
    games[uid]->setWinningStrategy(ws);
}

void TicTacToeSystem::printScoreBoard() {
    sb->printScores();
}
