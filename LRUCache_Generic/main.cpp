#include <iostream>
#include "headers/LRUCache.h"

int main() {

    LRUCache<int, int>* cache = new LRUCache<int, int>(3);

    cache->put(1, 2);
    cache->put(2, 3);
    cache->put(3, 4);

    cache->printCache();

    cache->put(1, 10);

    cache->printCache();

    delete cache;

    return 0;
}