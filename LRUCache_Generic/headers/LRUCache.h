//
// Created by Jassvanthh Kunjeti on 26/10/25.
//

#ifndef LRUCACHE_GENERIC_LRUCACHE_H
#define LRUCACHE_GENERIC_LRUCACHE_H

#include <unordered_map>

#include "DoublyLinkedList.h"

template<typename K, typename V>
class LRUCache {
private:
    int capacity;
    DoublyLinkedList<K, V>* dll;
    std::unordered_map<K, Node<K, V>*> values{};
    std::mutex m;
public:
    LRUCache(int capacity);
    V getValue(K key);
    void put(K key, V value);
    int getSize();
    void printCache();
    ~LRUCache();
};

template<typename K, typename V>
LRUCache<K, V>::LRUCache(int capacity) {
    this->capacity = capacity;
    dll = new DoublyLinkedList<K, V>();
}

template<typename K, typename V>
int LRUCache<K, V>::getSize() {
    std::lock_guard<std::mutex> lock(m);
    return dll->getSize();
}

template<typename K, typename V>
void LRUCache<K, V>::put(K key, V value) {
    std::lock_guard<std::mutex> lock(m);
    if (values.find(key) != values.end()) {
        Node<K, V>* node = values.at(key);
        node->updateValue(value);
        dll->moveNodeToFront(node);
        return;
    }

    Node<K, V>* node = new Node<K, V>(key, value);

    if (dll->getSize() >= capacity) {
        Node<K, V>* lastNode = dll->getLastNode();
        K key = lastNode->getKey();
        values.erase(key);
        dll->removeLastNode();
    }

    values[key] = node;
    dll->addNodeAtFront(node);
}

template<typename K, typename V>
V LRUCache<K, V>::getValue(K key) {

    if (values.find(key) == values.end()) {
        return V{};
    }

    Node<K, V>* node = values.at(key);
    V value = node->getValue();

    dll->moveNodeToFront(node);
    return value;
}

template<typename K, typename V>
void LRUCache<K, V>::printCache() {
    dll->print();
}

template<typename K, typename V>
LRUCache<K, V>::~LRUCache() {
    delete dll;
}



#endif //LRUCACHE_GENERIC_LRUCACHE_H