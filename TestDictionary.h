#pragma once
#include "Dictionary.h"
#include <cassert>

void test_GetCount(Dictionary<int, int>* dict, int size)
{
	assert(dict->GetCount() == size);
}

void test_Get(Dictionary<int, int>* dict, int* keyMas, int* elementMas)
{
	for (int i(0); i < dict->GetCount(); i++)
		assert(dict->Get(keyMas[i]) == elementMas[i]);
}

void test_ContainsKey(Dictionary<int, int>* dict, int key, bool rez)
{
	assert(dict->ContainsKey(key) == rez);
}
void test_Add(Dictionary<int, int>* dict, int addKey, int addEl, int size)
{
	dict->Add(addKey, addEl);
	assert(dict->Get(addKey) == addEl);
	assert(dict->GetCount() == size);
}

void test_Remove(Dictionary<int, int>* dict, int removeKey, int size)
{
	dict->Remove(removeKey);
	assert(dict->GetCount() == size - 1);
}

void test_Dictionary()
{
	pair<int, int> pairs6[6]{ {1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {6,6} };
	Dictionary<int, int>  dict6(pairs6, 6);
	int key6Mas[6]{ 1,2,3,4,5,6 };
	int el6Mas[6]{ 1,2,3,4,5,6 };


	pair<int, int> pairs1[1]{ {8,47} };
	Dictionary<int, int>  dict1(pairs1, 1);
	int key1Mas[1]{ 8 };
	int el1Mas[1]{ 47 };


	pair<int, int> pairs2[2]{ {-15,-9},{6,12 } };
	Dictionary<int, int>  dict2(pairs2, 2);
	int key2Mas[2]{ -15,6 };
	int el2Mas[2]{ -9, 12 };

	pair<int, int> pairs8[8]{ {5,89}, {-788,56}, {1,1}, {4,62}, {15,-5}, {9,6},{3,18}, {96,0} };
	Dictionary<int, int>  dict8(pairs8, 8);
	int key8Mas[8]{ 5, -788, 1, 4, 15, 9, 3, 96 };
	int el8Mas[8]{89, 56, 1, 62, -5, 6, 18, 0 };


	test_GetCount(&dict6, 6);
	test_GetCount(&dict1, 1);
	test_GetCount(&dict2, 2);
	test_GetCount(&dict8, 8);

	test_Get(&dict6, key6Mas, el6Mas);
	test_Get(&dict1, key1Mas, el1Mas);
	test_Get(&dict2, key2Mas, el2Mas);
	test_Get(&dict8, key8Mas, el8Mas);

	test_ContainsKey(&dict6, 2, true);
	test_ContainsKey(&dict6, 79, false);
	test_ContainsKey(&dict1, 8, true);
	test_ContainsKey(&dict1, -456, false);
	test_ContainsKey(&dict2, -15, true);
	test_ContainsKey(&dict2, 1 , false);
	test_ContainsKey(&dict8, 96, true);
	test_ContainsKey(&dict8, 62, false);
	
	test_Add(&dict6, 15, 5, 7);
	test_Add(&dict6, 19, 5, 8);
	test_Add(&dict1, 2, 2, 2);
	test_Add(&dict1, 3, 2, 3);
	test_Add(&dict2, 79, 2, 3);
	test_Add(&dict2, 78, 55, 4);
	test_Add(&dict8, 111, 2, 9);
	test_Add(&dict8, -111, 7, 10);

	test_Remove(&dict6, 15, 8);
	test_Remove(&dict6, 7989, 8);
	test_Remove(&dict1, 2, 3);
	test_Remove(&dict1, 7989, 3);
	test_Remove(&dict2, 79, 4);
	test_Remove(&dict2, 7989, 4);
	test_Remove(&dict8, 111, 10);
	test_Remove(&dict8, 7989, 10);
}