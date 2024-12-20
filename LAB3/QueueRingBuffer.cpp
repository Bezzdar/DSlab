#include "QueueRingBuffer.h"
#include <iostream>
#include <chrono>
#include <thread>

QueueRingBuffer::QueueRingBuffer(int initial_capacity)
    : buffer(initial_capacity) {}

void QueueRingBuffer::Enqueue(int value) {
    if (buffer.IsFull()) {
        std::cerr << "Queue is full! Cannot add more elements.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return;
    }

    buffer.Add(value);
}

int QueueRingBuffer::Dequeue() {
    return buffer.Remove();
}

void QueueRingBuffer::Display() const {
    buffer.Display();
}
