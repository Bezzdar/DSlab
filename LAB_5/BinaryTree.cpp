#include"BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree() :_size(0), _root(nullptr) {}

int BinaryTree::CalculateHeight(Node* node) {
	if (node == nullptr) {
		return 0;
	}
	int leftHeight = CalculateHeight(node->Left);
	int rightHeight = CalculateHeight(node->Right);
	return std::max(leftHeight, rightHeight) + 1;
}

int BinaryTree::GetHeight() {
	return CalculateHeight(_root);
}

int BinaryTree::GetSize() {
	return _size;
}

Node* BinaryTree::GetRoot() {
	return _root;
}

void BinaryTree::InitRoot(int data) {
	_root = new Node(data);
	_size++;
}

void BinaryTree::Insert(Node*& node, int data) {
	if (node == nullptr)
	{
		node = new Node(data);
		return;
	}

	if (node->Data > data)
	{
		Insert(node->Left, data);
		return;
	}
	else {
		Insert(node->Right, data);
		return;
	}
}

void BinaryTree::AddElement(int data) {
	if (_size == 0) {
		InitRoot(data);
		return;
	}
	Insert(_root, data);
	_size++;
}

void BinaryTree::DeleteNode(Node*& node, int data) {
	if (node == nullptr) {
		return;
	}

	if (data < node->Data) {
		DeleteNode(node->Left, data);
	}
	else if (data > node->Data) {
		DeleteNode(node->Right, data);
	}
	else {
		if (node->Left == nullptr) {
			Node* temp = node->Right;
			delete node;
			node = temp;
			_size--;
		}
		else if (node->Right == nullptr) {
			Node* temp = node->Left;
			delete node;
			node = temp;
			_size--;
		}
		else {
			Node* temp = node->Right;
			while (temp && temp->Left != nullptr) {
				temp = temp->Left;
			}
			node->Data = temp->Data;
			DeleteNode(node->Right, temp->Data);
		}
	}
}

void BinaryTree::DeleteElement(int data) {
	if (_size != 0) {
		DeleteNode(_root, data);

	}
}

int BinaryTree::FindMin() {
	if (_root == nullptr)
	{
		return 0;
	}
	Node* temp = _root;
	while (temp->Left != nullptr)
	{
		temp = temp->Left;
	}
	return temp->Data;
}

int BinaryTree::FindMax() {
	if (_root == nullptr)
	{
		return 0;
	}
	Node* temp = _root;
	while (temp->Right != nullptr)
	{
		temp = temp->Right;
	}
	return temp->Data;
}