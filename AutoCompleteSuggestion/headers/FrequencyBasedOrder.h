//
// Created by Jassvanthh Kunjeti on 01/11/25.
//

#ifndef AUTOCOMPLETESUGGESTION_FREQUENCYBASEDORDER_H
#define AUTOCOMPLETESUGGESTION_FREQUENCYBASEDORDER_H
#include "LookUpStrategy.h"

class FrequencyBasedOrder: public LookUpStrategy {
public:
    std::vector<std::string> TopKMatches(const std::string& key, Trie* root, int k) override;
    void DFS(const std::string& key, Trie* root, std::priority_queue<Trie*, std::vector<Trie*>, TrieComparator>& pq, int& k);
};

#endif //AUTOCOMPLETESUGGESTION_FREQUENCYBASEDORDER_H
