#include <iostream>
#include "DoublyLinkedNode.h"

using namespace std;

class DoublyLinkedList {

  private:
	DoublyLinkedNode* head;
	DoublyLinkedNode* tail;

  public:
	DoublyLinkedList() { // Creates an empty list
	  head = nullptr; // Initialize to NULL
	  tail = nullptr;
	}

	DoublyLinkedList(DoublyLinkedList &old_list); // Copy Constructor NEED TO IMPLEMENT

	~DoublyLinkedList() { // Destructor
	  DoublyLinkedNode* iterator = head;
	  while(iterator != nullptr) {
		DoublyLinkedNode* next = iterator->next;
		delete iterator;
		iterator = next;
	  }
	}

	DoublyLinkedList& operator=(DoublyLinkedList &rhs) { // Assignment operator NEED TO IMPLEMENT
	  if (this != &rhs) { // Check for self-assignment

	  }
	  return *this;
	}

	void insertFront(Channel new_data) { // Inserts data at front of list
		DoublyLinkedNode* iterator = new DoublyLinkedNode();
		iterator->data = new_data;
		iterator->prev = nullptr;

		if (head == nullptr) { // Case where list is empty
			head = iterator;
			tail = iterator;
			iterator = nullptr;
		}

	  else {
		head->prev = iterator;
		iterator->next = head;
		head = iterator;
	  }
	}

	void insertBack(Channel new_data) { // Inserts data at back of list
	  DoublyLinkedNode* iterator = new DoublyLinkedNode;
	  iterator->data = new_data;
	  iterator->next = nullptr; // Next is null because we are adding at the end

	  if (head == nullptr) { // Case where list is empty
		head = iterator;
		tail = iterator;
		iterator = nullptr;
	  }

	  else {
		tail->next = iterator;
		iterator->prev = tail;
		tail = iterator;
	  }
	}

	void removeFront() { // Removes data at front of list
	  if (size() == 0) {
		return; // Can't remove if there aren't any nodes
	  }

	  if (size() == 1) { // Need special case for one node left
		DoublyLinkedNode* iterator = head;
		delete iterator;
		head = nullptr;
		tail = nullptr;
	  }

	  else { // Normal deletion case
		DoublyLinkedNode* iterator = head;
		head = head->next;
		head->prev = nullptr;
		delete iterator;
	  }
	}

	void removeBack() { // Removes data at back of list
	  if (size() == 0) {
		return; // Can't remove if there aren't any nodes
	  }

	  if (size() == 1) { // Need special case for one node left
		DoublyLinkedNode* iterator = head;
		delete iterator;
		head = nullptr;
		tail = nullptr;
	  }

	  else { // Normal deletion case
		DoublyLinkedNode* iterator = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete iterator;
	  }
	}

    void removeIndex(int index) { // Removes data at given index
        if (size() == 0) {
            return; // Can't remove if there aren't any nodes
        }

        else if (index > size() - 1) {
            cerr << "List index out of range" << endl;
            exit(-1);
        }

        DoublyLinkedNode* iterator = head;

        if (iterator == tail) {
            removeBack();
            return;
        }

        else if (iterator == head) {
            removeFront();
            return;
        }

        for (int i = 0; i < index; i++) { // Move iterator to node we want to remove
            iterator = iterator->next;
        }

        iterator->prev->next = iterator->next; // Link up nodes before and after iterator
        iterator->next->prev = iterator->prev;

        delete iterator;
    }

	bool isEmpty() { // Test whether list is empty
	  if (head == 0) {
		return true; // list is empty if head and tail are NULL
	  }

	  return false;
	}

	Channel& getData(int index) { // Returns data at given index
	  if (index > size() - 1) {
		cerr << "List index out of range" << endl; // Case of incorrect index
		exit(-1);
	  }

	  DoublyLinkedNode* iterator = head;
	  for(int i = 0; i < index; i++) {
		iterator = iterator->next;
	  }

	  return iterator->data;
	}

	int size() { // Returns # of elements in list
	  DoublyLinkedNode* iterator = head;
	  int size = 0;

	  while(iterator != nullptr) {
		size += 1;
		iterator = iterator->next;
	  }

	  return size;
	}
};
