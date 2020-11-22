#pragma once
#include "SortedSequence.h"
#include "Dictionary.h"


class SearchRepetitiveSeq
{
private:
	pair<std::string, int> maxPair{ "0", 0 };
	Dictionary<std::string, int>* dict;

public:

	SearchRepetitiveSeq( Sequence<char>* seq, int Lmin, int Lmax)
	{
		this->maxPair.key = "0";
		this->maxPair.element = 0;
		this->dict = PreficsDict(seq, Lmin, Lmax);
	}

	~SearchRepetitiveSeq()
	{
		this->dict = nullptr;
		maxPair.key = "0";
		maxPair.element = 0;
	}

	Dictionary<std::string, int>* PreficsDict(Sequence<char>* seq, int Lmin, int Lmax)
	{
		int maxCount(1);
		std::string maxStr("");

		int size(1);
		Dictionary<std::string, int>* dict{ nullptr };
		Sequence<char>* subStr{ nullptr };
		std::string subString{ "aaaaa" };
		
		for (int i(0); i < seq->GetLength(); i++)
		{
			for (int j (Lmin - 1); j < Lmax
				&& i + j < seq->GetLength(); j++)
			{
				subStr = seq->GetSubsequence(i, j + i);

				subString.clear();
				for (int i = 0; i < subStr->GetLength(); i++)
					subString.append(1, subStr->Get(i));

				if(dict == nullptr)
					dict = new Dictionary<std::string, int>(subString, 1);
				else if (!dict->ContainsKey(subString))
					dict->Add(subString, 1);
				else
				{
					size = dict->Get(subString) + 1;
					dict->ChangeElement(subString, size);
			
					if (size > maxCount)
					{
						maxCount = size;
						maxStr = subString;
					}
				}
			}
		}
		pair<std::string, int> p;
		if (maxCount != 1)
		{
			p.key = maxStr;
			p.element = maxCount;
			this->maxPair = p;
		}
		else
		{
			p.key = "equal numbers";
			p.element = 1;
			this->maxPair = p;
		}
		return dict;
	}

	pair<std::string, int> GetPair()
	{
		return this->maxPair;
	}

	std::string GetMaxStr()
	{
		return this->maxPair.key;
	}

	int GetMaxCount()
	{
		return this->maxPair.element;
	}

	Dictionary<std::string, int>* GetDict()
	{
		return this->dict;
	}

	void Print()
	{
		this->dict->Print();
	}

};
