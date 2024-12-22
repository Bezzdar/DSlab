#ifndef CARTESIANTREECONSOLE_H
#define CARTESIANTREECONSOLE_H
#include <iostream>
#include"TreapNode.h"
#include"Treap.h"
#include <vector>
#include <string>
#include <iostream>
#include "Symbols.h"

using namespace std;

void Show1(TreapNode const* node, bool high = true, vector<string> const& lpref = vector<string>(), vector<string> const& cpref = vector<string>(), vector<string> const& rpref = vector<string>(), bool root = true, bool left = true, shared_ptr<vector<vector<string>>> lines = nullptr);

void ShowTreap(Treap& tree);

void MenuTreap(Treap& tree);

void TreapConsole(Treap& tree);


#endif 