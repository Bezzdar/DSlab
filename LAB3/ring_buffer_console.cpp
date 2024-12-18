#include "ring_buffer.h"
#include <iostream>

void RunRingBufferConsole() {
    int initial_capacity;
    std::cout << "Enter initial capacity of the ring buffer: ";
    std::cin >> initial_capacity;

    RingBuffer ringBuffer(initial_capacity);
    int choice, value;

    do {
        ringBuffer.Display();
        std::cout << "Ring Buffer Menu:\n";
        std::cout << "1. Add element\n";
        std::cout << "2. Remove element\n";
        std::cout << "3. Get free space\n";
        std::cout << "4. Get occupied space\n";
        std::cout << "0. Back to main menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value to add: ";
            std::cin >> value;
            ringBuffer.Add(value);
            break;
        case 2:
            std::cout << "Removed value: " << ringBuffer.Remove() << "\n";
            break;
        case 3:
            std::cout << "Free space: " << ringBuffer.GetFreeSpace() << "\n";
            break;
        case 4:
            std::cout << "Occupied space: " << ringBuffer.GetOccupiedSpace() << "\n";
            break;
        case 0:
            break;
        default:
            std::cout << "Invalid choice!\n";
            break;
        }
    } while (choice != 0);
}
