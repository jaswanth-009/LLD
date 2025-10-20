//
// Created by Jassvanthh Kunjeti on 20/10/25.
//

#include "headers/LRUCache.h"

#include <iostream>
#include <ostream>

LRUCache::LRUCache(int capacity) {
    if (capacity < 1) {
        throw std::invalid_argument("capacity must be >= 1");
    }
    this->capacity = capacity;
    dll = new DoublyLinkedList();
}

int LRUCache::get(int key) {
    if (values.find(key) == values.end()) {
        std::cout << "Given key: " << key << " Not found! ";
        return -1;
    }

    std::lock_guard<std::mutex> l(mtx);

    Node* n = values[key];
    int value = n->getValue();

    dll->removeNode(n);
    values.erase(key);

    Node* newNode = new Node(key, value);
    dll->addNode(newNode);
    values[key] = newNode;

    return value;
}

void LRUCache::removeLruNode() {
    Node* lruNode = dll->getLastNode();
    values.erase(lruNode->getKey());
    dll->removeLastNode();
}

void LRUCache::put(int key, int value) {
    std::lock_guard<std::mutex> l(mtx);

    if (values.find(key) != values.end()) {
        Node* node = values[key];
        dll->removeNode(node);
        values.erase(key);

        Node* newNode = new Node(key, value);
        dll->addNode(newNode);
        values[key] = newNode;
        return;
    }

    int dllCapacity = dll->getSize();

    std::cout << "For [" << key << "," << value << "], capacity: " << dllCapacity << "\n";
    if (dllCapacity >= this->capacity) {
        removeLruNode();
    }

    Node* newNode = new Node(key, value);
    dll->addNode(newNode);
    values[key] = newNode;
}

void LRUCache::printCache() {
    std::lock_guard<std::mutex> l(mtx);
    dll->printDLL();
}