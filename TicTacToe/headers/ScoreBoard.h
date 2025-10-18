//
// Created by Jassvanthh Kunjeti on 18/10/25.
//

#ifndef TICTACTOE_SCOREBOARD_H
#define TICTACTOE_SCOREBOARD_H
#include <string>
#include <unordered_map>

#include "GameObserver.h"

class ScoreBoard: public GameObserver {
public:
    std::unordered_map<std::string, int> scores{};
    void update(Game* g) override;
    void printScores();
};
#endif //TICTACTOE_SCOREBOARD_H