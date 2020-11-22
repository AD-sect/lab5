#pragma once
#include "BinaryTree.h"
#include "Exception.h"
#include<iostream>

template<class TKey, class TElement>
struct pair 
{
	TKey key;
	TElement element;
};

template<class TKey, class TElement>
std::ostream& operator<< (std::ostream& out, const pair<TKey, TElement>& p)
{
	out << p.key << " " << p.element << " ";

	return out;
}

template<class TKey, class TElement>
bool operator>= (const pair<TKey, TElement>& p1, const pair<TKey, TElement>& p2)
{
	return  p1.key >= p2.key;
}

template<class TKey, class TElement>
bool operator<= (const TKey key, const pair<TKey, TElement>& p2)
{
	return key <= p2.key;
}

template<class TKey, class TElement>
bool operator<= (const pair<TKey, TElement>& p1, const pair<TKey, TElement>& p2)
{
	return p1.key <= p2.key;
}
template<class TKey, class TElement>

bool operator< (const pair<TKey, TElement>& p1, const pair<TKey, TElement>& p2)
{
	return p1.key < p2.key;
}

template<class TKey, class TElement>
bool operator> (const pair<TKey, TElement>& p1, const pair<TKey, TElement>& p2)
{
	return  p1.key > p2.key;
}

 template <class TKey, class TElement>
 class Dictionary
 {
 private:
	 BinaryTree<pair<TKey, TElement>>* tree { nullptr };

 public:

	 Dictionary(TKey key, TElement element)
	 {
		 pair<TKey, TElement> p;
		 p.element = element;
		 p.key = key;
		 this->tree = new BinaryTree< pair<TKey, TElement>>(p);
	 }

	 Dictionary(pair<TKey, TElement> p)
	 {
		 this->tree = new BinaryTree<pair<TKey, TElement>>(p);
	 }

	 Dictionary(TKey key)
	 {
		 pair<TKey, TElement> p;
		 p.key = key;
		 this->tree = new BinaryTree<pair<TKey, TElement>>(p);
	 }

	 Dictionary(pair<TKey, TElement>* p, int size)
	 {
		this->tree = new BinaryTree<pair<TKey, TElement>> (p, size);
	 }


	 ~Dictionary()
	 {
		delete this->tree;
		this->tree = nullptr;
	 }

	 int GetCount()
	 {
		 return this->tree->getSize();
	 }

	 TElement Get(TKey key)
	 {
		 pair<TKey, TElement> searchPair;
		 searchPair.key = key;
		 if (tree->search(searchPair))
			 return tree->getDataNode(tree->search(searchPair)).element;
		 else 
			 throw IndexOutOfRange();
	 }
	 TKey* GetKey(TKey key)
	 {
		 pair<TKey, TElement> searchPair;
		 searchPair.key = key;
		 if (tree->search(searchPair))
			 return &(tree->getDataNode(tree->search(searchPair)).key);
		 else return nullptr;
	 }
	 /*pair<TKey, TElement>* GetPointer(TKey key)
	 {
		 pair<TKey, TElement> searchPair;
		 searchPair.key = key;

		 if (tree->search(searchPair))
		 {
			
		 }
		 else
			 return nullptr;
	 }*/

	 bool ContainsKey(TKey key)
	 {
		 pair<TKey, TElement> searchPair;
		 searchPair.key = key;
		 if (tree->search(searchPair) == nullptr)
			 return false;
		 else
			 return true;
	 }

	 void Add(TKey key, TElement element)
	 {
		 pair<TKey, TElement> addPair;
		 addPair.key = key;
		 addPair.element = element;
		 this->tree->insert(addPair); 
	 }

	 void Remove(TKey key)
	 {
		 pair<TKey, TElement> removePair;
		 removePair.key = key;
		 this->tree->remove(removePair);
	 }

	 void Print()
	 {
		 this->tree->print();
	 }

	 void ChangeElement(TKey key, TElement newElement)
	 {
		 pair<TKey, TElement> pSearch{ key, 0 };
		 pair<TKey, TElement>* p = this->tree->getNode(pSearch);
		 p->element = newElement;
	 }
 };