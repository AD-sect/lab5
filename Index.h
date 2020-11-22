#pragma once
#include "Dictionary.h" 
#include"Sequence.h"

template <class T>
class Index
{
private:

	Dictionary<std::string, int>* dict{ nullptr };
	int count{ 0 };
	
public:

Index(std::string str, int count)
{
	dict = MakeDictionary(str, count);
	this->count = count;
}

~Index()
{
	dict = nullptr;
}

Dictionary<std::string, int>* GetDict()
{
	return this->dict;
}


Dictionary<std::string, int>* MakeDictionary( std::string str, int count)
{
	pair<std::string, int> p;
	Dictionary<std::string, int>* dictMas = new Dictionary<std::string, int>(p);
	dictMas->Remove("");
	std::string copyStr;

	int i(0);
	int k(0);
	int pos(0);
	int page(1);
	int wordSize(0);
	while( i < str.length())
	{
		if (str[i] == ' ')
		{
			if (pos == 0)
				copyStr = str.substr(pos, i);
			else
				copyStr = str.substr(pos + 1, i - pos - 1);

			wordSize++;
			k++;
			pos = i;

			if (page == 1)
			{
				if (k != ((count / 2) + 1))
					dictMas->Add(copyStr, page);
				else 
				{
					page++;
					dictMas->Add(copyStr, page);
					k = 0;
				}
			}
			else if (page % 10 != 0)
			{
				if (k != count)
					dictMas->Add(copyStr, page);
				else
				{
					page++;
					dictMas->Add(copyStr, page);
					k = 0;
				}
			}
			else
			{
				if (k != ((count * 3 / 4)))
					dictMas->Add(copyStr, page);
				else
				{
					page++;
					dictMas->Add(copyStr, page);
					k = 0;
				}
			}
			copyStr = "";
		}
		i++;
	}

	return dictMas;
}

int GetPageSize(std::string str)
{
	int k(0);
	int page(0);
	for (int i(0); i < str.length(); i++)
	{
		if (this->str[i] == ' ')
		{
			k++;
			if (k == this->count)
			{
				page++;
				k = 0;
			}
		}
	}
	if (GetWordSize() % this->count != 0)
		page++;
	return page;
}

int GetWordSize(std::string str)
{
	int i(0);
	int size(0);
	while (i < str.length())
	{
		if (str[i] != ' ')
			i++;
		else
		{
			size++;
			i++;
		}
	}
	return size + 1;	
}

void Print()
{
	dict->Print();
}
};
