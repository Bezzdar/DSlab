#include "ring_buffer.h"
#include <iostream>
#include <cstring>

RingBuffer::RingBuffer(int initial_capacity)
    : capacity(initial_capacity), head(0), tail(0), size(0) {
    buffer = new int[capacity];
}

RingBuffer::~RingBuffer() {
    delete[] buffer;
}

void RingBuffer::Resize() {
    int new_capacity = capacity * 2;
    int* new_buffer = new int[new_capacity];

    for (int i = 0; i < size; ++i) {
        new_buffer[i] = buffer[(head + i) % capacity];
    }

    delete[] buffer;
    buffer = new_buffer;
    capacity = new_capacity;
    head = 0;
    tail = size;
}

void RingBuffer::Add(int value) {
    if (size == capacity) {
        Resize();
    }
    buffer[tail] = value;
    tail = (tail + 1) % capacity;
    ++size;
}

int RingBuffer::Remove() {
    if (size == 0) {
        std::cerr << "Ring buffer is empty!\n";
        return -1; // Error code
    }
    int value = buffer[head];
    head = (head + 1) % capacity;
    --size;
    return value;
}

int RingBuffer::GetFreeSpace() const {
    return capacity - size;
}

int RingBuffer::GetOccupiedSpace() const {
    return size;
}

void RingBuffer::Display() const {
    std::cout << "Ring Buffer: ";
    for (int i = 0; i < size; ++i) {
        std::cout << buffer[(head + i) % capacity] << " ";
    }
    std::cout << "\n";
}
