#pragma once
#include <iostream>
using namespace std;

template <typename Comparable>
class BinarySearchTree
{
public:
	int size;
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree &rhs);
	~BinarySearchTree();

	const Comparable &FindMin() const;
	const Comparable &FindMax() const;
	bool Contains(const Comparable &x) const;
	bool IsEmpty() const;
	void PrintTree() const;

	void MakeEmpty();
	void Insert(const Comparable &x);
	void Remove(const Comparable &x);

	const BinarySearchTree & operator=(const BinarySearchTree &rhs);

private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode *left;
		BinaryNode *right;

		BinaryNode(const Comparable &theElement, BinaryNode *lt, BinaryNode *rt)
			:element(theElement), left(lt), right(rt) {}
	};
	BinaryNode *root;
	void Insert(const Comparable &x, BinaryNode *&t) const;
	void Remove(const Comparable &x, BinaryNode *&t) const;
	BinaryNode * FindMin(BinaryNode *t) const;
	BinaryNode * FindMax(BinaryNode *t) const;
	bool Contains(const Comparable &x, BinaryNode *t) const;
	void MakeEmpty(BinaryNode *&t);
	void PrintTree(BinaryNode *t) const;
	BinaryNode * Clone(BinaryNode *t) const;
};



template <typename Comparable>
void BinarySearchTree<Comparable>::PrintTree() const
{
	PrintTree(root);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::MakeEmpty(BinaryNode *&t)
{
	if (t != NULL)
	{
		MakeEmpty(t->left);
		MakeEmpty(t->right);
		delete t;
	}
	t = NULL;
}

template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree()
{
}

template <typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
	MakeEmpty(root);
}

template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree &rhs)
{

}

template <typename Comparable>
bool BinarySearchTree<Comparable>::Contains(const Comparable &x) const
{
	return Contains(x, root);
}


template <typename Comparable>
void BinarySearchTree<Comparable>::Insert(const Comparable &x)
{
	return Insert(x, root);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::Remove(const Comparable &x)
{
	return Remove(x, root);
}

template <typename Comparable>
const Comparable & BinarySearchTree<Comparable>::FindMax() const
{
	return FindMax(root)->element;
}

template <typename Comparable>
const Comparable & BinarySearchTree<Comparable>::FindMin() const
{
	return FindMin(root)->element;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::PrintTree(BinaryNode *t) const
{
	if (t != NULL)
	{
		PrintTree(t->left);
		cnt++;
		if (cnt == (tree.size + 1) / 2) {
			cout << t->element << endl;
			return;
		}
		PrintTree(t->right);
	}
}

template <typename Comparable>
bool BinarySearchTree<Comparable>::Contains(const Comparable &x, BinaryNode *t) const
{
	if (t == NULL)
		return false;
	else if (x < t->element)
		return Contains(x, t->left);
	else if (x > t->element)
		return Contains(x, t->right);
	else
		return true;//匹配到
}


template <typename Comparable>
void BinarySearchTree<Comparable>::Insert(const Comparable &x, BinaryNode *&t) const
{
	if (t == NULL)
		t = new BinaryNode(x, NULL, NULL);
	else if (x < t->element) {
		Insert(x, t->left);
		t.size++;
	}
	else if (x > t->element) {
		t.size++;
		Insert(x, t->right);
	}
	else
		return;//重复，不插入

}

template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode * BinarySearchTree<Comparable>::FindMax(BinaryNode *t) const
{
	if (t == NULL)
		return NULL;
	else if (t->right == NULL)
		return t;
	else
		return FindMax(t->right);
}

template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode * BinarySearchTree<Comparable>::FindMin(BinaryNode *t) const
{
	if (t == NULL)
		return NULL;
	else if (t->left == NULL)
		return t;
	else
		return FindMin(t->left);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::Remove(const Comparable &x, BinaryNode *&t) const
{
	if (t == NULL)
		return;
	if (x < t->element)
		Remove(x, t->left);
	else if (x > t->element)
		Remove(x, t->right);
	else if (t->left != NULL && t->right != NULL)//两个儿子的结点
	{
		t->element = FindMin(t->right)->element;
		Remove(t->element, t->right);
	}
	else
	{
		BinaryNode *oldNode = t;
		t = (t->left != NULL) ? t->left : t->right;
		delete oldNode;
		t.size--;
	}
}


template <typename Comparable>
const BinarySearchTree<Comparable> & BinarySearchTree<Comparable>::operator=(const BinarySearchTree<Comparable> &rhs)
{
	if (this != &rhs)
	{
		MakeEmpty();
		root = Clone(rhs.root);
	}
	return *this;
}


template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode * BinarySearchTree<Comparable>::Clone(BinaryNode *t) const
{
	if (t == NULL)
		return NULL;
	return new BinaryNode(t->element, Clone(t->left), Clone(t->right));
}