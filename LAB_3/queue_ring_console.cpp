#include "queue_ring.h"
#include "queue_ring_console.h"
#include <iostream>

void queueRingMenu() {
    int size;
    std::cout << "Enter buffer size for the queue: ";
    std::cin >> size;

    QueueRing queue(size);
    int choice;

    do {
        std::cout << "1. Enqueue\n2. Dequeue\n3. Print\n0. Exit\nChoice: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            int value;
            std::cout << "Enter value: ";
            std::cin >> value;
            try {
                queue.enqueue(value);
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 2:
            try {
                std::cout << "Dequeued: " << queue.dequeue() << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 3:
            queue.print();
            break;
        case 0:
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 0);
}
