#ifndef RING_BUFFER_H
#define RING_BUFFER_H

class RingBuffer {
public:
    RingBuffer(int size);
    ~RingBuffer();

    void add(int value);
    int get();
    int freeSpace() const;
    int usedSpace() const;

    void print() const;

private:
    int* buffer;
    int head;
    int tail;
    int capacity;
    int count;
};

#endif // RING_BUFFER_H
