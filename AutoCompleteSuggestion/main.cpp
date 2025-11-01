#include <iostream>

#include "headers/AlphabeticalOrder.h"
#include "headers/FrequencyBasedOrder.h"
#include "headers/SearchComplete.h"

int main() {
    std::vector<std::string> words = {"an", "app", "apple", "app store", "ant", "anxious"};
    std::vector<int> frequenceis = {1, 2, 3, 4, 5, 4};

    SearchComplete* sc = new SearchComplete(3, words, frequenceis);
    LookUpStrategy* f = new FrequencyBasedOrder();

    sc->setLookUpStrategy(f);

    sc->addCharToSearchString('a');
    sc->addCharToSearchString('n');
    sc->addCharToSearchString('e');
    sc->addCharToSearchString('#');

    sc->addCharToSearchString('a');
    sc->addCharToSearchString('t');
    sc->addCharToSearchString('#');


    delete f, sc;

    return 0;
}