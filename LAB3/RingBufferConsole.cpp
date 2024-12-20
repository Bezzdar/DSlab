#include "RingBuffer.h"
#include "SafeInput.h"
#include <iostream>
#include <cstdlib> // Для system()


void RunRingBufferConsole() {
    system("cls");
    int initial_capacity;

    std::cout << "Enter initial capacity of the ring buffer: ";
    initial_capacity = SafeInput(); // Используем безопасный ввод

    RingBuffer ringBuffer(initial_capacity);
    int choice, value;

    do {
        system("cls"); // Очистка консоли
        std::cout << "Buffer content:\n";
        ringBuffer.Display();
        std::cout << "Ring Buffer Menu:\n";
        std::cout << "1. Add element\n";
        std::cout << "2. Remove element\n";
        std::cout << "3. Get free space\n";
        std::cout << "4. Get occupied space\n";
        std::cout << "5. Overwrite element\n";
        std::cout << "0. Back to main menu\n";
        std::cout << "Enter your choice: ";
        choice = SafeInput(); // Используем безопасный ввод

        switch (choice) {
        case 1:
            std::cout << "Enter value to add: ";
            value = SafeInput(); // Используем безопасный ввод
            ringBuffer.Add(value);
            break;
        case 2:
            std::cout << "Removed value: " << ringBuffer.Remove() << "\n";
            std::cin.ignore();
            std::cin.get();
            break;
        case 3:
            std::cout << "Free space: " << ringBuffer.GetFreeSpace() << "\n";
            std::cin.ignore();
            std::cin.get();
            break;
        case 4:
            std::cout << "Occupied space: " << ringBuffer.GetOccupiedSpace() << "\n";
            std::cin.ignore();
            std::cin.get();
            break;
        case 5:
            std::cout << "Enter value to overwrite: ";
            value = SafeInput(); // Используем безопасный ввод
            ringBuffer.Overwrite(value);
            break;
        case 0:
            break;
        default:
            std::cout << "Invalid choice!\n";
            std::cin.ignore();
            std::cin.get();
            break;
        }
    } while (choice != 0);
}

