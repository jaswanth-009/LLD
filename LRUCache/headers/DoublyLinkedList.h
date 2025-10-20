//
// Created by Jassvanthh Kunjeti on 20/10/25.
//

#ifndef LRUCACHE_DOUBLYLINKEDLIST_H
#define LRUCACHE_DOUBLYLINKEDLIST_H

#include "Node.h"

class DoublyLinkedList {
private:
        Node* head;
        Node* tail;
        int size;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        void addNode(Node* newNode);
        void removeNode(Node* removedNode);
        Node* getLastNode() const;
        void removeLastNode();
        void printDLL() const;
        Node* getHead() const;
        int getSize() const;
};

#endif //LRUCACHE_DOUBLYLINKEDLIST_H