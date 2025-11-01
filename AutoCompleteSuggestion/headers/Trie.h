//
// Created by Jassvanthh Kunjeti on 01/11/25.
//

#ifndef AUTOCOMPLETESUGGESTION_TRIE_H
#define AUTOCOMPLETESUGGESTION_TRIE_H

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

struct Trie {
    int frequency;
    std::string word;
    std::vector<Trie *> children;

    Trie() {
        frequency = 0;
        word = "";
        children.resize(27);

        for (int i  = 0; i < 27; i++) {
            children[i] = nullptr;
        }
    }
};

static inline void insert(std::string& word, Trie *root, int freq) {
    std::cout << "Inserting: " << word << "\n";
    Trie *cur = root;

    for (int i = 0; i < word.length(); i++) {
        int idx = -1;
        if (word[i] == ' ') idx = 26;
        else idx = word[i] - 'a';

        if (cur->children[idx] == nullptr) {
            cur->children[idx] = new Trie();
        }
        cur = cur->children[idx];
    }

    cur->word = word;
    cur->frequency += freq;
}

struct TrieComparator {
        bool operator()(const Trie* a, const Trie* b) {
            // ascending a < b -> true -> no swap
            int f1 = a->frequency;
            int f2 = b->frequency;

            if (f1 < f2) return false;
            return true;
        }
};
#endif //AUTOCOMPLETESUGGESTION_TRIE_H