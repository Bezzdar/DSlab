#ifndef NODE_H
#define NODE_H

#include <iostream>
struct Node
{
    int Data;

    Node* Left;

    Node* Right;

    Node() : Data(-1), Left(nullptr), Right(nullptr) {}
    Node(int data) : Data(data), Left(nullptr), Right(nullptr) {}
};
#endif