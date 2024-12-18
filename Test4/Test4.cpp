﻿#include <iostream>
#include"Validator.h"
#include"Colors.h"
#include "DictionaryConsole.h"
#include"Dictionary.h"
using namespace std;

//Вывод основного меню в консоль.
void Menu()
{
    cout << "Choose array:" << endl << endl;
    cout << "[1]" << CYAN << " - Hash table" << RESET << endl;
    cout << "[2]" << MAGENTA << " - Dictionary" << RESET << endl;
}

int main()
{
    Dictionary hash = Dictionary();
    bool programState = true;
    int arrayType;
    while (programState) {
        Menu();
        arrayType = 1;
        switch (arrayType)
        {
        case 1:
            system("cls");
            DictionaryConsole(hash);
            break;
        case 2:
            system("cls");

            break;
        case 0:
            programState = false;
            break;
        }
    }
}