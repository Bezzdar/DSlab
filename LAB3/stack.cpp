#include "stack.h"
#include <iostream>

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    Clear();
}

void Stack::Push(int value) {
    StackNode* newNode = new StackNode{ value, top };
    top = newNode;
}

int Stack::Pop() {
    if (IsEmpty()) {
        std::cerr << "Stack is empty!\n";
        return -1; // Error code
    }
    int value = top->data;
    StackNode* temp = top;
    top = top->next;
    delete temp;
    return value;
}

bool Stack::IsEmpty() const {
    return top == nullptr;
}

void Stack::Clear() {
    while (!IsEmpty()) {
        Pop();
    }
}

void Stack::Display() const {
    StackNode* current = top;
    std::cout << "Stack: ";
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}
