﻿#include "Dictionary.h"
#include "SafeInput.h"
#include <iostream>
#include <cstdlib> 


void clearScreen() {
    system("cls"); 
}

// Функция отображения меню
void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Add (key, value)\n";
    std::cout << "2. Remove (key)\n";
    std::cout << "3. Search (key)\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Dictionary dict;
    int choice;
    std::string key, value;

    do {
        clearScreen();

        std::cout << "Current Dictionary State:\n";
        dict.Display();

        displayMenu();

        choice = SafeInput();

        switch (choice) {
        case 1:
            std::cout << "Enter key: ";
            std::cin >> key;
            std::cout << "Enter value: ";
            std::cin >> value;
            dict.Add(key, value);
            break;

        case 2:
            std::cout << "Enter key to remove: ";
            std::cin >> key;
            dict.Remove(key);
            break;

        case 3:
            std::cout << "Enter key to search: ";
            std::cin >> key;
            value = dict.Search(key);
            std::cout << "Value: " << value << "\n";
            std::cin.ignore();
            std::cin.get(); 
            break;

        case 4:
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << "Invalid choice. Try again.\n";
            std::cin.ignore();
            std::cin.get(); 
            break;
        }
    } while (choice != 4);

    return 0;
}
