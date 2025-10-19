//
// Created by Jassvanthh Kunjeti on 19/10/25.
//

#ifndef SNAKEANDLADDER_GAME_H
#define SNAKEANDLADDER_GAME_H

#include "Board.h"
#include <queue>
#include <vector>
#include "Player.h"
#include "State.h"
#include "Dice.h"

class Game {
    private:
        Board* board;
        std::queue<Player*> players;
        Player* winner;
        State state;
        Dice* dice;
        std::string gid;

        Game(Board* board, Dice* dice, std::vector<Player*> players);

    public:

        class Builder {
            private:
                Board* board;
                std::vector<Player*> players;
                Dice* dice;
            public:
                Builder (int size, std::vector<BoardEntity *> snl);

                Builder& setDice(Dice* d);
                Builder& setPlayers(std::vector<Player*> p);
                Game* build();
        };

        void play();
        void setWinner(Player* p);
        Player* getWinner();
        void setState(State s);
        std::string generateHash();
        std::string getGameId() const;
        State getCurrentState() const;
};

#endif //SNAKEANDLADDER_GAME_H