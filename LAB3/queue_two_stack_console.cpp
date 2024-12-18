#include "queue_two_stacks.h"
#include <iostream>

void RunQueueTwoStackConsole() {
    QueueTwoStacks queue;
    int choice, value;

    do {
        queue.Display();
        std::cout << "Queue (Two Stacks) Menu:\n";
        std::cout << "1. Enqueue (Add element)\n";
        std::cout << "2. Dequeue (Remove element)\n";
        std::cout << "0. Back to main menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value to enqueue: ";
            std::cin >> value;
            queue.Enqueue(value);
            break;
        case 2:
            std::cout << "Dequeued value: " << queue.Dequeue() << "\n";
            break;
        case 0:
            break;
        default:
            std::cout << "Invalid choice!\n";
            break;
        }
    } while (choice != 0);
}
