#include <iostream>
#include"SafeInput.h"
#include"BinaryTree.h"
#include "BinaryTreeConsole.h"
#include "TreapConsole.h"
#include"Treap.h"
using namespace std;

//Вывод основного меню в консоль.
void Menu()
{
    cout << "Choose Tree:" << endl << endl;
    cout << "1." << "Binary Tree" << endl;
    cout << "2." << "Decart Tree" << endl;
}

int main()
{
    BinaryTree binaryTree = BinaryTree();
    Treap cartesianTree = Treap();

    bool programState = true;
    int arrayType;
    while (programState) {
        Menu();
        arrayType = SafeInput(1, 4);
        switch (arrayType)
        {
        case 1:
            system("cls");
            BinaryTreeConsole(binaryTree);
            break;
        case 2:
            system("cls");
            TreapConsole(cartesianTree);
            break;
        case 0:
            programState = false;
            break;
        }
    }
}