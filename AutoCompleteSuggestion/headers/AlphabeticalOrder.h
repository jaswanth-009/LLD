//
// Created by Jassvanthh Kunjeti on 01/11/25.
//

#ifndef AUTOCOMPLETESUGGESTION_ALPHABETICALORDER_H
#define AUTOCOMPLETESUGGESTION_ALPHABETICALORDER_H
#include "LookUpStrategy.h"

class AlphabeticalOrder: public LookUpStrategy {
    public:
        std::vector<std::string> TopKMatches(const std::string& key, Trie* root, int k) override;
        void DFS(const std::string& key, Trie* root, std::vector<std::string>& result, int& k);
};
#endif //AUTOCOMPLETESUGGESTION_ALPHABETICALORDER_H