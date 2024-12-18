#ifndef STACK_H
#define STACK_H

struct Node {
    int value;
    Node* next;
};

class Stack {
public:
    Stack();
    ~Stack();

    void push(int value);
    int pop();
    void clear();

    void print() const;
    bool isEmpty() const;

private:
    Node* top;


};

#endif // STACK_H
