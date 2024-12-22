#include <iostream>
#include "TreapConsole.h"
#include "SafeInput.h"
#include "Treap.h"


using namespace std;

void Show1(TreapNode const* node, bool high, vector< string> const& lpref, vector< string> const& cpref, vector< string> const& rpref, bool root, bool left, shared_ptr< vector< vector< string>>> lines) {
    if (!node) return;
    typedef  vector< string> VS;
    auto VSCat = [](VS const& a, VS const& b) { auto r = a; r.insert(r.end(), b.begin(), b.end()); return r; };
    if (root) lines = make_shared< vector<VS>>();
    if (node->Left)
        Show1(node->Left, high, VSCat(lpref, high ? VS({ " ", " " }) : VS({ " " })), VSCat(lpref, high ? VS({ ch_ddia, ch_ver }) : VS({ ch_ddia })), VSCat(lpref, high ? VS({ ch_hor, " " }) : VS({ ch_hor })), false, true, lines);

    auto sval = "[" + to_string(node->Key) + ";" + to_string(node->Priority) + "]";
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

void ShowTreap(Treap& tree) {
    Show1(tree.GetRoot(), true);
}
void MenuTreap(Treap& tree)
{
    cout <<  "Cartesian Tree:" << endl;
    ShowTreap(tree);
    cout << endl;

    cout << "Size:"<< tree.GetSize() << endl << endl;
    cout << "1. Add new element not optimazed" << endl;
    cout << "2. Remove element by value not optimazed" << endl;
    cout << "3. Add new element optimazed" << endl;
    cout << "4. Remove element by value optimazed" << endl;
    cout << "5. Clear Tree" << endl;
    cout << "0. Exit to main menu" << endl;
}

void TreapConsole(Treap& tree) {
    bool stackState = true;
    int commandNumber;
    int newElement;
    int deletedElement;
    int chosenElement;
    while (stackState)
    {
        MenuTreap(tree);
        int commandNumber;
        commandNumber = SafeInput(0, 5);
        switch (commandNumber)
        {
        case 1:
            cout << "Enter a value:";
            newElement = ValidCin();
            tree.AddElementNotOptimazed(newElement);
            system("cls");
            break;
        case 2:
            cout << "Enter a value:";
            cin >> deletedElement;
            tree.DeleteElementNotOptimazed(deletedElement);
            system("cls");
            break;
        case 3:
            cout << "Enter a value:";
            newElement = ValidCin();
            tree.AddElementOptimazed(newElement);
            system("cls");
            break;
        case 4:
            cout << "Enter a value:";
            cin >> deletedElement;
            tree.DeleteElementOptimazed(deletedElement);
            system("cls");
            break;
        case 5:
            tree.ClearTree();
            system("cls");
            break;
        case 0:
            system("cls");
            stackState = false;
            break;
        }
    }
}