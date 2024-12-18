#include "Stack.h"
#include <iostream>

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    clear();
}

void Stack::push(int value) {
    Node* newNode = new Node{ value, top };
    top = newNode;
}

int Stack::pop() {
    if (!top) {
        throw std::runtime_error("Stack is empty!");
    }
    Node* temp = top;
    int value = top->value;
    top = top->next;
    delete temp;
    return value;
}

void Stack::clear() {
    while (top) {
        pop();
    }
}

bool Stack::isEmpty() const {
    return top == nullptr; // Проверка на пустоту стека
}

void Stack::print() const {
    Node* current = top;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}



