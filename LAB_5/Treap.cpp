#include "Treap.h"

Treap::Treap() : _size(0), _root(nullptr) {}

int Treap::GetSize() {
	return _size;
}

TreapNode* Treap::GetRoot() {
	return _root;
}

TreapNode* Treap::Merge(TreapNode* a, TreapNode* b) {

	if (!a || !b) {
		return a ? a : b;
	}
	if (a->Priority > b->Priority) {
		a->Right = Merge(a->Right, b);
		return a;
	}
	else {
		b->Left = Merge(a, b->Left);
		return b;
	}

}

void Treap::Split(TreapNode* node, int key, TreapNode*& a, TreapNode*& b) {
	if (!node)
	{
		a = b = nullptr;
		return;
	}
	if (node->Key < key)
	{
		Split(node->Right, key, node->Right, b);
		a = node;
	}
	else
	{
		Split(node->Left, key, a, node->Left);
		b = node;
	}

}

void Treap::InitRoot(int key) {
	_root = new TreapNode(key);
	_size++;
}

void Treap::AddElementNotOptimazed(int key) {
	if (_size != 0) {
		TreapNode* less;
		TreapNode* greater;
		Split(_root, key, less, greater);
		less = Merge(less, new TreapNode(key));
		_root = Merge(less, greater);
		_size++;
	}
	else {
		InitRoot(key);
	}
}

void Treap::Insert(TreapNode*& node, int key, int priority) {
	if (node == nullptr)
	{
		node = new TreapNode;
		node->Key = key;
		node->Priority = priority;
		return;
	}

	if (node->Priority > priority)
	{
		if (key < node->Key)
		{
			Insert(node->Left, key, priority);
		}
		else
		{
			Insert(node->Right, key, priority);
		}
		return;
	}

	TreapNode* newCartesianNode = new TreapNode(key);
	newCartesianNode->Priority = priority;
	Split(node, key, newCartesianNode->Left, newCartesianNode->Right);
	node = newCartesianNode;
}

void Treap::AddElementOptimazed(int key) {
	if (_size != 0) {
		int start = 0;
		int end = 20;

		Insert(_root, key, rand() % (end - start + 1) + start);
		_size++;
	}
	else {
		InitRoot(key);
	}
}

void Treap::DeleteElementNotOptimazed(int key) {
	if (_size != 0) {
		TreapNode* less;
		TreapNode* equal;
		TreapNode* greater;
		Split(_root, key, less, greater);
		Split(greater, key + 1, equal, greater);
		if (equal != nullptr) {
			equal = Merge(equal->Left, equal->Right);
			_root = Merge(less, greater);
			_root = Merge(_root, equal);
			_size--;
		}
	}

}
void Treap::Remove(TreapNode*& node, int key) {
	if (node == nullptr)
	{
		return;
	}

	if (key < node->Key)
	{
		Remove(node->Left, key);
	}
	else if (key > node->Key)
	{
		Remove(node->Right, key);
	}
	else
	{
		TreapNode* current = node;
		node = Merge(node->Left, node->Right);
		delete current;
		_size--;
	}
}

void Treap::DeleteElementOptimazed(int key) {
	if (_size != 0) {
		Remove(_root, key);
	}
}

void Treap::FreeTree(TreapNode*& node)
{
	if (node == nullptr)
	{
		return;
	}
	FreeTree(node->Left);
	FreeTree(node->Right);
	delete node;
	node = nullptr;
}

void Treap::ClearTree() {
	if (_size != 0) {
		FreeTree(_root);
		_size = 0;
	}
}