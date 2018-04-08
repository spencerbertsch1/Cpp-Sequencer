/*
Graeme Gengras
ENGS65 Project 5
DoublyLinkedNode.h

Implementation of a node for DoublyLinkedList
*/
#include "Channel.h"

class DoublyLinkedNode {
  public:
    // Make internal variables public so that DoublyLinkedList can access them
    // This is okay because nobody else will have access to this class
    Channel data;
    DoublyLinkedNode* next;
    DoublyLinkedNode* prev;

    DoublyLinkedNode() { // Creates an empty node
        next = nullptr;
        prev = nullptr;
    }

    DoublyLinkedNode(DoublyLinkedNode &old_node) { // Copy constructor
        data = old_node.data;
        next = old_node.next;
        prev = old_node.prev;
    }

    ~DoublyLinkedNode() {} // Destructor (don't need)

    DoublyLinkedNode& operator=(DoublyLinkedNode &rhs) { // Assignment operator
        if (this != &rhs) { // Check for self-assignment
            this->data = rhs.data;
            this->next = rhs.next;
            this->prev = rhs.prev;
        }

        return *this;
    }
};
