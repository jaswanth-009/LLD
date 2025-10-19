//
// Created by Jassvanthh Kunjeti on 19/10/25.
//

#ifndef SNAKEANDLADDER_DICE_H
#define SNAKEANDLADDER_DICE_H

class Dice {
private:
    int minVal;
    int maxVal;
public:
    Dice(int minVal, int maxVal);
    int rollDice();
};

#endif //SNAKEANDLADDER_DICE_H