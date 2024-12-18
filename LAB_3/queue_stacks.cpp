#include "queue_stacks.h"
#include <iostream>
#include <stdexcept>

QueueStacks::QueueStacks() {}

QueueStacks::~QueueStacks() {}

void QueueStacks::enqueue(int value) {
    inputStack.push(value); // Добавляем элемент в входной стек
}

int QueueStacks::dequeue() {
    if (outputStack.pop()) {
        return outputStack.pop();
    }
    if (inputStack.pop()) {
        queue.QueueEnqueue();
    }
}


if (outputStack.isEmpty()) { // Если выходной стек пуст
    if (inputStack.isEmpty()) {
        throw std::runtime_error("Queue is empty!"); // Очередь пуста
    }
    transfer(); // Переносим элементы из входного стека в выходной
}
return outputStack.pop(); // Извлекаем элемент из выходного стека
}

void QueueStacks::print() const {
    std::cout << "Queue (front to back): ";
    // Вывод содержимого выходного стека
    outputStack.print();

    // Вывод содержимого входного стека (в обратном порядке)
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
