#pragma once
#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    explicit Node(T data) : data(data), next(nullptr){}
};

template <typename T>
class Stack {
private:
    Node<T> *top_node;
public:
    Stack();
    ~Stack();
    void push(const T &value);
    void pop();
    T &top();
    void clear();
    [[nodiscard]] bool empty() const;
    [[nodiscard]] size_t size() const;
    bool find_element(T element);
    void sort();

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Stack<U>& stack);
};

#include "../src/classes/stack.inl"