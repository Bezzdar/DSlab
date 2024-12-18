#include "ring_buffer.h"
#include "ring_buffer_console.h"
#include <iostream>

void ringBufferMenu() {
    int size;
    std::cout << "Enter buffer size: ";
    std::cin >> size;
    RingBuffer buffer(size);

    int choice;
    do {
        std::cout << "1. Add\n2. Get\n3. Print\n4. Free space\n5. Used space\n0. Exit\nChoice: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            int value;
            std::cout << "Enter value: ";
            std::cin >> value;
            try {
                buffer.add(value);
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 2:
            try {
                std::cout << "Got: " << buffer.get() << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 3:
            buffer.print();
            break;
        case 4:
            std::cout << "Free space: " << buffer.freeSpace() << std::endl;
            break;
        case 5:
            std::cout << "Used space: " << buffer.usedSpace() << std::endl;
            break;
        case 0:
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 0);
}
