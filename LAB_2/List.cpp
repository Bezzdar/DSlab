#include "List.h"
#include "ListItem.h"
#include <iostream>
#include <algorithm>
#include <vector>

List::List() : _head(nullptr), _tail(nullptr), _size(0) {}

List::~List() {
    ListItem* current = _head;
    while (current) {
        ListItem* Next = current->Next;
        delete current;
        current = Next;
    }
}

void List::Add(int value) {
    ListItem* newItem = new ListItem(value);
    if (!_tail) {
        _head = _tail = newItem;
    }
    else {
        _tail->Next = newItem;
        newItem->Prev = _tail;
        _tail = newItem;
    }
    ++_size;
}

void List::Remove(int value) {
    ListItem* current = _head;
    while (current) {
        if (current->Data == value) {
            if (current->Prev) current->Prev->Next = current->Next;
            if (current->Next) current->Next->Prev = current->Prev;
            if (current == _head) _head = current->Next;
            if (current == _tail) _tail = current->Prev;

            delete current;
            --_size;
            return;
        }
        current = current->Next;
    }
}

void List::InsertAtBeginning(int value) {
    ListItem* newItem = new ListItem(value);
    if (!_head) {
        _head = _tail = newItem;
    }
    else {
        newItem->Next = _head;
        _head->Prev = newItem;
        _head = newItem;
    }
    ++_size;
}

void List::InsertAtEnd(int value) {
    Add(value);
}

void List::InsertAfter(int afterValue, int newValue) {
    int index = Find(afterValue);
    if (index == -1) return;

    ListItem* current = GetItemByIndex(index);
    ListItem* newItem = new ListItem(newValue);
    newItem->Next = current->Next;
    newItem->Prev = current;
    if (current->Next) current->Next->Prev = newItem;
    current->Next = newItem;
    if (current == _tail) _tail = newItem;
    ++_size;
}

void List::InsertBefore(int beforeValue, int newValue) {
    int index = Find(beforeValue);
    if (index == -1) return;

    ListItem* current = GetItemByIndex(index);
    ListItem* newItem = new ListItem(newValue);
    newItem->Next = current;
    newItem->Prev = current->Prev;
    if (current->Prev) current->Prev->Next = newItem;
    current->Prev = newItem;
    if (current == _head) _head = newItem;
    ++_size;
}

void List::Sort() {
    if (_size <= 1) return;

    std::vector<int> values;
    ListItem* current = _head;
    while (current) {
        values.push_back(current->Data);
        current = current->Next;
    }

    std::sort(values.begin(), values.end());

    current = _head;
    for (int value : values) {
        current->Data = value;
        current = current->Next;
    }
}

int List::Find(int value) {
    ListItem* current = _head;
    int index = 0;

    while (current) {
        if (current->Data == value) {
            return index;
        }
        current = current->Next;
        index++;
    }

    return -1;
}

ListItem* List::GetItemByIndex(int index) {
    if (index < 0 || index >= _size) return nullptr;

    ListItem* current = _head;
    for (int i = 0; i < index; i++) {
        current = current->Next;
    }

    return current;
}


void List::Print() const {
    ListItem* current = _head;
    while (current) {
        std::cout << current->Data << " ";
        current = current->Next;
    }
    std::cout << "\n";
}

size_t List::GetSize() const {
    return _size;
}
