#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include "Node.h"
class BinaryTree {
private:
	Node* _root;

	int _size;

	void InitRoot(int data);

	void Insert(Node*& node, int data);

	int CalculateHeight(Node* node);

	void DeleteNode(Node*& node, int data);

public:
	int GetSize();

	int GetHeight();

	Node* GetRoot();

	BinaryTree();

	void AddElement(int data);

	void DeleteElement(int data);

	int FindMin();

	int FindMax();

};
#endif