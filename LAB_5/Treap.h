#ifndef CARTESIANTREE_H
#define CARTESIANTREE_H

#include <iostream>
#include "TreapNode.h"
class Treap {
private:
	TreapNode* _root;

	int _size;

	void InitRoot(int data);

	static TreapNode* Merge(TreapNode* a, TreapNode* b);

	static void Split(TreapNode* node, int key, TreapNode*& a, TreapNode*& b);

	void Insert(TreapNode*& node, int key, int priority);

	void Remove(TreapNode*& node, int key);

	void FreeTree(TreapNode*& node);



public:
	void ClearTree();

	int GetSize();

	TreapNode* GetRoot();

	Treap();

	void AddElementNotOptimazed(int key);

	void DeleteElementNotOptimazed(int key);

	void AddElementOptimazed(int key);

	void DeleteElementOptimazed(int key);
};
#endif