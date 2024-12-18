#ifndef LIST_H
#define LIST_H

#include "ListItem.h"
#include <functional>

class List {
private:
    ListItem* _head;
    ListItem* _tail;
    size_t _size;

public:
    List();
    ~List();

    void Add(int value);
    void Remove(int value);
    void InsertAtBeginning(int value);
    void InsertAtEnd(int value);
    void InsertAfter(int afterValue, int newValue);
    void InsertBefore(int beforeValue, int newValue);
    void Sort();
    int Find(int value);
    ListItem* GetItemByIndex(int index);

    void Print() const;
    size_t GetSize() const;

    ListItem* GetHead() const { return _head; }
    ListItem* GetTail() const { return _tail; }
};

#endif 
