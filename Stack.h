#pragma once
#include <iostream>
#include "DoublyLinkedList.h"

template <typename T>
class Stack {
private :
	DoublyLinkedList<T> list;
	int capacity;

public:
	Stack() : capacity(0) {}
	
	void push(T* val) {
		list.add(0, val);
		capacity++;
	}

	void pop() {
		if (isEmpty()) return;

		list.remove(0);
		capacity--;
	}

	T* getFirstElement() {
		if (isEmpty()) return nullptr;

		auto top = list.getByIndex(0);
		return top->data;
	}

	bool isEmpty() {
		return capacity == 0 ? true : false;
	}

	int size() { return capacity; }

};