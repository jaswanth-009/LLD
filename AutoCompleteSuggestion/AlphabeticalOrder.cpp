//
// Created by Jassvanthh Kunjeti on 01/11/25.
//

#include "headers/AlphabeticalOrder.h"
#include <iostream>
std::vector<std::string> AlphabeticalOrder::TopKMatches(const std::string &key, Trie *root, int k) {
    std::cout << "Finding top matches for key: " << key << "\n";
    std::vector<std::string> result{};
    Trie* cur = root;

    for (int i = 0; i < key.size(); i++) {
        int idx = -1;
        if (key[i] == ' ') idx = 26;
        else idx = key[i] - 'a';
        if (cur->children[idx] == nullptr) return result;
        cur = cur->children[idx];
    }
    DFS(key, cur, result, k);
    return result;
}

void AlphabeticalOrder::DFS(const std::string& key, Trie *root, std::vector<std::string> &result, int& k) {
    if (k == 0) return;

    for (int i = 0; k > 0 && i < 27; i++) {
        if (root->children[i] != nullptr) {
            if (!root->children[i]->word.empty() && key != root->children[i]->word) {
                result.push_back(root->children[i]->word);
                k--;
            }
            DFS(key, root->children[i], result, k);
        }
    }
}

