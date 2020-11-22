#pragma once
#include "LinkedList.h"
#include "Sequence.h"
#include "Exception.h"

template <typename T>
class LinkedListSequence : public Sequence<T>
{
protected:
	LinkedList<T>* list;
public:
	LinkedListSequence() : Sequence<T>()
	{
		list = new LinkedList<T>();
	}

	LinkedListSequence(T* items, int count) : Sequence<T>()
	{
		list = new LinkedList<T>(items, count);
	}


	LinkedListSequence(int count) : Sequence<T>()
	{
		list = new LinkedList<T>(count);
	}

	virtual ~LinkedListSequence()
	{
		delete this->list;
		this->list = nullptr;
	}

	LinkedListSequence(const LinkedListSequence<T>* seq)
	{
		this->list = seq->list;
	}

	virtual T GetFirst() const override
	{
		if (list->GetLength() == 0)
			throw IndexOutOfRange();

		return list->GetFirst();
	}

	virtual T GetLast() const override
	{
		if (list->GetLength() == 0)
			throw IndexOutOfRange();

		return list->GetLast();
	}

	virtual T Get(int index) const override
	{
		if (index < 0 || index == list->GetLength() || index > list->GetLength())
			throw IndexOutOfRange();

		return list->Get(index);
	}

	virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override
	{
		if (startIndex < 0 || endIndex < 0 || startIndex == list->GetLength() || endIndex == list->GetLength() || startIndex > list->GetLength() || endIndex > list->GetLength() || startIndex > endIndex)
			throw IndexOutOfRange();

		LinkedList<T>* subList = this->list->GetSubList(startIndex, endIndex);
		Sequence<T>* subSeq = new LinkedListSequence<T>();
		for (int i(0); i < subList->GetLength(); ++i)
		{
			subSeq->Prepend(subList->Get(i));
		}

		return subSeq;
	}

	virtual int GetLength() const override
	{
		return list->GetLength();
	}

	virtual void Append(T item) override
	{
		return list->Append(item);
	}

	virtual void Prepend(T item) override
	{
		return list->Prepend(item);
	}

	virtual void InsertAt(T item, int index)  override
	{
		if (index < 0 || index == list->GetLength() || index > list->GetLength())
			throw IndexOutOfRange();

		return this->list->InsertAt(item, index);
	}

	virtual LinkedListSequence<T>* Concat(Sequence <T>* list) const override
	{
		LinkedListSequence<T>* concatSeq = new LinkedListSequence<T>();

		int size{ this->list->GetLength() };

		for (int i(0); i < size; i++)
			concatSeq->Prepend(this->list->Get(i));

		for (int i(0); i < list->GetLength(); i++)
			concatSeq->Prepend(list->Get(i));

		for (int i(0); i < list->GetLength(); i++)
			this->list->Prepend(concatSeq->Get(i + size));

		return concatSeq;
	}

	virtual void Print() const override
	{
		for (int i(0); i < this->list->GetLength(); ++i)
		{
			if (i % 10 == 0 && i != 0)
				std::cout << this->list->Get(i) << " " << std::endl;
			else
				std::cout << this->list->Get(i) << " ";
		}
	}

	virtual void Set(T item, int index) const override
	{
		this->list->Set(item, index);
	}
};
