#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <iostream>

class RingBuffer {
private:
    int* buffer;
    int capacity;
    int start;
    int end;
    int count;

public:
    RingBuffer(int cap);
    ~RingBuffer();

    void Add(int value);
    int Remove();
    int GetFreeSpace() const;
    int GetOccupiedSpace() const;
    bool IsFull() const;
    bool IsEmpty() const;
    void Display() const;
};

#endif // RING_BUFFER_H
