#include "Stack.h"
#include "stack_console.h"
#include <iostream>

void stackMenu() {
    Stack stack;
    int choice;
    do {
        std::cout << "1. Push\n2. Pop\n3. Print\n4. Clear\n0. Exit\nChoice: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            int value;
            std::cout << "Enter value: ";
            std::cin >> value;
            stack.push(value);
            break;
        }
        case 2:
            try {
                std::cout << "Popped: " << stack.pop() << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 3:
            stack.print();
            break;
        case 4:
            stack.clear();
            std::cout << "Stack cleared!" << std::endl;
            break;
        case 0:
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 0);
}
