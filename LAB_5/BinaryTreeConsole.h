#ifndef BINARYTREECONSOLE_H
#define BINARYTREECONSOLE_H
#include <iostream>
#include"BinaryTree.h"
#include <vector>
#include <string>
#include <iostream>
#include "Lines.h"


using namespace std;

void Show1(Node const* node, bool high = true, vector<string> const& lpref = vector<string>(), vector<string> const& cpref = vector<string>(), vector<string> const& rpref = vector<string>(), bool root = true, bool left = true, shared_ptr<vector<vector<string>>> lines = nullptr);

void ShowBinaryTree(BinaryTree& tree);

void MenuBinaryTree(BinaryTree& tree);

void BinaryTreeConsole(BinaryTree& tree);


#endif 