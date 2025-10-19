#include <iostream>

#include "headers/Ladder.h"
#include "headers/Snake.h"
#include "headers/SnakeAndLadder.h"


int main() {

    SnakeAndLadder* sys = SnakeAndLadder::getInstance();

    std::vector<Player*> players{};
    Player* p1 = new Player("Jaswanth");
    Player* p2 = new Player("John");
    Player* p3 = new Player("Jonathan");
    players.push_back(p1);
    players.push_back(p2);
    players.push_back(p3);

    Dice* d = new Dice(1,6);

    std::vector<BoardEntity*> snl{};
    BoardEntity* s1 = new Snake(30, 10);
    snl.push_back(s1);
    BoardEntity* s2 = new Snake(40, 25);
    snl.push_back(s2);
    BoardEntity* s3 = new Snake(50, 40);
    snl.push_back(s3);

    BoardEntity* l1 = new Ladder(2, 15);
    snl.push_back(l1);
    BoardEntity* l2 = new Ladder(14, 29);
    snl.push_back(l2);
    BoardEntity* l3 = new Ladder(45, 78);
    snl.push_back(l3);

    std::string gid = sys->createGame(100, snl, players, d);

    sys->startGame(gid);

    delete p1, p2, p3, s1, s2, s3, l1, l2, l3;

    return 0;
}