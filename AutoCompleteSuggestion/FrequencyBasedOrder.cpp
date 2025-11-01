//
// Created by Jassvanthh Kunjeti on 01/11/25.
//

#include "headers/FrequencyBasedOrder.h"
#include <iostream>

std::vector<std::string> FrequencyBasedOrder::TopKMatches(const std::string &key, Trie *root, int k) {
    std::cout << "Finding top K matches for key: " << key << "\n";
    std::vector<std::string> result;
    Trie* cur = root;

    for (int i = 0; i < key.size(); ++i) {
        int idx = -1;
        if (key[i] == ' ') idx = 26;
        else idx = key[i] - 'a';

        if (cur->children[idx] == NULL) {
            return result;
        }
        cur = cur->children[idx];
    }
    std::priority_queue<Trie*, std::vector<Trie*>, TrieComparator> pq{};
    DFS(key, cur, pq, k);
    while (!pq.empty()) {
        std::string word = pq.top()->word;
        pq.pop();
        result.insert(result.begin(), word);
    }
    return result;
}

void FrequencyBasedOrder::DFS(const std::string &key, Trie *root,
        std::priority_queue<Trie*, std::vector<Trie*>, TrieComparator>& pq, int &k) {
    if (k == 0) return;

    for (int i = 0; k > 0 && i < 27; i++) {
        if (root->children[i] != nullptr) {
            std::string word = root->children[i]->word;
            if (!word.empty() && word != key) {
                if (pq.size() < k) {
                    pq.push(root->children[i]);
                }
                else if (pq.top()->frequency < root->children[i]->frequency) {
                    pq.pop();
                    pq.push(root->children[i]);
                }
            }
            DFS(key, root->children[i], pq, k);
        }
    }
}

