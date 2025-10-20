//
// Created by Jassvanthh Kunjeti on 20/10/25.
//

#include "headers/Node.h"

Node::Node(int key, int value) {
    this->key = key;
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}

int Node::getKey() const {
    return this->key;
}

int Node::getValue() const {
    return this->value;
}

void Node::setNext(Node* next) {
    this->next = next;
}

void Node::setPrev(Node* prev) {
    this->prev = prev;
}

Node* Node::getNext() const {
    return this->next;
}

Node* Node::getPrev() const {
    return this->prev;
}
