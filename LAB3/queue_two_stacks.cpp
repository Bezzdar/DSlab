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

    // Сначала выводим элементы из stack2 (в том порядке, как они уже готовятся к извлечению)
    StackNode* current = stack2.top;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }

    // Теперь создаём временный стек для инверсии stack1
    Stack tempStack;
    current = stack1.top;
    while (current) {
        tempStack.Push(current->data);
        current = current->next;
    }

    // Выводим элементы из временного стека, чтобы они были в правильном порядке
    current = tempStack.top;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << "\n";
}

