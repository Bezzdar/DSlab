#ifndef LISTITEM_H
#define LISTITEM_H

struct ListItem {
    int Data;
    ListItem* Next;
    ListItem* Prev;

    ListItem(int value) : Data(value), Next(nullptr), Prev(nullptr) {}
};

#endif 
