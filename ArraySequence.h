#pragma once
#include "DynamicArray.h"
#include "Sequence.h"

template <typename T>
class ArraySequence : public Sequence<T>
{
protected:
	DynamicArray<T>* m_mas{ nullptr };
public:
	ArraySequence() : Sequence<T>()
	{
		m_mas = new DynamicArray<T>();
	}

	ArraySequence(int size) : Sequence<T>()
	{
		m_mas = new DynamicArray<T>(size);
	}

	ArraySequence(T* items, int size) : Sequence<T>()
	{
		m_mas = new DynamicArray<T>(items, size);

	}

	virtual ~ArraySequence()
	{
		delete this->m_mas;
		this->m_mas = nullptr;
	}

	ArraySequence(Sequence<T>* seq)
	{
		this->m_mas = new DynamicArray<T>(seq->GetLength());
		for (size_t i(0); i < this->m_mas->GetSize(); ++i)
			this->m_mas->Set(i, seq->Get(i));
	}

	virtual T GetFirst() const override
	{
		if (this->m_mas->GetSize() == 0)
			throw IndexOutOfRange();

		return m_mas->Get(0);
	}

	virtual T GetLast() const override
	{

		if (this->m_mas->GetSize() == 0)
			throw IndexOutOfRange();

		return m_mas->Get(this->m_mas->GetSize() - 1);
	}

	virtual T Get(int index) const override
	{
		if (index < 0 || index == this->m_mas->GetSize() || index > this->m_mas->GetSize())
			throw IndexOutOfRange();

		return m_mas->Get(index);
	}

	virtual void Set(T item, int index) const override
	{
		this->m_mas->Set(index, item);
	}

	virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override
	{
		if (startIndex < 0 || endIndex < 0 || startIndex == this->m_mas->GetSize())
			throw IndexOutOfRange();
		if (endIndex == this->m_mas->GetSize() || startIndex > this->m_mas->GetSize())
			throw IndexOutOfRange();
		if (endIndex > this->m_mas->GetSize() || startIndex > endIndex)
			throw IndexOutOfRange();

		int index(endIndex - startIndex + 1);
		Sequence<T>* getSub = new ArraySequence(0);
		for (int i = 0; i < index; ++i)
			getSub->Prepend(this->m_mas->Get(i + startIndex));

		return getSub;
	}

	virtual int GetLength() const override
	{
		return this->m_mas->GetSize();
	}

	virtual void Append(T item) override
	{

		if (this->m_mas->GetSize() == 0)
		{
			this->m_mas->Resize(this->m_mas->GetSize() + 1);
			this->m_mas->Set(0, item);
		}
		else
		{
			this->m_mas->Resize(this->m_mas->GetSize() + 1);
			T item1 = this->m_mas->Get(0);
			T item2 = 0;

			for (int i(0); i < this->m_mas->GetSize() - 1; ++i)
			{
				item2 = item1;
				item1 = this->m_mas->Get(i + 1);
				this->m_mas->Set(i + 1, item2);
			}
			this->m_mas->Set(0, item);
		}

	}

	virtual void Prepend(T item) override
	{
		this->m_mas->Resize(this->m_mas->GetSize() + 1);
		this->m_mas->Set(this->m_mas->GetSize() - 1, item);
	}

	virtual void InsertAt(T item, int index) override
	{
		if (index < 0)
			throw IndexOutOfRange();

		if (index == 0)
		{
			ArraySequence<T>* newMas1 = new ArraySequence(0);
			newMas1->Prepend(item);
			for (int i(0); i < this->m_mas->GetSize(); ++i)
				newMas1->Prepend(this->m_mas->Get(i));
			this->m_mas = newMas1->m_mas;
		}
		else if (index == this->m_mas->GetSize())
		{
			ArraySequence<T>* newMas1 = new ArraySequence(0);
			for (int i(0); i < this->m_mas->GetSize(); ++i)
				newMas1->Prepend(this->m_mas->Get(i));
			newMas1->Prepend(item);
			this->m_mas = newMas1->m_mas;
		}
		else
		{
			ArraySequence<T>* leftMas = new ArraySequence{ 0 };
			for (int i = 0; i < index; ++i)
				leftMas->Prepend(this->m_mas->Get(i));

			leftMas->Prepend(item);

			ArraySequence<T>* rightMas = new ArraySequence(0);
			for (int i = index; i < this->m_mas->GetSize(); ++i)
				rightMas->Prepend(m_mas->Get(i));

			ArraySequence<T>* newMas = new ArraySequence(0);
			for (int i = 0; i < leftMas->GetLength(); ++i)
				newMas->Prepend(leftMas->Get(i));

			for (int i = 0; i < rightMas->GetLength(); ++i)
				newMas->Prepend(rightMas->Get(i));


			this->m_mas = newMas->m_mas;
		}
	}


	virtual ArraySequence <T>* Concat(Sequence<T>* mas) const override
	{
		int masSize = mas->GetLength();

		ArraySequence <T>* newMas = new ArraySequence(0);
		for (int i = 0; i < this->m_mas->GetSize(); ++i)
			newMas->Prepend(this->m_mas->Get(i));

		for (int i = 0; i < masSize; ++i)
			newMas->Prepend(mas->Get(i));

		this->m_mas->Resize(this->m_mas->GetSize() + masSize);
		for (int i(0); i < this->m_mas->GetSize(); i++)
			this->m_mas->Set(i, newMas->Get(i));

		return newMas;
	}

	virtual void Print() const override
	{
		this->m_mas->Print();
	}

};
