#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <iostream>

class RingBuffer {
private:
    int* _buffer;
    int _capacity;
    int _start;
    int _end;
    int _count;

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
    void Overwrite(int value); 
};

#endif // RING_BUFFER_H
