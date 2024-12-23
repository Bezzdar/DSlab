﻿#include <iostream>
#include "StackConsole.h"
#include "RingBufferConsole.h"
#include "QueueRingConsole.h"
#include "QueueTwoStackConsole.h"
#include "SafeInput.h"

int main() {
    int choice;
    do {
        system("cls");
        std::cout << "Menu:\n";
        std::cout << "1. Work with Stack\n";
        std::cout << "2. Work with Ring Buffer\n";
        std::cout << "3. Work with Queue (Ring Buffer)\n";
        std::cout << "4. Work with Queue (Two Stacks)\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        choice = SafeInput();

        switch (choice) {
        case 1: RunStackConsole(); break;
        case 2: RunRingBufferConsole(); break;
        case 3: RunQueueRingConsole(); break;
        case 4: RunQueueTwoStackConsole(); break;
        case 0: std::cout << "Exiting...\n"; break;
        default: std::cout << "Invalid choice!\n"; break;
        }
    } while (choice != 0);

    return 0;
}
