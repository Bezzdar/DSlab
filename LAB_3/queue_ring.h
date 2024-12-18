#ifndef QUEUE_RING_H
#define QUEUE_RING_H

#include "ring_buffer.h"

class QueueRing {
public:
    QueueRing(int size);

    void enqueue(int value);
    int dequeue();

    void print() const;

private:
    RingBuffer buffer;
};

#endif 
