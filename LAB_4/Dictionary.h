#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <iostream>
#include <list>

struct KeyValuePair {
    std::string key;
    std::string value;

    KeyValuePair(const std::string& k, const std::string& v) : key(k), value(v) {}
};

class HashTable {
private:
    std::vector<std::list<KeyValuePair>> table;
    size_t capacity;
    size_t size;
    const double loadFactorThreshold = 0.75;

    unsigned char pearsonHash(const std::string& key) const;
    void rehash();

public:
    HashTable(size_t initialCapacity = 8);
    ~HashTable();

    bool add(const std::string& key, const std::string& value);
    bool remove(const std::string& key);
    bool search(const std::string& key, std::string& value) const;

    void print() const;
};

class Dictionary {
private:
    HashTable hashTable;

public:
    Dictionary(size_t initialCapacity = 8);
    void Add(const std::string& key, const std::string& value);
    void Remove(const std::string& key);
    void Search(const std::string& key) const;
    void print() const;
};

#endif // DICTIONARY_H
