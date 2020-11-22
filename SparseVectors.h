#pragma once
#include "Dictionary.h"
#include "Sequence.h"
#include"ArraySequence.h"
#include"Matrix.h"

template<class TKey, class TElement>
struct pair_for_matrix
{
	TKey key;
	TElement element;
};

template<class TKey, class TElement>
std::ostream& operator<< (std::ostream& out, const pair_for_matrix<TKey, TElement>& p)
{
	out << p.key << " " << p.element << " ";
	return out;
}

template<class TKey, class TElement>
bool operator>= (const pair_for_matrix<TKey, TElement>& p1, const pair_for_matrix<TKey, TElement>& p2)
{
	if (p1.key >= p2.key || p1.element >= p2.element)
		return  true;
	else
		return false;
}

template<class TKey, class TElement>
bool operator<= (const TKey key, const pair_for_matrix<TKey, TElement>& p2)
{
	return key <= p2.key;
}

template<class TKey, class TElement>
bool operator<= (const pair_for_matrix<TKey, TElement>& p1, const pair_for_matrix<TKey, TElement>& p2)
{
	if (p1.key <= p2.key && p1.element <= p2.element)
		return  true;
	else
		return false;
}
template<class TKey, class TElement>

bool operator< (const pair_for_matrix<TKey, TElement>& p1, const pair_for_matrix<TKey, TElement>& p2)
{
	if (p1.key < p2.key  || (p1.key == p2.key && p1.element < p2.element))
		return  true;
	else
		return false;
}

template<class TKey, class TElement>
bool operator> (const pair_for_matrix<TKey, TElement>& p1, const pair_for_matrix<TKey, TElement>& p2)
{
	if (p1.key > p2.key  || (p1.key == p2.key && p1.element > p2.element))
		return  true;
	else
		return false;
}

template<class T>
class SparseVectors
{
private:
	Dictionary<T, int>* dict{ nullptr };
	int size{ 0 };
	int col{ 0 };
	int row{ 0 };
public:

	SparseVectors(Sequence<int>* vec)
	{
		this->size = vec->GetLength();
		for (int i(0); i < this->size; i++)
		{
			if (vec->Get(i) != 0)
			{
				if (this->dict == nullptr)
					this->dict = new Dictionary<int, int>(i, vec->Get(i));
				else
					this->dict->Add(i, vec->Get(i));
			}
		}
	}

	SparseVectors(Matrix* matrix)
	{
		this->size = matrix->GetSize();
		pair_for_matrix<int, int> p{ 0, 0 };
		
		for (int x(0); x < matrix->GetRow(); x++)
		{
			for (int y(0); y < matrix->GetCol(); y++)
			{
				p.key = x;
				p.element = y;
				if (matrix->Get(x, y) != 0)
				{
					if (this->dict == nullptr)
						this->dict = new Dictionary<pair_for_matrix<int, int>, int>(p, matrix->Get(x, y));
					else
						this->dict->Add(p, matrix->Get(x, y));
				}
			}
		}
		this->col = matrix->GetCol();
		this->row = matrix->GetRow();
	}

	~SparseVectors()
	{
		delete this->dict;
		this->dict == nullptr;
	}

	Dictionary<T, int>* GetDict()
	{
		return this->dict;
	}

	int GetSize()
	{
		return this->size;
	}

	Sequence<int>* GetVector()
	{
		Sequence<int>* vec = new ArraySequence<int>;
		for (int i(0); i < this->size; i++)
		{
			if (dict->ContainsKey(i))
				vec->InsertAt(dict->Get(i), i);
			else
				vec->InsertAt(0, i);
		}
		return vec;
	}

	Matrix* GetMatrix()
	{
		pair_for_matrix<int, int> p{ 0,0 };
		Matrix* matrix = new Matrix(this->col, this->row);

		for (int x(0); x < this->row; x++)
		{
			for (int y(0); y < this->col; y++)
			{
				p.element = y;
				p.key = x;
		
				if (this->dict->ContainsKey(p))
						matrix->Set(x, y, this->dict->Get(p));
				else
					matrix->Set(x, y, 0);
			}
		}
		return matrix;
	}

	void Print()
	{
		this->dict->Print();
	}
};
