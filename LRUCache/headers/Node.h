//
// Created by Jassvanthh Kunjeti on 20/10/25.
//

#ifndef LRUCACHE_NODE_H
#define LRUCACHE_NODE_H

class Node {
    private:
        int key;
        int value;
        Node* prev;
        Node* next;
    public:
        Node(int key, int value);
        void setNext(Node* next);
        Node* getNext() const;
        Node* getPrev() const;
        void setPrev(Node* prev);
        int getValue() const;
        int getKey() const;
};

#endif //LRUCACHE_NODE_H