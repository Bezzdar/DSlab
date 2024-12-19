#ifndef STACK_H
#define STACK_H

struct StackNode {
    int Data;
    StackNode* next;
};



class Stack {
    friend class QueueTwoStacks; 

private:
    StackNode* _top;

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
