#include "Stack.h"
#include <iostream>
#include <cstdlib> // Для system()
#include "SafeInput.h"

void RunStackConsole() {
    Stack stack;
    int choice, value;

    do {
        system("cls"); // Очистка консоли для обновления интерфейса
        stack.Display();
        std::cout << "Stack Menu:\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "0. Back to main menu\n";
        std::cout << "Enter your choice: ";
        choice = SafeInput();

        switch (choice) {
        case 1:
            std::cout << "Enter value to push: ";
            std::cin >> value;
            stack.Push(value);
            break;
        case 2:
            std::cout << "Popped value: " << stack.Pop() << "\n";
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
