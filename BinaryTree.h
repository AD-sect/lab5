#pragma once
#include <iostream>
#include <algorithm>
#include "Dictionary.h"

template <typename T>
class BinaryTree
{
private:
	struct Node
	{
		T data{ 0 };
		Node* left{ nullptr };
		Node* right{ nullptr };
		Node* parent{ nullptr };
	};
	Node* root{ nullptr };
	int size{ 0 };

public:
	BinaryTree() = default;

	BinaryTree(const T item)
	{
		this->root = new Node{ item, nullptr, nullptr, nullptr };
		this->size = 1;
	}

	BinaryTree(T* items, const int size)
	{

		for (int i(0); i < size; i++)
			insert(*(items + i));
	}

	BinaryTree(Node* root)
	{
		this->root = root;
		this->size = subTreeSize(root);
	}

	void destroyTree(Node* leaf)
	{
		if (leaf != nullptr)
		{
			destroyTree(leaf->left);
			destroyTree(leaf->right);
			delete leaf;
			leaf = nullptr;
		}
	}

	~BinaryTree()
	{
		destroyTree(this->root);
	}

	T getData()
	{
		return this->root->data;
	}

	int getSize()
	{
		return this->size;
	}

	Node* getRoot()
	{
		return this->root;
	}

	void insert(const T item)
	{
		if (this->root == nullptr)
		{
			this->root = new Node{ item, nullptr, nullptr, nullptr };
			++this->size;
		}
		else
		{
			insertAt(item, this->root);
			++this->size;
		}
	}


	void insertAt( T item, Node* curRoot)
	{
		if (item <= curRoot->data)
		{
			if (curRoot->left != nullptr)
				insertAt(item, curRoot->left);
			else
			{
				Node* leaf = new Node{ item, nullptr, nullptr, curRoot };
				curRoot->left = leaf;
			}
		}
		else if (item >= curRoot->data)
		{
			if (curRoot->right != nullptr)
				insertAt(item, curRoot->right);
			else
			{
				Node* leaf = new Node{ item, nullptr, nullptr, curRoot };
				curRoot->right = leaf;
			}
		}
	}

	void print()
	{
		printTree(this->root);
		std::cout << std::endl;
	}
	void printTree(Node* cur)
	{
		if (cur != nullptr)
		{
			if (cur->left)
				printTree(cur->left);

			std::cout << cur->data << " " << std::endl;

			if (cur->right)
				printTree(cur->right);
		}
		else
			return;
	}

	T getDataNode(Node* curRoot)
	{
		return curRoot->data;
	}

	T getMin(Node* curRoot)
	{
		if (curRoot == nullptr)
		{
			return -1;
		}

		while (curRoot->left)
			curRoot = curRoot->left;

		return curRoot->data;
	}

	T getMax(Node* curRoot)
	{
		if (curRoot == nullptr)
		{
			return -1;
		}

		while (curRoot->right)
			curRoot = curRoot->right;

		return curRoot->data;
	}

	Node* getMinNode(Node* curRoot)
	{
		while (curRoot->left)
			curRoot = curRoot->left;

		return curRoot;
	}

	Node* getMaxNode(Node* curRoot)
	{
		while (curRoot->right)
			curRoot = curRoot->right;

		return curRoot;
	}

	Node* search(const T item)
	{
		Node* it{ this->root };
		while (it)
		{
			if (item < it->data)
			{
				it = it->left;
				continue;
			}
			else if (item > it->data)
			{
				it = it->right;
				continue;
			}
			else
				return it;
		}
		return nullptr;
	}

	int remove(const T item)
	{

		if (search(item) == nullptr)
			return -1;
		
		Node* it{ search(item) };

		if (this->size == 1)
		{
			delete this->root;
			this->root = nullptr;
			--this->size;
			return 0;
		}
		//if(it == this->root)
		if (it->left == nullptr && it->right == nullptr)
		{
			if (it->data <= it->parent->data)
				it->parent->left = nullptr;

			else if (it->data >= it->parent->data)
				it->parent->right = nullptr;
			delete it;
			it = nullptr;

		}
		else if (it->left != nullptr && it->right == nullptr)
		{
			if (it->data <= it->parent->data)
				it->parent->left = it->left;
			else if (it->data >= it->parent->data)
				it->parent->right = it->left;
			delete it;
			it = nullptr;

		}
		else if (it->left == nullptr && it->right != nullptr)
		{
			if (it->data <= it->parent->data)
				it->parent->left = it->right;

			else if (it->data >= it->parent->data)
				it->parent->right = it->right;
			delete it;
			it = nullptr;

		}
		else if (it->left != nullptr && it->right != nullptr)
		{
			Node* current{ getMaxNode(search(item)->left) };
			T data{ current->data };
			remove(current->data);
			it->data = data;

		}
		--this->size;
		return 0;
	}

	BinaryTree<T>* subTree(const T key)
	{
		if (search(key) == nullptr)
		{
			BinaryTree<T>* subTree = new BinaryTree<T>{ nullptr };
			return  subTree;
		}

		Node* newRoot{ search(key) };

		if (newRoot == nullptr)
			return nullptr;

		Node* subTreeRoot = new Node{ key , nullptr, nullptr, nullptr };
		Node* subTreeNode{ copy(newRoot, subTreeRoot) };

		BinaryTree<T>* subTree = new BinaryTree<T>{ subTreeRoot };
		return subTree;
	}

	Node* copy(Node* curRoot, Node* copyRoot)
	{
		if (curRoot->left)
		{
			copy(curRoot->left, copyRoot);
			insertAt(curRoot->left->data, copyRoot);
		}
		if (curRoot->right)
		{
			copy(curRoot->right, copyRoot);
			insertAt(curRoot->right->data, copyRoot);
		}
		return copyRoot;
	}

	int subTreeSize(const Node* subTreeRoot)
	{
		if (subTreeRoot == nullptr) return 0;
		else
			return subTreeSize(subTreeRoot->left) + 1
			+ subTreeSize(subTreeRoot->right);
	}

	bool matchTree(const Node* root1, const Node* root2)
	{
		if (root1 == nullptr && root2 == nullptr)
			return true;

		if (root1 == nullptr || root2 == nullptr)
			return false;

		if (root1->data != root2->data)
			return false;

		return (matchTree(root1->left, root2->left) &&
			matchTree(root1->right, root2->right));
	}

	bool subTreeCheck(BinaryTree* subTree)
	{
		if (subTree == nullptr)
			return false;

		if (!search(subTree->getData()))
			return false;
		else
			return matchTree(subTree->getRoot(), search(subTree->getData()));
	}

	T* getNode(T item)
	{
		return &(search(item)->data);
	}
};
