//
// Created by Jassvanthh Kunjeti on 26/10/25.
//

#ifndef LRUCACHE_GENERIC_DOUBLYLINKEDLIST_H
#define LRUCACHE_GENERIC_DOUBLYLINKEDLIST_H

#include "Node.h"

template<typename K, typename V>
class DoublyLinkedList {
private:
        Node<K, V>* head;
        Node<K, V>* tail;
        int size;

    public:
        DoublyLinkedList();
        void addNodeAtFront(Node<K, V>* node);
        void moveNodeToFront(Node<K, V>* node);
        void removeLastNode();
        Node<K, V>* getLastNode();
        int getSize();
        void print();
        ~DoublyLinkedList();
};

template<typename K, typename V>
DoublyLinkedList<K, V>::DoublyLinkedList() {
    this->head = new Node<K, V>();
    this->tail = new Node<K, V>();

    this->head->setNext(this->tail);
    this->tail->setPrev(this->head);

    this->head->setPrev(nullptr);
    this->tail->setNext(nullptr);

    this->size = 0;
}

template<typename K, typename V>
void DoublyLinkedList<K, V>::addNodeAtFront(Node<K, V> *node) {

    Node<K, V>* nextNode = this->head->getNext();

    node->setNext(nextNode);
    node->setPrev(this->head);

    this->head->setNext(node);
    nextNode->setPrev(node);
    this->size++;
}

template<typename K, typename V>
void DoublyLinkedList<K, V>::moveNodeToFront(Node<K, V> *node) {

    Node<K, V>* nextNode = node->getNext();
    Node<K, V>* prevNode = node->getPrev();

    prevNode->setNext(nextNode);
    nextNode->setPrev(prevNode);

    this->size--;
    addNodeAtFront(node);
}

template<typename K, typename V>
void DoublyLinkedList<K, V>::removeLastNode() {
    Node<K, V>* lastNode = this->tail->getPrev();
    Node<K, V>* prevNode = lastNode->getPrev();

    prevNode->setNext(this->tail);
    this->tail->setPrev(prevNode);

    this->size--;
    delete lastNode;
}

template<typename K, typename V>
int DoublyLinkedList<K, V>::getSize() {
    return this->size;
}

template<typename K, typename V>
Node<K, V> *DoublyLinkedList<K, V>::getLastNode() {
    if (this->size == 0) return nullptr;
    return this->tail->getPrev();
}

template<typename K, typename V>
void DoublyLinkedList<K, V>::print() {
    if (this->size == 0) {
        std::cout << "Empty Cache\n";
        return;
    }
    Node<K, V> *node = this->head->getNext();

    while (node != this->tail) {
        std::cout << node->getKey() << " " << node->getValue() << "\n";
        node = node->getNext();
    }
}

template<typename K, typename V>
DoublyLinkedList<K, V>::~DoublyLinkedList() {

    if (this->size > 0) {
        Node<K, V>* cur = this->head->getNext();

        while (cur != this->tail) {
            Node<K, V>* next = cur->getNext();
            delete cur;
            cur = next;
        }
    }

    delete this->head;
    delete this->tail;

}


#endif //LRUCACHE_GENERIC_DOUBLYLINKEDLIST_H