#include "SafeInput.h"

int SafeInput() {
    int value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail()) { // Проверка на некорректный ввод
            std::cin.clear(); // Сбросить флаг ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистить буфер
            std::cout << "Invalid input. Please enter a valid number: ";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистить оставшиеся символы
            return value; // Если ввод корректен, вернуть значение
        }
    }
}
