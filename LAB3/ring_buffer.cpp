#include "ring_buffer.h"
#include <chrono>
#include <thread>

RingBuffer::RingBuffer(int cap) : capacity(cap), start(0), end(0), count(0) {
    buffer = new int[capacity];
}

RingBuffer::~RingBuffer() {
    delete[] buffer;
}

void RingBuffer::Add(int value) {
    if (IsFull()) {
        std::cerr << "Buffer is full! Cannot add more elements.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return;
    }

    buffer[end] = value;
    end = (end + 1) % capacity; 
    count++;
}

int RingBuffer::Remove() {
    if (IsEmpty()) {
        std::cerr << "Buffer is empty! Cannot remove elements.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return -1; 
    }

    int value = buffer[start];
    start = (start + 1) % capacity; 
    count--;
    return value;
}

int RingBuffer::GetFreeSpace() const {
    return capacity - count;
}

int RingBuffer::GetOccupiedSpace() const {
    return count;
}

bool RingBuffer::IsFull() const {
    return count == capacity;
}

bool RingBuffer::IsEmpty() const {
    return count == 0;
}

void RingBuffer::Display() const {
    std::cout << "Buffer content:\n";
    for (int i = 0; i < count; ++i) {
        std::cout << buffer[(start + i) % capacity] << " ";
    }
    std::cout << "\n";
}
