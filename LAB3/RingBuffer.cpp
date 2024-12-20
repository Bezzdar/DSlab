#include "RingBuffer.h"
#include <chrono>
#include <thread>

RingBuffer::RingBuffer(int cap) : _capacity(cap), _start(0), _end(0), _count(0) {
    _buffer = new int[_capacity];
}

RingBuffer::~RingBuffer() {
    delete[] _buffer;
}

void RingBuffer::Add(int value) {
    if (IsFull()) {
        std::cerr << "Buffer is full! Cannot add more elements.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return;
    }

    _buffer[_end] = value;
    _end = (_end + 1) % _capacity; 
    _count++;
}

int RingBuffer::Remove() {
    if (IsEmpty()) {
        std::cerr << "Buffer is empty! Cannot remove elements.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return -1; 
    }

    int value = _buffer[_start];
    _start = (_start + 1) % _capacity; 
    _count--;
    return value;
}

int RingBuffer::GetFreeSpace() const {
    return _capacity - _count;
}

int RingBuffer::GetOccupiedSpace() const {
    return _count;
}

bool RingBuffer::IsFull() const {
    return _count == _capacity;
}

bool RingBuffer::IsEmpty() const {
    return _count == 0;
}

void RingBuffer::Display() const {

    for (int i = 0; i < _count; ++i) {
        std::cout << _buffer[(_start + i) % _capacity] << " ";
    }
    std::cout << "\n";
}

void RingBuffer::Overwrite(int value) {
    if (IsFull()) {
        _buffer[_start] = value;
        _start = (_start + 1) % _capacity; 
    }
    else {
        
        Add(value);
    }
}


