//
// Created by Jassvanthh Kunjeti on 18/10/25.
//

#ifndef TICTACTOE_GAMEOBSERVER_H
#define TICTACTOE_GAMEOBSERVER_H

class Game;
class GameObserver {
    public:
        virtual void update(Game* g) = 0;
};
#endif //TICTACTOE_GAMEOBSERVER_H