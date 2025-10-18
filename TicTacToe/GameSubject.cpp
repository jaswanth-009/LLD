//
// Created by Jassvanthh Kunjeti on 18/10/25.
//

#include "headers/GameSubject.h"

void GameSubject::addObserver(GameObserver *observer) {
    observers.push_back(observer);
}

void GameSubject::removeObserver(GameObserver *observer) {
    for (int i = 0; i < observers.size(); i++) {
        if (observer == observers.at(i)) {
            observers.erase(observers.begin() + i);
            return;
        }
    }
}