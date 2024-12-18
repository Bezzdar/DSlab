#include "ring_buffer.h"
#include <iostream>
#include <stdexcept>

RingBuffer::RingBuffer(int size)
    : buffer(new int[size]), head(0), tail(0), capacity(size), count(0) {}

RingBuffer::~RingBuffer() {
    delete[] buffer;
}

void RingBuffer::add(int value) {
    if (count == capacity) {
        throw std::runtime_error("Buffer is full!");
    }
    buffer[tail] = value;
    tail = (tail + 1) % capacity;
    count++;
}

int RingBuffer::get() {
    if (count == 0) {
        throw std::runtime_error("Buffer is empty!");
    }
    int value = buffer[head];
    head = (head + 1) % capacity;
    count--;
    return value;
}

int RingBuffer::freeSpace() const {
    return capacity - count;
}

int RingBuffer::usedSpace() const {
    return count;
}

void RingBuffer::print() const {
    for (int i = 0, idx = head; i < count; i++, idx = (idx + 1) % capacity) {
        std::cout << buffer[idx] << " ";
    }
    std::cout << std::endl;
}
