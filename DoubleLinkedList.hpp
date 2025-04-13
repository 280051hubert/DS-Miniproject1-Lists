#pragma once
#include "List.hpp"

template <typename T>
class DoubleLinkedList : public List<T>
{
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(T val, Node* p = nullptr, Node* n = nullptr) : data(val), prev(p), next(n) {}
    };

    Node* head;
    Node* tail;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    size_t size() override;
    bool isEmpty() override;
    size_t search(T elem) override;
    T atIndex(size_t index) override;

    void add(T elem, size_t index) override;
    void addFront(T elem) override;
    void addBack(T elem) override;

    T popBack() override;
    T popFront() override;
    T pop() override;

private:
    Node* getNode(size_t index);
    void clear();
};
