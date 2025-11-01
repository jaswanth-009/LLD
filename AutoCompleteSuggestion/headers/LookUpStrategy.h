//
// Created by Jassvanthh Kunjeti on 01/11/25.
//

#ifndef AUTOCOMPLETESUGGESTION_LOOKUPSTRATEGY_H
#define AUTOCOMPLETESUGGESTION_LOOKUPSTRATEGY_H

#include <string>
#include <vector>

#include "Trie.h"

class LookUpStrategy {
public:
    virtual std::vector<std::string> TopKMatches(const std::string& key, Trie* root, int k) = 0;
};

#endif //AUTOCOMPLETESUGGESTION_LOOKUPSTRATEGY_H