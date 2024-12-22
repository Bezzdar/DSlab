#ifndef TREAPNODE_H
#define TREAPNODE_H

#include <iostream>
struct TreapNode
{
    int start = 0;
    int end = 20;
    int x = rand() % (end - start + 1) + start;

    int Key;

    int Priority;

    TreapNode* Left;

    TreapNode* Right;

    TreapNode() : Key(-1), Priority(x), Left(nullptr), Right(nullptr) {}
    TreapNode(int key) : Key(key), Priority(x), Left(nullptr), Right(nullptr) {}
};
#endif