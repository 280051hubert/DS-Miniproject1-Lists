#include "SingleLinkedList.hpp"
#include <cstdlib>
#include <ctime>
#include <cstdint>
#include <iostream>

template <typename T>
SingleLinkedList<T>::Node::Node(const T& node_data) : dane(node_data), next(nullptr) {}

template <typename T>
SingleLinkedList<T>::SingleLinkedList() : head(nullptr), tail(nullptr), _size(0) {}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList() 
{
	clear();
}

template <typename T>
void SingleLinkedList<T>::push_end(const T& value)
{
	Node* newN = new Node(value);
	if (!head) {
		head = newN;
		tail = newN;
	}
	else {
		tail->next = newN;
		tail = newN;

	} ++_size;
}

template<typename T>
void SingleLinkedList<T>::push_front(const T& value)
{
	Node* newN = new Node(value);
	newN->next = head;
	head = newN;
	if (!tail) {
		tail = head;
	} ++_size;
}

template<typename T>
bool SingleLinkedList<T>::pop_front()
{
	if (!head) return false;
	Node* temp_pointer = head;
	head = head->next;
	delete temp_pointer;
	--_size;
	if (!head) tail = nullptr;
	return true;
}

template<typename T>
void SingleLinkedList<T>::push_random(const T& value)
{
	int index = std::rand() % (_size + 1);
	if (index == 0) {
		push_front(value);
	}
	else if (index == _size) {
		push_end(value);
	}
	else {
		Node* newN = new Node(value);
		Node* current = head;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		newN->next = current->next;
		current->next = newN;
		++_size;
	}
}

template<typename T>
void SingleLinkedList<T>::find_random(const T& value) {

	uint32_t random_value = static_cast<uint32_t>(std::rand());
	Node* current = head;
	bool has_found = false;
	while (current) {
		if (static_cast<uint32_t>(current->dane) == random_value) {
			has_found = true;
			break;
		} current = current->next;
	}
	if (has_found) {
		std::cout << "Operation successfull.";
	}
	else {
		std::cout << "Operation failed";
	}
}
