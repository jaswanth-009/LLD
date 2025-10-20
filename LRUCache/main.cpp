#include <iostream>

#include "headers/LRUCache.h"

int main() {

    LRUCache* cache = new LRUCache(3);

    cache->printCache();

    cache->put(1, 2);
    cache->put(2, 3);
    cache->put(4, 5);

    cache->printCache();

    std::cout << "Get value for 1: " << cache->get(1) << "\n";
    std::cout << "Get value for 2: " <<  cache->get(2) << "\n";


    cache->printCache();

    cache->put(5, 6);
    cache->put(1, 10);

    std::cout << "Get value for 4: " << cache->get(4) << "\n";

    cache->printCache();

    delete cache;
    return 0;
}