#pragma once
#include "List.hpp"

template <typename T>
class SingleLinkedList : public List<T> {
private:
	struct Node {
		T dane;
		Node* next;

		Node(const T& node_data);
	};

	Node* head;
	Node* tail;
	size_t _size;
	void clear();

public:
	SingleLinkedList();
	~SingleLinkedList();

	void push_end(const T& value);
	void push_front(const T& value);
	void push_random(const T& value);
	void find_random(const T& value);

	bool pop_front();
};

