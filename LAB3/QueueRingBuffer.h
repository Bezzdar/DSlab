#ifndef QUEUE_RING_BUFFER_H
#define QUEUE_RING_BUFFER_H

#include "RingBuffer.h"

class QueueRingBuffer {
private:
    RingBuffer buffer; 

public:
    QueueRingBuffer(int initial_capacity = 10);
    void Enqueue(int value);
    int Dequeue();
    void Display() const;
};

#endif 
