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
    std::cout << "Queue elements (as one set): ";

    // ������� ������� �������� �� stack2 (� ��� �������, ��� ��� ��� ��������� � ����������)
    StackNode* current = stack2.top;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }

    // ������ ������ ��������� ���� ��� �������� stack1
    Stack tempStack;
    current = stack1.top;
    while (current) {
        tempStack.Push(current->data);
        current = current->next;
    }

    // ������� �������� �� ���������� �����, ����� ��� ���� � ���������� �������
    current = tempStack.top;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << "\n";
}

