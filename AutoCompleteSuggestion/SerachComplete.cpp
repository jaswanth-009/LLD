//
// Created by Jassvanthh Kunjeti on 01/11/25.
//

#include "headers/SearchComplete.h"
#include <iostream>

SearchComplete::SearchComplete(int k, std::vector<std::string> words, std::vector<int> freq) {
    this->k = k;
    this->searchWord = "";
    this->st = nullptr;
    this->root = new Trie();

    for (int i = 0; i < words.size(); i++) {
        std::string word = words[i];
        int f = freq[i];

        insert(word, root, f);
    }
}

void SearchComplete::setLookUpStrategy(LookUpStrategy *l) {
    this->st = l;
}

void SearchComplete::removeLastCharFromSearchString() {
    if (this->searchWord.empty()) {
        std::cout << "Search word is empty\n";
        return;
    }

    this->searchWord.pop_back();
    printTopKMatches();
}

void SearchComplete::addCharToSearchString(char c) {

    if (c != '#') {
        this->searchWord.push_back(c);
    }
    else {
        std::cout << "Adding current string to database\n";
        insert(this->searchWord, this->root, 1);
    }

    printTopKMatches();

    if (c == '#') {
        std::cout << "Clearing the search string for a fresh start\n";
        this->searchWord.clear();
    }
}

void SearchComplete::printTopKMatches() {
    if (this->st == nullptr) {
        std::cout << " LookUp Strategy is not set\n";
        return;
    }
    std::vector<std::string> results = this->st->TopKMatches(this->searchWord, root, k);

    if (results.empty()) {
        std::cout << "No matching strings found from databse\n";
        return;
    }

    std::cout << "Matching words are: \n";
    for (int i = 0; i < results.size(); i++) {
        std::cout << results[i] << "\n";
    }
}

void SearchComplete::setKValue(int k) {
    this->k = k;
    std::cout << "Updated K value to: " << this->k << "\n";
    std::cout << "Getting top " << this->k << " matches\n";
    printTopKMatches();
}
