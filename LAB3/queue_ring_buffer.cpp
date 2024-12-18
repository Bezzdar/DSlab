#include "queue_ring_buffer.h"

QueueRingBuffer::QueueRingBuffer(int initial_capacity)
    : buffer(initial_capacity) {}

void QueueRingBuffer::Enqueue(int value) {
    buffer.Add(value);
}

int QueueRingBuffer::Dequeue() {
    return buffer.Remove();
}

void QueueRingBuffer::Display() const {
    buffer.Display();
}
