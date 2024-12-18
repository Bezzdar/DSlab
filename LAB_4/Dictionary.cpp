#include "Dictionary.h"
#include <iomanip>
#include <thread>


HashTable::HashTable(size_t initialCapacity) : capacity(initialCapacity), size(0) {
    table.resize(capacity);
}

HashTable::~HashTable() {}

unsigned char HashTable::pearsonHash(const std::string& key) const {
    static const unsigned char T[256] = {
        0x01, 0x02, 0x03, 0x04, 
        0xFE, 0xFF
    };

    unsigned char hash = 0;
    for (char ch : key) {
        hash = T[hash ^ static_cast<unsigned char>(ch)];
    }
    return hash % capacity;
}

void HashTable::rehash() {
    size_t newCapacity = capacity * 2;
    std::vector<std::list<KeyValuePair>> newTable(newCapacity);

    for (auto& chain : table) {
        for (const auto& pair : chain) {
            unsigned char hash = pearsonHash(pair.key) % newCapacity;
            newTable[hash].emplace_back(pair.key, pair.value);
        }
    }

    table = std::move(newTable);
    capacity = newCapacity;
}

bool HashTable::add(const std::string& key, const std::string& value) {
    unsigned char hash = pearsonHash(key);

    for (const auto& pair : table[hash]) {
        if (pair.key == key) {
            std::cout << "Duplicate key not added: " << key << std::endl;
            return false;
        }
    }

    table[hash].emplace_back(key, value);
    ++size;

    if (static_cast<double>(size) / capacity > loadFactorThreshold) {
        rehash();
    }
    return true;
}

bool HashTable::remove(const std::string& key) {
    unsigned char hash = pearsonHash(key);
    auto& chain = table[hash];

    for (auto it = chain.begin(); it != chain.end(); ++it) {
        if (it->key == key) {
            chain.erase(it);
            --size;
            return true;
        }
    }

    return false;
}

bool HashTable::search(const std::string& key, std::string& value) const {
    unsigned char hash = pearsonHash(key);
    const auto& chain = table[hash];

    for (const auto& pair : chain) {
        if (pair.key == key) {
            value = pair.value;
            return true;
        }
    }

    return false;
}

void HashTable::print() const {
    for (size_t i = 0; i < capacity; ++i) {
        std::cout << "[" << std::setw(2) << i << "]: ";
        for (const auto& pair : table[i]) {
            std::cout << "(" << pair.key << ": " << pair.value << ") ";
        }
        std::cout << std::endl;
    }
}

// ==================== Dictionary Implementation ====================

Dictionary::Dictionary(size_t initialCapacity) : hashTable(initialCapacity) {}

void Dictionary::add(const std::string& key, const std::string& value) {
    if (hashTable.add(key, value)) {
        std::cout << "Added: (" << key << ": " << value << ")" << std::endl;
    }
    print();
}

void Dictionary::remove(const std::string& key) {
    if (hashTable.remove(key)) {
        std::cout << "Removed: " << key << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    else {
        std::cout << "Key not found: " << key << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    print();
}

void Dictionary::search(const std::string& key) const {
    std::string value;
    if (hashTable.search(key, value)) {
        std::cout << "Found: (" << key << ": " << value << ")" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    else {
        std::cout << "Key not found: " << key << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Dictionary::print() const {
    hashTable.print();
}
