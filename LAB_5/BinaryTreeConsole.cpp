#include <iostream>
#include "BinaryTreeConsole.h"
#include"SafeInput.h"
#include"BinaryTree.h"
#include"Node.h"

using namespace std;

void Show1(Node const* node, bool high, vector< string> const& lpref, vector< string> const& cpref, vector< string> const& rpref, bool root, bool left, shared_ptr< vector< vector< string>>> lines) {
    if (!node) return;
    typedef  vector< string> VS;
    auto VSCat = [](VS const& a, VS const& b) { auto r = a; r.insert(r.end(), b.begin(), b.end()); return r; };
    if (root) lines = make_shared< vector<VS>>();
    if (node->Left)
        Show1(node->Left, high, VSCat(lpref, high ? VS({ " ", " " }) : VS({ " " })), VSCat(lpref, high ? VS({ ch_ddia, ch_ver }) : VS({ ch_ddia })), VSCat(lpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })), false, true, lines);

    auto sval = to_string(node->Data);
    string coloredSval = sval;
    size_t sm = left || sval.empty() ? sval.size() / 2 : ((sval.size() + 1) / 2 - 1);
    for (size_t i = 0; i < sval.size(); ++i) {
        string colored = string(1, sval[i]);
        lines->push_back(VSCat(i < sm ? lpref : i == sm ? cpref : rpref, { colored }));
    }
    if (node->Right)
        Show1(node->Right, high, VSCat(rpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })), VSCat(rpref, high ? VS({ ch_rddia, ch_ver }) : VS({ ch_rddia })), VSCat(rpref, high ? VS({ " ", " " }) : VS({ " " })), false, false, lines);
    if (root) {
        VS out;
        for (size_t l = 0;; ++l) {
            bool last = true;
            string line;
            for (size_t i = 0; i < lines->size(); ++i)
                if (l < (*lines).at(i).size()) {
                    line += lines->at(i)[l];
                    last = false;
                }
                else line += " ";
            if (last) break;
            out.push_back(line);
        }
        for (size_t i = 0; i < out.size(); ++i)
            cout << out[i] << endl;
    }
}

void ShowBinaryTree(BinaryTree& tree) {
    Show1(tree.GetRoot(), true);
}
void MenuBinaryTree(BinaryTree& tree)
{
    cout << "Binary Tree:" << endl;
    ShowBinaryTree(tree);
    cout << endl;

    cout << "Size:" <<tree.GetSize()<< endl;
    cout << "Height:"<<tree.GetHeight() << endl;
    //cout << "Min Element:" <<tree.FindMin() << endl;
    //cout << "Max Element:" <<tree.FindMax() << endl;

    cout << "1." << "Add new elemnt" << endl;
    cout << "2." << "Remove element by value" << endl;
    cout << "3." << "Get min elememnt" << endl;
    cout << "4." << "Get max element" << endl;
    cout << "0."<< "Exit to main menu" << endl;
}

void BinaryTreeConsole(BinaryTree& tree) {
    bool stackState = true;
    int commandNumber;
    int newElement;
    int deletedElement;
    int chosenElement;
    while (stackState)
    {
        MenuBinaryTree(tree);
        int commandNumber;
        commandNumber = SafeInput(0, 4);
        switch (commandNumber)
        {
        case 1:
            cout << "Enter a value:";
            newElement = ValidCin();
            tree.AddElement(newElement);
            system("cls");
            break;
        case 2:
            cout << "Enter a value:";
            cin >> deletedElement;
            tree.DeleteElement(deletedElement);
            system("cls");
            break;
        case 3:
            cout << "Min element:";
            cout << tree.FindMin();
            std::cin.ignore();
            std::cin.get();
            system("cls");
            break;
        case 4:
            cout << "Max element:";
            cout << tree.FindMax();
            std::cin.ignore();
            std::cin.get();;
            system("cls");
            break;
        case 0:
            system("cls");
            stackState = false;
            break;
        }
    }
}