#include "stack.h"
#include <iostream>

Stack::Stack() : _top(nullptr) {}

Stack::~Stack() {
    Clear();
}

void Stack::Push(int value) {
    StackNode* newNode = new StackNode{ value, _top };
    _top = newNode;
}

int Stack::Pop() {
    if (IsEmpty()) {
        std::cerr << "Stack is empty!\n";
        return -1; 
    }
    int value = _top->Data;
    StackNode* temp = _top;
    _top = _top->next;
    delete temp;
    return value;
}

bool Stack::IsEmpty() const {
    return _top == nullptr;
}

void Stack::Clear() {
    while (!IsEmpty()) {
        Pop();
    }
}

void Stack::Display() const {
    StackNode* current = _top;
    std::cout << "Stack: ";
    while (current) {
        std::cout << current->Data << " ";
        current = current->next;
    }
    std::cout << "\n";
}
