#include "SafeInput.h"
#include <iostream>

int SafeInput() 
    {
        int value;
        while (true)
        {
            std::cin >> value;
            if (std::cin.fail() || std::cin.peek() != '\n')
            {
                std::cout << "Invalid input!" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                return value;
            }
        }
    }
