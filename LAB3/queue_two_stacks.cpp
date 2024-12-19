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

    StackNode* current = stack2._top; // ��������� �� ������� ��������
    while (current) { //���� current �� ����� nullptr
        std::cout << current->Data << " ";
        current = current->next; //������� � ���������� ����
    }

    Stack tempStack; //c�������� ��������� ����
    current = stack1._top; //��������� �� ������� ��������
    while (current) {
        tempStack.Push(current->Data); //�������������� ������� ���
        current = current->next; 
    }

    current = tempStack._top; // ��������� �� ������� ��������
    while (current) {
        std::cout << current->Data << " ";
        current = current->next;
    }

    std::cout << "\n";
}

