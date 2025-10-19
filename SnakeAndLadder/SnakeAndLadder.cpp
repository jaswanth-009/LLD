//
// Created by Jassvanthh Kunjeti on 19/10/25.
//

#include "headers/SnakeAndLadder.h"
#include <iostream>

std::mutex SnakeAndLadder::m;
SnakeAndLadder* SnakeAndLadder::instance = nullptr;
std::unordered_map<std::string, Game*> SnakeAndLadder::games;

SnakeAndLadder *SnakeAndLadder::getInstance() {
    if (instance == nullptr) {
        std::lock_guard<std::mutex> lock(m);
        if (instance == nullptr) {
            instance = new SnakeAndLadder();
        }
    }
    return instance;
}

SnakeAndLadder::SnakeAndLadder() {
    std::cout << "Created a single POC for the game\n";
}

std::string SnakeAndLadder::createGame(int size, std::vector<BoardEntity*> entities, std::vector<Player *> players, Dice *d) {
    Game *g;
    Game::Builder obj = Game::Builder(size, entities);
    g = obj.setDice(d).setPlayers(players).build();
    std::string gid = g->getGameId();
    games[gid] = g;
    return gid;
}

void SnakeAndLadder::startGame(std::string gid) {
    if (games.find(gid) == games.end()) {
        std::cout << "Game " << gid << " not found\n";
        return;
    }

    games.at(gid)->play();
}

SnakeAndLadder::~SnakeAndLadder() {
    for (auto [_, g]: games) {
        delete g;
    }
    games.clear();
}
