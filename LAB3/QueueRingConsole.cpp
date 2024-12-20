#include "QueueRingBuffer.h"
#include <iostream>
#include <cstdlib> // Для system()

void RunQueueRingConsole() {
    int initial_capacity;
    system("cls");
    std::cout << "Enter initial capacity of the ring buffer-based queue: ";
    std::cin >> initial_capacity;

    QueueRingBuffer queue(initial_capacity);
    int choice, value;

    do {
        system("cls"); // Очистка консоли
        queue.Display();
        std::cout << "Queue (Ring Buffer) Menu:\n";
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
            std::cin.ignore();
            std::cin.get();
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
