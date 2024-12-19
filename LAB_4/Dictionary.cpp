#include "Dictionary.h"
#include <iomanip>
#include <thread>

// Конструктор хэш-таблицы с заданной начальной ёмкостью
HashTable::HashTable(size_t initialCapacity) : capacity(initialCapacity), size(0) {
    table.resize(capacity); // Инициализация таблицы заданным количеством бакетов
}

// Деструктор хэш-таблицы
HashTable::~HashTable() {}

// Функция для вычисления хэша строки с использованием Pearson Hashing
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
    // Проходим по каждому символу строки и обновляем значение хэша
    for (char ch : key) {
        hash = T[hash ^ static_cast<unsigned char>(ch)];
    }
    return hash % capacity; // Приведение хэша к размеру таблицы
}

// Функция для увеличения размера таблицы и перераспределения данных
void HashTable::rehash() {
    size_t newCapacity = capacity * 2; // Удваиваем ёмкость
    std::vector<std::list<KeyValuePair>> newTable(newCapacity);

    // Перебираем все цепочки в старой таблице
    for (auto& chain : table) {
        for (const auto& pair : chain) {
            // Перерасчитываем хэш для новой ёмкости
            unsigned char hash = pearsonHash(pair.key) % newCapacity;
            newTable[hash].emplace_back(pair.key, pair.value); // Перемещаем пары
        }
    }

    table = std::move(newTable); // Заменяем таблицу на новую
    capacity = newCapacity; // Обновляем ёмкость
}

// Добавление нового элемента в хэш-таблицу
bool HashTable::add(const std::string& key, const std::string& value) {
    unsigned char hash = pearsonHash(key); // Вычисляем хэш

    // Проверяем, существует ли уже ключ
    for (const auto& pair : table[hash]) {
        if (pair.key == key) {
            std::cout << "Duplicate key not added: " << key << std::endl;
            return false;
        }
    }

    // Добавляем новую пару в цепочку
    table[hash].emplace_back(key, value);
    ++size; // Увеличиваем размер

    // Проверяем коэффициент заполнения
    if (static_cast<double>(size) / capacity > loadFactorThreshold) {
        rehash(); // Перехэшируем, если превышен порог
    }
    return true;
}

// Удаление элемента по ключу
bool HashTable::remove(const std::string& key) {
    unsigned char hash = pearsonHash(key); // Вычисляем хэш
    auto& chain = table[hash]; // Получаем цепочку

    // Ищем элемент в цепочке
    for (auto it = chain.begin(); it != chain.end(); ++it) {
        if (it->key == key) {
            chain.erase(it); // Удаляем элемент
            --size; // Уменьшаем размер
            return true;
        }
    }

    return false; // Ключ не найден
}

// Поиск значения по ключу
bool HashTable::search(const std::string& key, std::string& value) const {
    unsigned char hash = pearsonHash(key); // Вычисляем хэш
    const auto& chain = table[hash]; // Получаем цепочку

    // Ищем элемент в цепочке
    for (const auto& pair : chain) {
        if (pair.key == key) {
            value = pair.value; // Присваиваем найденное значение
            return true;
        }
    }

    return false; // Ключ не найден
}

// Печать содержимого хэш-таблицы
void HashTable::print() const {
    for (size_t i = 0; i < capacity; ++i) {
        std::cout << "[" << std::setw(2) << i << "]: ";
        for (const auto& pair : table[i]) {
            std::cout << "(" << pair.key << ": " << pair.value << ") ";
        }
        std::cout << std::endl;
    }
}

// Конструктор словаря
Dictionary::Dictionary(size_t initialCapacity) : hashTable(initialCapacity) {}

// Добавление нового элемента в словарь
void Dictionary::add(const std::string& key, const std::string& value) {
    if (hashTable.add(key, value)) {
        std::cout << "Added: (" << key << ": " << value << ")" << std::endl;
    }
    print(); 
}

// Удаление элемента из словаря
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

// Поиск элемента в словаре
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

// Печать содержимого словаря
void Dictionary::print() const {
    hashTable.print();
}
