#ifndef RING_BUFFER_H
#define RING_BUFFER_H

class RingBuffer {
private:
    int* buffer;
    int capacity;
    int head;
    int tail;
    int size;

    void Resize();

public:
    RingBuffer(int initial_capacity = 10);
    ~RingBuffer();
    void Add(int value);
    int Remove();
    int GetFreeSpace() const;
    int GetOccupiedSpace() const;
    void Display() const;
};

#endif // RING_BUFFER_H
