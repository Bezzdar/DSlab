#include "queue_two_stacks.h"
#include <iostream>

QueueTwoStacks::QueueTwoStacks() {}

void QueueTwoStacks::TransferStack1ToStack2() {
    while (!stack1.IsEmpty()) {
        stack2.Push(stack1.Pop());
    }
}

void QueueTwoStacks::Enqueue(int value) {
    stack1.Push(value);
}

int QueueTwoStacks::Dequeue() {
    if (stack2.IsEmpty()) {
        TransferStack1ToStack2();
    }
    return stack2.Pop();
}

void QueueTwoStacks::Display() const {
    std::cout << "Queue elements: ";

    StackNode* current = stack2.top; // указатель на верхнем элементе
    while (current) { //пока current не равен nullptr
        std::cout << current->data << " ";
        current = current->next; //переход к следующему узлу
    }

    Stack tempStack; //cоздается временный стек
    current = stack1.top; //указатель на верхнем элементе
    while (current) {
        tempStack.Push(current->data); //инвертирование методом пуш
        current = current->next; 
    }

    current = tempStack.top; // указатель на верхнем элементе
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << "\n";
}

