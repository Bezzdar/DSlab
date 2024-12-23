#include "Dictionary.h"
#include <iomanip>
#include <thread>

// ����������� ���-������� � �������� ��������� ��������
HashTable::HashTable(size_t initialCapacity) : capacity(initialCapacity), size(0) {
    table.resize(capacity); // ������������� ������� �������� ����������� �������
}

// ���������� ���-�������
HashTable::~HashTable() {}

// ������� ��� ���������� ���� ������ � �������������� Pearson Hashing
unsigned char HashTable::pearsonHash(const std::string& key) const {
    static const unsigned char T[256] =
    { 98,  6, 85,150, 36, 23,112,164,135,207,169,  5, 26, 64,165,219,
      61, 20, 68, 89,130, 63, 52,102, 24,229,132,245, 80,216,195,115,
      90,168,156,203,177,120,  2,190,188,  7,100,185,174,243,162, 10,
     237, 18,253,225,  8,208,172,244,255,126,101, 79,145,235,228,121,
     123,251, 67,250,161,  0,107, 97,241,111,181, 82,249, 33, 69, 55,
      59,153, 29,  9,213,167, 84, 93, 30, 46, 94, 75,151,114, 73,222,
     197, 96,210, 45, 16,227,248,202, 51,152,252,125, 81,206,215,186,
      39,158,178,187,131,136,  1, 49, 50, 17,141, 91, 47,129, 60, 99,
     154, 35, 86,171,105, 34, 38,200,147, 58, 77,118,173,246, 76,254,
     133,232,196,144,198,124, 53,  4,108, 74,223,234,134,230,157,139,
     189,205,199,128,176, 19,211,236,127,192,231, 70,233, 88,146, 44,
     183,201, 22, 83, 13,214,116,109,159, 32, 95,226,140,220, 57, 12,
     221, 31,209,182,143, 92,149,184,148, 62,113, 65, 37, 27,106,166,
       3, 14,204, 72, 21, 41, 56, 66, 28,193, 40,217, 25, 54,179,117,
     238, 87,240,155,180,170,242,212,191,163, 78,218,137,194,175,110,
      43,119,224, 71,122,142, 42,160,104, 48,247,103, 15, 11,138,239
    };

    unsigned char hash = 0;
    // �������� �� ������� ������� ������ � ��������� �������� ����
    for (char ch : key) {
        hash = T[hash ^ static_cast<unsigned char>(ch)];
    }
    return hash % capacity; // ���������� ���� � ������� �������
}

// ������� ��� ���������� ������� ������� � ����������������� ������
void HashTable::rehash() {
    size_t newCapacity = capacity * 2; // ��������� �������
    std::vector<std::list<KeyValuePair>> newTable(newCapacity);

    // ���������� ��� ������� � ������ �������
    for (auto& chain : table) {
        for (const auto& pair : chain) {
            // ��������������� ��� ��� ����� �������
            unsigned char hash = pearsonHash(pair.key) % newCapacity;
            newTable[hash].emplace_back(pair.key, pair.value); // ���������� ����
        }
    }

    table = std::move(newTable); // �������� ������� �� �����
    capacity = newCapacity; // ��������� �������
}

// ���������� ������ �������� � ���-�������
bool HashTable::add(const std::string& key, const std::string& value) {
    unsigned char hash = pearsonHash(key); // ��������� ���

    // ���������, ���������� �� ��� ����
    for (const auto& pair : table[hash]) {
        if (pair.key == key) {
            std::cout << "Duplicate key not added: " << key << std::endl;
            return false;
        }
    }

    // ��������� ����� ���� � �������
    table[hash].emplace_back(key, value);
    ++size; // ����������� ������

    // ��������� ����������� ����������
    if (static_cast<double>(size) / capacity > loadFactorThreshold) {
        rehash(); // ������������, ���� �������� �����
    }
    return true;
}

// �������� �������� �� �����
bool HashTable::remove(const std::string& key) {
    unsigned char hash = pearsonHash(key); // ��������� ���
    auto& chain = table[hash]; // �������� �������

    // ���� ������� � �������
    for (auto it = chain.begin(); it != chain.end(); ++it) {
        if (it->key == key) {
            chain.erase(it); // ������� �������
            --size; // ��������� ������
            return true;
        }
    }

    return false; // ���� �� ������
}

// ����� �������� �� �����
bool HashTable::search(const std::string& key, std::string& value) const {
    unsigned char hash = pearsonHash(key); // ��������� ���
    const auto& chain = table[hash]; // �������� �������

    // ���� ������� � �������
    for (const auto& pair : chain) {
        if (pair.key == key) {
            value = pair.value; // ����������� ��������� ��������
            return true;
        }
    }

    return false; // ���� �� ������
}

// ������ ����������� ���-�������
void HashTable::print() const {
    for (size_t i = 0; i < capacity; ++i) {
        std::cout << "[" << std::setw(2) << i << "]: ";
        for (const auto& pair : table[i]) {
            std::cout << "(" << pair.key << ": " << pair.value << ") ";
        }
        std::cout << std::endl;
    }
}

// ����������� �������
Dictionary::Dictionary(size_t initialCapacity) : hashTable(initialCapacity) {}

// ���������� ������ �������� � �������
void Dictionary::Add(const std::string& key, const std::string& value) {
    if (hashTable.add(key, value)) {
        std::cout << "Added: (" << key << ": " << value << ")" << std::endl;
    }
    print(); 
}

// �������� �������� �� �������
void Dictionary::Remove(const std::string& key) {
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

// ����� �������� � �������
void Dictionary::Search(const std::string& key) const {
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

// ������ ����������� �������
void Dictionary::print() const {
    hashTable.print();
}
