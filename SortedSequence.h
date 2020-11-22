#pragma once
#include "Sequence.h"

template <class T>
class SortedSequence
{
	private:
		Sequence<T>* seq{ nullptr };
	public:
	
		SortedSequence() = default;
		SortedSequence(Sequence<T>* seq, Sequence <T>* (*sort)(Sequence<T>*, int), int size)
		{
			this->seq = sort(seq, size);
		}
		SortedSequence(Sequence<T>* seq )
		{
			this->seq = seq;
		}
		SortedSequence(Sequence<T>* seq, int size)
		{
			this->seq = seq;
		}
		SortedSequence(SortedSequence<T> const& seq )
		{
			for (int i(0); i < seq.GetLength(); i++)
				this->seq->Add(seq.Get(i));
		}

		~SortedSequence() 
		{
			delete this->seq;
			this->seq = nullptr;
		}

		int GetLength()
		{
			return this->seq->GetLength();
		}

		int GetIsEmpty()
		{
			if (this->seq->GetLength() >= 1)
				return 1;
			else
				return 0;
		}

		T Get(int index)
		{
			return this->seq->Get(index);
		}

		T GetFirst()
		{
			return this->seq->GetFirst();
		}
		
		T GetLast()
		{
			return this->seq->GetLast();
		}

		int IndexOf(T element)
		{
			for (int i(0); i < this->seq->GetLength(); i++)
				if (this->seq->Get(i) == element)
					return i;
			return -1;
		}
		
		SortedSequence<T>* GetSubsequence(int startIndex, int endIndex)
		{
			Sequence<T>* subSeq = this->seq->GetSubsequence(startIndex, endIndex);
			SortedSequence<T>* subSeqSorted = new SortedSequence<T>(subSeq , endIndex - startIndex );
			return subSeqSorted;
		}

		void Add(T element)//основан на бинаронм поиске последнего элемента, меньшего element
		{
			int leftBorder(0);
			int rightBorder(this->seq->GetLength() - 1);
			int middle(0);

			bool flag(true);
			while (leftBorder < rightBorder)
			{
				middle = leftBorder + (rightBorder - leftBorder) / 2;

				if (this->seq->Get(middle) < element)
					leftBorder = middle + 1;
				else if (this->seq->Get(middle) > element)
					rightBorder = middle;
				else
				{
					flag = false;
					break;
				}
			}
			if (flag == true)
			{
				if (leftBorder == (seq->GetLength() - 1))
					this->seq->InsertAt(element, leftBorder + 1);
				else
					this->seq->InsertAt(element, leftBorder);
			}
					

			else
				this->seq->InsertAt(element, middle );
		}

		int BinarySearch(T element)
		{
			int leftBorder(0);
			int rightBorder(this->seq->GetLength() - 1);
			int middle(0);

			bool flag(false);
			while (leftBorder <= rightBorder)
			{
				middle = leftBorder + (rightBorder - leftBorder) / 2;

				if (this->seq->Get(middle) < element)
					leftBorder = middle + 1;
				else if (this->seq->Get(middle) > element)
					rightBorder = middle - 1;
				else
				{
					flag = true;
					break;
				}
			}
			if (flag == true)
				return middle;
			else
				return -1;
		
		}

		void Print()
		{
			this->seq->Print();
		}

};
