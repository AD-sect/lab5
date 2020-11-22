#pragma once
#include <iostream>
#include "Exception.h"

template < typename T>
class LinkedList
{
private:
	struct Node
	{
		T values = 0;
		Node* next = nullptr;
	};
	Node* head = nullptr;
	int count = 0;

public:

	LinkedList() = default;

	LinkedList(T* items, int count)
	{
		if (count < 0)
			throw IndexIsNegative();
		if (count == 0)
			throw NodeIsEmpty();
		head = new Node{ *items, nullptr };

		for (ptrdiff_t i(1); i < count; i++)
			head = new Node{ *(items + i), head };

		this->count = count;
	}

	LinkedList(int count)
	{
		if (count < 0)
			throw IndexIsNegative();
		if (count == 0)
			throw NodeIsEmpty();

		head = new Node{ 0, nullptr };

		for (ptrdiff_t i(1); i < count; i++)
			head = new Node{ 0, head };


		this->count = count;
	}

	LinkedList(LinkedList <T> const& list)
	{
		Node* it{ head };
		Node* copyList{ it };


		for (ptrdiff_t i(1); i < count; ++i, it = it->next)
		{
			copyList = new Node{ it->values, copyList };
		}
		this->count = count;
	}

	LinkedList(LinkedList<T>* list)
	{
		this->list = list;
		this->count = list->GetLength();
	}

	~LinkedList()
	{
		while (this->head != nullptr)
		{
			Node* buffer{ head->next };
			delete[] head;
			this->head = buffer;
		}
		delete[] this->head;
		this->head = nullptr;
	}

	T GetFirst()
	{
		if (count == 0)
			throw IndexOutOfRange();
		return head->values;

	}

	T GetLast()
	{
		if (count == 0)
			throw IndexOutOfRange();
		Node* it{ head };
		for (ptrdiff_t i(0); i < count - 1; ++i, it = it->next);
		return it->values;

	}

	T Get(int index)
	{
		if (index < 0 || index > count || index == count)
			throw IndexOutOfRange();

		Node* it{ head };
		for (ptrdiff_t i(0); i < index; ++i, it = it->next);
		return it->values;
	}


	LinkedList<T>* GetSubList(int startIndex, int endIndex)
	{
		if (startIndex < 0 || endIndex < 0 || startIndex == count || endIndex == count || startIndex > count || endIndex > count || startIndex > endIndex)
			throw IndexOutOfRange();
		Node* it{ head };
		for (ptrdiff_t i(0); i < startIndex - 1; ++i, it = it->next);
		LinkedList<T>* newNode = new LinkedList<T>;

		for (ptrdiff_t i(startIndex); i < endIndex + 1; ++i)
		{
			newNode->Prepend(it->values);
			it = it->next;
		}
		newNode->count = endIndex - startIndex + 1;

		return newNode;
	}

	int GetLength()
	{
		return count;
	}

	void Append(T item)
	{

		if (head == nullptr)
			head = new Node{ item, head };

		if (head != nullptr)
			head = new Node{ item, head };

		++this->count;
	}

	void Prepend(T item)
	{
		if (head != nullptr)
		{
			Node* it{ head };
			for (int i(1); i < count; ++i, it = it->next);
			it->next = new Node{ item, nullptr };
		}

		if (head == nullptr)
			head = new Node{ item, head };

		++count;
	}

	void InsertAt(T item, int index)
	{
		if (index < 0 || index == count || index > count)
			throw IndexOutOfRange();

		Node* it{ head };
		for (ptrdiff_t i(0); i < index - 1; ++i, it = it->next);

		Node* newNode;
		newNode = new Node{ item, it->next };
		it->next = newNode;

		this->count = this->count + 1;
	}


	LinkedList<T>* Concat(LinkedList<T>* list)
	{
		Node* it1{ this->head };
		LinkedList<T>* newList = new LinkedList<T>();

		for (int i(0); i < this->count; ++i)
		{
			newList->Prepend(it1->values);
			it1 = it1->next;
		}

		Node* it2{ list->head };
		for (int i(0); i < list->count; ++i)
		{
			newList->Prepend(it2->values);
			it2 = it2->next;
		}
		newList->count = this->count + list->count;

		return newList;
	}

	void Set(T item, int index)
	{
		Node* tmp{ nullptr };
		Node* it = head;
		for (int i = 0; i < index; i++)
			it = it->next;

		tmp = it;
		tmp->values = item;

	}

};
