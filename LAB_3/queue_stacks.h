#ifndef QUEUE_STACKS_H
#define QUEUE_STACKS_H

#include "Stack.h"

class QueueStacks {
public:
    QueueStacks();
    ~QueueStacks();

    void enqueue(int value); // ���������� �������� � �������
    int dequeue();           // ���������� �������� �� �������

    void print() const;      // ����� ����������� �������

private:
    Stack inputStack;        // ������� ����
    Stack outputStack;       // �������� ����

    void transfer();         // ������� ��������� �� �������� ����� � ��������
};

#endif // QUEUE_STACKS_H
