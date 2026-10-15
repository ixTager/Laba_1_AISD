#include <iostream>
#pragma once
template <typename T>
class DoublyLinkedList {
public:
	struct Node {
		T* data;
		Node* prev;
		Node* next;

		Node(T* val) : data(val), prev(nullptr), next(nullptr) {}
	};

private:
	Node* head;

public:
	DoublyLinkedList() : head(nullptr) {}

	DoublyLinkedList(T* val) {
		this->head = new Node(val);
	}

	Node* getByIndex(int index) {
		int i = 0;
		Node* current = head;
		while (current != nullptr) {
			if (i == index) return current;
			i++;
			current = current->next;
		}
		return nullptr;
	}

	Node* getByVal(T* data) {
		Node* current = head;
		while (current != nullptr) {
			if (current->data == data) return current;
			current = current->next;
		}
		return nullptr;
	}

	void add(int index, T* data) {
		Node* newNode = new Node(data);

		if (head == nullptr) {
			head = newNode;
			return;
		}

		if (index == 0) {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		else {
			Node* current = getByIndex(index);

			if (current != nullptr) {
				newNode->next = current;
				newNode->prev = current->prev;
				if (current->prev != nullptr) {
					current->prev->next = newNode;
				}
				current->prev = newNode;
			}
			else {
				Node* last = head;
				while (last->next != nullptr) {
					last = last->next;
				}
				last->next = newNode;
				newNode->prev = last;
			}
		}
	}

	void remove(int index) {
		if (head == nullptr) return;

		if (index == 0) {
			Node* temp = head;
			head = head->next;
			if (head != nullptr) {
				head->prev = nullptr;
			}
			delete temp;
		}
		else {
			Node* toDelete = getByIndex(index);
			if (toDelete == nullptr) return;

			if (toDelete->next != nullptr) {
				toDelete->next->prev = toDelete->prev;
			}
			if (toDelete->prev != nullptr) {
				toDelete->prev->next = toDelete->next;
			}
			delete toDelete;
		}
	}

	~DoublyLinkedList() {
		while (head != nullptr) {
			remove(0);
		}
	}
};
