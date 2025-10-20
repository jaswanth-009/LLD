//
// Created by Jassvanthh Kunjeti on 20/10/25.
//

#ifndef LRUCACHE_LRUCACHE_H
#define LRUCACHE_LRUCACHE_H

#include <unordered_map>
#include <mutex>
#include "DoublyLinkedList.h"

class LRUCache {
    private:
        DoublyLinkedList* dll;
        std::unordered_map<int, Node*> values;
        int capacity;
        std::mutex mtx;
    public:
        LRUCache(int capacity);
        void put(int key, int value);
        int get(int key);
        void removeLruNode();
        void printCache();
};

#endif //LRUCACHE_LRUCACHE_H