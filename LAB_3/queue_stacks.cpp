#include "queue_stacks.h"
#include <iostream>
#include <stdexcept>

QueueStacks::QueueStacks() {}

QueueStacks::~QueueStacks() {}

void QueueStacks::enqueue(int value) {
    inputStack.push(value); // ��������� ������� � ������� ����
}

int QueueStacks::dequeue() {
    if (outputStack.pop()) {
        return outputStack.pop();
    }
    if (inputStack.pop()) {
        queue.QueueEnqueue();
    }
}


if (outputStack.isEmpty()) { // ���� �������� ���� ����
    if (inputStack.isEmpty()) {
        throw std::runtime_error("Queue is empty!"); // ������� �����
    }
    transfer(); // ��������� �������� �� �������� ����� � ��������
}
return outputStack.pop(); // ��������� ������� �� ��������� �����
}

void QueueStacks::print() const {
    std::cout << "Queue (front to back): ";
    // ����� ����������� ��������� �����
    outputStack.print();

    // ����� ����������� �������� ����� (� �������� �������)
    Stack temp = inputStack;
    Stack reversedInput;
    while (!temp.isEmpty()) {
        reversedInput.push(temp.pop());
    }
    reversedInput.print();
}

void QueueStacks::transfer() {
    while (!inputStack.isEmpty()) {
        outputStack.push(inputStack.pop());
    }
}
