#include "Dictionary.h"
#include "safe_input.h"
#include <iostream>
#include <cstdlib>


void menu() {
    Dictionary dictionary;

    while (true) {
        system("cls");

        std::cout << "Dictionary:\n";
        dictionary.print();

        std::cout << "\nMenu:\n";
        std::cout << "1. Add (key, value)\n";
        std::cout << "2. Remove (key)\n";
        std::cout << "3. Search (key)\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        choice = SafeInput();

        if (choice == 4) break;

        std::string key, value;
        switch (choice) {
        case 1:
            std::cout << "Enter key: ";
            std::cin >> key;
            std::cout << "Enter value: ";
            std::cin >> value;
            dictionary.add(key, value);
            break;
        case 2:
            std::cout << "Enter key to remove: ";
            std::cin >> key;
            dictionary.remove(key);
            break;
        case 3:
            std::cout << "Enter key to search: ";
            std::cin >> key;
            dictionary.search(key);
            break;
        default:
            std::cout << "Invalid option. Try again.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}
