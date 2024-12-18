#ifndef QUEUE_STACKS_H
#define QUEUE_STACKS_H

#include "Stack.h"

class QueueStacks {
public:
    QueueStacks();
    ~QueueStacks();

    void enqueue(int value); // Добавление элемента в очередь
    int dequeue();           // Извлечение элемента из очереди

    void print() const;      // Вывод содержимого очереди

private:
    Stack inputStack;        // Входной стек
    Stack outputStack;       // Выходной стек

    void transfer();         // Перенос элементов из входного стека в выходной
};

#endif 
