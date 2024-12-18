#ifndef QUEUE_TWO_STACKS_H
#define QUEUE_TWO_STACKS_H

#include "stack.h"

class QueueTwoStacks {
private:
    Stack stack1;
    Stack stack2;

    void TransferStack1ToStack2();

public:
    QueueTwoStacks();
    void Enqueue(int value);
    int Dequeue();
    void Display() const;
};

#endif // QUEUE_TWO_STACKS_H
