//
// Created by Jassvanthh Kunjeti on 19/10/25.
//

#ifndef SNAKEANDLADDER_SNAKEANDLADDER_H
#define SNAKEANDLADDER_SNAKEANDLADDER_H

#include <mutex>
#include <unordered_map>
#include "Game.h"

class SnakeAndLadder {
    public:
        static std::mutex m;
        static SnakeAndLadder* instance;
        static SnakeAndLadder *getInstance();
        static std::string createGame(int size, std::vector<BoardEntity*> entities, std::vector<Player* > players, Dice* d);
        static void startGame(std::string gid);
    private:
        static std::unordered_map<std::string, Game*> games;
        SnakeAndLadder();
        ~SnakeAndLadder();
        SnakeAndLadder(const SnakeAndLadder &) = delete;
        SnakeAndLadder &operator=(const SnakeAndLadder &) = delete;
};
#endif //SNAKEANDLADDER_SNAKEANDLADDER_H