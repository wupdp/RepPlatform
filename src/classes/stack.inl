#include <iostream>
#include "../../include/stack.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnreachableCode"
template<typename T>
Stack<T>::Stack() : top_node(nullptr) {}

template<typename T>
Stack<T>::~Stack() {
    while (!empty()) {
        pop();
    }
}

template<typename T>
void Stack<T>::push(const T &value) {
    auto newNode = new Node<T>(value);
    newNode->next = top_node;
    top_node = newNode;
}

template<typename T>
void Stack<T>::pop() {
    if (!empty()) {
        Node<T> *temp = top_node;
        top_node = top_node->next;
        delete temp;
    } else {
        std::cerr << "Stack is empty. Cannot pop." << std::endl;
    }
}

template<typename T>
T& Stack<T>::top() {
    if (!empty()) {
        return top_node->data;
    } else {
        throw std::out_of_range("Stack is empty. Cannot get top.");
    }
}

template<typename T>
[[nodiscard]] bool Stack<T>::empty() const {
    return top_node == nullptr;
}

template<typename T>
size_t Stack<T>::size() const {
    size_t count = 0;
    Node<T> *current = top_node;
    while (current != nullptr) {
        ++count;
        current = current->next;
    }
    return count;
}

template<typename T>
void Stack<T>::clear() {
    while (!empty()) {
        pop();
    }
}

template<typename T>
bool Stack<T>::find_element(T element) {
    Node<T> *node = top_node;
    while (node != NULL) {
        if (node->data == element)
            return true;
        node = node->next;
    }
    return false;
}

template<typename T>
void Stack<T>::sort() {
    if (empty() || size() == 1) {
        return;
    }

    bool swapped;
    Node<T> *current;
    Node<T> *temp = nullptr;
    do {
        swapped = false;
        current = top_node;

        while (current->next != temp) {
            if (current->data > current->next->data) {
                std::swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
        temp = current;
    } while (swapped);
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Stack<T> &stack) {
    Node<T> *current = stack.top_node;

    while (current != nullptr) {
        os << current->data << " ";
        current = current->next;
    }

    return os;
}
#pragma clang diagnostic pop