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

    std::vector<std::list<Entry>> _table;
    size_t _capacity;
    size_t _size;
    static const size_t _defaultCapacity = 8;
    static const double _loadFactor;

    size_t Hash(const std::string& key) const;
    void Rehash();

public:
    Dictionary();
    void Add(const std::string& key, const std::string& value);
    void Remove(const std::string& key);
    std::string Search(const std::string& key) const;
    void Display() const;
};

#endif // DICTIONARY_H
