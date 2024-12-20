#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <list>
#include <iostream>

class Dictionary {
private:
    struct Entry {
        std::string key;
        std::string value;
    };

    std::vector<std::list<Entry>> table;
    size_t capacity;
    size_t size;
    static const size_t DEFAULT_CAPACITY = 8;
    static const double LOAD_FACTOR;

    size_t hash(const std::string& key) const;
    void rehash();

public:
    Dictionary();
    void add(const std::string& key, const std::string& value);
    void remove(const std::string& key);
    std::string search(const std::string& key) const;
    void display() const;
};

#endif // DICTIONARY_H
