//
// Created by Jassvanthh Kunjeti on 19/10/25.
//

#ifndef SNAKEANDLADDER_PLAYER_H
#define SNAKEANDLADDER_PLAYER_H
#include <string>

class Player {
private:
    std::string name;
    int position;
public:
    Player(std::string name);
    std::string getName();
    void setPosition(int position);
    int getPosition() const;
};
#endif //SNAKEANDLADDER_PLAYER_H