#include "queue_stacks.h"
#include "queue_stacks_console.h"
#include <iostream>

void queueStacksMenu() {
    QueueStacks queue;
    int choice;
    do {
        std::cout << "1. Enqueue\n2. Dequeue\n3. Print\n0. Exit\nChoice: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            int value;
            std::cout << "Enter value: ";
            std::cin >> value;
            queue.enqueue(value);
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
