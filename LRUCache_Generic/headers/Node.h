//
// Created by Jassvanthh Kunjeti on 26/10/25.
//

#ifndef LRUCACHE_GENERIC_NODE_H
#define LRUCACHE_GENERIC_NODE_H
#include <mutex>
#include <iostream>

template<typename K, typename V>
class Node {
private:
    K key;
    V value;
    Node<K, V>* prev;
    Node<K, V> *next;

public:
    Node(K key, V val);
    Node();
    std::pair<K, V> getKeyAndValue();
    V getValue();
    K getKey();
    void updateValue(V val);
    Node<K, V>* getPrev();
    void setPrev(Node<K, V>* prev);
    Node<K, V>* getNext();
    void setNext(Node<K, V>* next);
};

template<typename K, typename V>
Node<K, V>::Node() {
    this->prev = nullptr;
    this->next = nullptr;
    std::cout << "Created an empty node\n";
}

template<typename K, typename V>
Node<K, V>::Node(K key, V val) {
    this->key = key;
    this->value = val;
    this->prev = nullptr;
    this->next = nullptr;
    std::cout << "Created node with key-value\n";
}

template<typename K, typename V>
std::pair<K, V> Node<K, V>::getKeyAndValue() {
    return std::make_pair(this->key, this->value);
}

template<typename K, typename V>
V Node<K, V>::getValue() {
    return this->value;
}

template<typename K, typename V>
void Node<K, V>::updateValue(V val) {
    this->value = val;
}

template<typename K, typename V>
Node<K, V> *Node<K, V>::getNext() {
    return this->next;
}

template<typename K, typename V>
Node<K, V> *Node<K, V>::getPrev() {
    return this->prev;
}

template<typename K, typename V>
void Node<K, V>::setNext(Node<K, V> *next) {
    this->next = next;
}

template<typename K, typename V>
void Node<K, V>::setPrev(Node<K, V> *prev) {
    this->prev = prev;
}

template<typename K, typename V>
K Node<K, V>::getKey() {
    return this->key;
}


#endif //LRUCACHE_GENERIC_NODE_H