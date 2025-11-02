//
// Created by Jassvanthh Kunjeti on 01/11/25.
//

#ifndef AUTOCOMPLETESUGGESTION_SEARCHCOMPLETE_H
#define AUTOCOMPLETESUGGESTION_SEARCHCOMPLETE_H
#include <string>

#include "LookUpStrategy.h"

class SearchComplete {
    private:
        std::string searchWord;
        LookUpStrategy* st;
        int k;
        Trie* root;
        std::mutex m;
    public:
        SearchComplete(int k, std::vector<std::string> words, std::vector<int> freq);
        void setLookUpStrategy(LookUpStrategy* l);
        void removeLastCharFromSearchString();
        void addCharToSearchString(char c);
        void printTopKMatches();
        void setKValue(int k);
        void addMoreWordsToSerachBase(std::vector<std::string>& words, std::vector<int>& freq);
};
#endif //AUTOCOMPLETESUGGESTION_SEARCHCOMPLETE_H