//
// Created by Jassvanthh Kunjeti on 20/10/25.
//

#include "headers/DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() {
    this->head = new Node(-1, -1);
    this->tail = new Node(-1, -1);

    this->head->setNext(this->tail);
    this->tail->setPrev(this->head);

    this->size = 0;
}

void DoublyLinkedList::addNode(Node *newNode) {
    Node* nextNode = this->head->getNext();

    newNode->setNext(nextNode);
    nextNode->setPrev(newNode);

    newNode->setPrev(this->head);
    this->head->setNext(newNode);

    this->size++;
}

void DoublyLinkedList::removeNode(Node *node) {
    Node* nextNode = node->getNext();
    Node* prevNode = node->getPrev();

    prevNode->setNext(nextNode);
    nextNode->setPrev(prevNode);

    delete node;
    this->size--;
}

Node* DoublyLinkedList::getHead() const {
    return this->head;
}

void DoublyLinkedList::printDLL() const {
    Node* currentNode = this->head;

    if (currentNode->getNext() == this->tail) {
        std::cout << "DLL is empty\n";
        return;
    }

    currentNode = currentNode->getNext();
    std::cout << "Contents of Cache are:\n";

    while (currentNode != this->tail) {
        std::cout << currentNode->getKey() << " " << currentNode->getValue() << "\n";
        currentNode = currentNode->getNext();
    }
}

void DoublyLinkedList::removeLastNode() {
    Node* lastNode = this->tail->getPrev();

    if (lastNode == this->head) {
        std::cout << "DLL is empty\n";
        return;
    }

    Node* prevNode = lastNode->getPrev();
    Node* nextNode = lastNode->getNext();

    prevNode->setNext(nextNode);
    nextNode->setPrev(prevNode);
    delete lastNode;
    this->size--;
}

Node* DoublyLinkedList::getLastNode() const {
    return this->tail->getPrev();
}

DoublyLinkedList::~DoublyLinkedList() {
    Node* currentNode = this->head;

    while (currentNode != this->tail) {
        Node* nextNode = currentNode->getNext();
        delete currentNode;
        currentNode = nextNode;
    }

    delete head;
    delete tail;
}

int DoublyLinkedList::getSize() const {
    return this->size;
}
