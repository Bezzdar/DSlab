#include "queue_ring.h"

QueueRing::QueueRing(int size) : buffer(size) {}

void QueueRing::enqueue(int value) {
    buffer.add(value);
}

int QueueRing::dequeue() {
    return buffer.get();
}

void QueueRing::print() const {
    buffer.print();
}
