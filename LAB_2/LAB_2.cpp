#include "List.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <fstream>

void ClearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void PrintListWithColors(const List& list) {
    const char* RESET = "\033[0m";
    const char* GREEN = "\033[32m";
    const char* RED = "\033[31m";

    ListItem* current = list.GetHead();
    if (!current) {
        std::cout << "The list is empty.\n";
        return;
    }

    std::cout << "List: ";
    bool isFirst = true;
    while (current) {
        if (isFirst) {
            std::cout << GREEN << current->Data << RESET << " ";
            isFirst = false;
        }
        else if (current == list.GetTail()) {
            std::cout << RED << current->Data << RESET << " ";
        }
        else {
            std::cout << current->Data << " ";
        }
        current = current->Next;
    }
    std::cout << "\n";
}

void DisplayMenu() {
    std::cout << "\nMenu:\n"
        << "1. Add element\n"
        << "2. Remove element\n"
        << "3. Insert at the beginning\n"
        << "4. Insert at the end\n"
        << "5. Insert after an element\n"
        << "6. Insert before an element\n"
        << "7. Sort the list\n"
        << "8. Search for an element\n"
        << "9. Exit\n"
        << "10. Run benchmark\n"
        << "Enter your choice: ";
}

void Benchmark() {
    std::vector<int> sizes = { 1000, 5000, 10000, 50000, 100000 };
    std::vector<long long> insertStartTimes, insertEndTimes, deleteStartTimes, deleteEndTimes;

    for (int size : sizes) {
        List list;

        for (int i = 0; i < size; ++i) {
            list.Add(i);
        }

        auto start = std::chrono::high_resolution_clock::now();
        list.InsertAtBeginning(-1);
        auto end = std::chrono::high_resolution_clock::now();
        insertStartTimes.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());

        start = std::chrono::high_resolution_clock::now();
        list.InsertAtEnd(-1);
        end = std::chrono::high_resolution_clock::now();
        insertEndTimes.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());

        start = std::chrono::high_resolution_clock::now();
        list.Remove(list.GetHead()->Data);
        end = std::chrono::high_resolution_clock::now();
        deleteStartTimes.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());

        start = std::chrono::high_resolution_clock::now();
        list.Remove(list.GetTail()->Data);
        end = std::chrono::high_resolution_clock::now();
        deleteEndTimes.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }

    std::ofstream file("benchmark_results.csv");
    file << "Size,InsertStart,InsertEnd,DeleteStart,DeleteEnd\n";
    for (size_t i = 0; i < sizes.size(); ++i) {
        file << sizes[i] << ","
            << insertStartTimes[i] << ","
            << insertEndTimes[i] << ","
            << deleteStartTimes[i] << ","
            << deleteEndTimes[i] << "\n";
    }
    file.close();

    std::cout << "Benchmark results saved to 'benchmark_results.csv'.\n";
}

void Menu() {
    List list;
    int choice;
    int index;
    int value, target;

    do {
        ClearScreen();
        PrintListWithColors(list);
        DisplayMenu();

        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value to add: ";
            std::cin >> value;
            list.Add(value);
            break;
        case 2:
            std::cout << "Enter value to remove: ";
            std::cin >> value;
            list.Remove(value);
            break;
        case 3:
            std::cout << "Enter value to insert at the beginning: ";
            std::cin >> value;
            list.InsertAtBeginning(value);
            break;
        case 4:
            std::cout << "Enter value to insert at the end: ";
            std::cin >> value;
            list.InsertAtEnd(value);
            break;
        case 5:
            std::cout << "Enter the target value to insert after: ";
            std::cin >> target;
            std::cout << "Enter the new value: ";
            std::cin >> value;
            list.InsertAfter(target, value);
            break;
        case 6:
            std::cout << "Enter the target value to insert before: ";
            std::cin >> target;
            std::cout << "Enter the new value: ";
            std::cin >> value;
            list.InsertBefore(target, value);
            break;
        case 7:
            list.Sort();
            std::cout << "The list has been sorted.\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
        case 8:
            std::cout << "Enter the value to search for: ";
            std::cin >> value;
            index = list.Find(value);
            std::cout << "Element found at index: " << index;
            std::this_thread::sleep_for(std::chrono::seconds(3));
            break;
        case 9:
            std::cout << "Exiting the program...\n";
            break;
        case 10:
            Benchmark();
            std::this_thread::sleep_for(std::chrono::seconds(3));
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    } while (choice != 9);
}

int main() {
    Menu();
    return 0;
}
