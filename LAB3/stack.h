#ifndef STACK_H
#define STACK_H

struct StackNode {
    int data;
    StackNode* next;
};

class Stack {
private:
    StackNode* top;

public:
    Stack();
    ~Stack();
    void Push(int value);
    int Pop();
    bool IsEmpty() const;
    void Clear();
    void Display() const;
};

#endif // STACK_H
