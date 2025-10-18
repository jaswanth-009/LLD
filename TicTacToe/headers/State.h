//
// Created by Jassvanthh Kunjeti on 18/10/25.
//

#ifndef TICTACTOE_STATE_H
#define TICTACTOE_STATE_H

class Game;
class Player;

class State {
    public:
        virtual void makeMove(Game* game, Player* p, int r, int c) = 0;
        virtual ~State() {}
};
#endif //TICTACTOE_STATE_H