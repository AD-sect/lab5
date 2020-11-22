#pragma once
#include "SparseVectors.h"
#include "Dictionary.h"
#include <assert.h>

void test_Vector(SparseVectors<int>* vec, Dictionary<int, int>* checkDict, int* mas)
{
	if(vec->GetDict() != nullptr)
	for (int i(0); i < checkDict->GetCount(); i++)
		assert(vec->GetDict()->Get(mas[i]) == checkDict->Get(mas[i]));
}

void test_GetVector(SparseVectors<int>* vec, int* mas)
{
	for (int i(0); i < vec->GetSize(); i++)
		assert(vec->GetVector()->Get(i) == mas[i]);
}

void test_Mat(Dictionary<pair_for_matrix<int, int>, int>* matrix,
	Dictionary<pair_for_matrix<int, int>, int>* checkDict, pair_for_matrix<int, int>* mas)
{
	pair_for_matrix<int, int> p{ 0,0 };
	for (int i(0); i < checkDict->GetCount(); i++)
	{
		p.element = mas[i].element;
		p.key = mas[i].key;
		assert(matrix->Get(p) == checkDict->Get(p));
	}
}

void test_GetMatrix(SparseVectors<pair_for_matrix<int, int>>* mat, Matrix* checkMatrix)
{
	Matrix* matrix(mat->GetMatrix());
	for (int x(0); x < checkMatrix->GetRow(); x++)
		for (int y(0); y < checkMatrix->GetCol(); y++)
			assert(matrix->Get(x, y) == checkMatrix->Get(x, y));
}

void test_GetSize(SparseVectors<pair_for_matrix<int, int>>* mat, int size)
{
	assert(mat->GetSize() == size);
}

void test_GetSize(SparseVectors<int>* mat, int size)
{
	assert(mat->GetSize() == size);
}

void test_SparseVector_Vector()
{
	int mas10[10]{ 0, 0, 0, 0 ,0 ,1, 7, 8, 9, 0 };
	Sequence<int>* seq10 = new ArraySequence<int>(mas10, 10);
	SparseVectors<int> vec10(seq10);
	int mas10Check[4]{5, 6, 7, 8 };

	Dictionary<int, int> dict10(5, 1);
	dict10.Add(6, 7);
	dict10.Add(7, 8);
	dict10.Add(8, 9);

	int mas2[2]{ 45, 0 };
	Sequence<int>* seq2 = new ArraySequence<int>(mas2, 2);
	SparseVectors<int> vec2(seq2);
	Dictionary<int, int> dict2(0, 45);
	int mas2Check[1]{ 0 };

	int mas14[14]{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
	Sequence<int>* seq14 = new ArraySequence<int>(mas14, 14);
	SparseVectors<int> vec14(seq14);
	Dictionary<int, int> dict14(13, 1);
	int mas14Check[1]{ 13 };

	int mas6[6]{ 0, 0, 0, 0, 0, 0 };
	Sequence<int>* seq6 = new ArraySequence<int>(mas6, 6);
	SparseVectors<int> vec6(seq6);
	Dictionary<int, int> dict6(0, 0);
	int mas6Check[1]{ 0 };

	int mas8[8]{ 1, 1, 1, 1, 1, 1, 1, 1 };
	Sequence<int>* seq8 = new ArraySequence<int>(mas8, 8);
	SparseVectors<int> vec8(seq8);
	int mas8Check[8]{ 0, 1, 2, 3, 4, 5, 6, 7 };

	Dictionary<int, int> dict8(0, 1);
	dict8.Add(1, 1);
	dict8.Add(2, 1);
	dict8.Add(3, 1);
	dict8.Add(4, 1);
	dict8.Add(5, 1);
	dict8.Add(6, 1);
	dict8.Add(7, 1);
	
	test_Vector(&vec10, &dict10, mas10Check);
	test_Vector(&vec2, &dict2, mas2Check);
	test_Vector(&vec14, &dict14, mas14Check);
	test_Vector(&vec6, &dict6, mas6Check);
	test_Vector(&vec8, &dict8, mas8Check);

	test_GetVector(&vec10, mas10);
	test_GetVector(&vec2, mas2);
	test_GetVector(&vec14, mas14);
	test_GetVector(&vec8, mas8);
	
	test_GetSize(&vec10, 10);
	test_GetSize(&vec2, 2);
	test_GetSize(&vec14, 14);
	test_GetSize(&vec6, 6);
	test_GetSize(&vec8, 8);
}

void test_SparseVector_Matrix()
{
	int mas10[10]{ 0, 0, 0, 0 ,0 ,1, 7, 8, 9, 0 };
	Matrix matrix10(mas10, 2, 5);
	SparseVectors<pair_for_matrix<int, int>> m10(&matrix10);

	pair_for_matrix<int, int> checkMas10[4]{ {2, 1}, {3, 0},{3, 1}, {4, 0} };
	Dictionary<pair_for_matrix<int, int>, int> dict10(checkMas10[0], 1);
	dict10.Add(checkMas10[1], 7);
	dict10.Add(checkMas10[2], 8);
	dict10.Add(checkMas10[3], 9);

	int mas2[2]{ 45, 0 };
	Matrix matrix2(mas2, 1, 2);
	SparseVectors<pair_for_matrix<int, int>> m2(&matrix2);

	pair_for_matrix<int, int> checkMas2[1]{ {0, 0} };
	Dictionary<pair_for_matrix<int, int>, int> dict2(checkMas2[0], 45);

	int mas14[14]{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
	Matrix matrix14(mas14, 7, 2);
	SparseVectors<pair_for_matrix<int, int>> m14(&matrix14);

	pair_for_matrix<int, int> checkMas14[1]{ {1, 6} };
	Dictionary<pair_for_matrix<int, int>, int> dict14(checkMas14[0], 1);

	int mas8[8]{ 1, 1, 1, 1, 1, 1, 1, 1 };
	Matrix matrix8(mas8, 2, 4);
	SparseVectors<pair_for_matrix<int, int>> m8(&matrix8);

	pair_for_matrix<int, int> checkMas8[8]{ {0, 0}, {0, 1}, {1, 0}, {1, 1}, {2, 0}, {2, 1}, {3, 0}, {3, 1} };

	Dictionary<pair_for_matrix<int, int>, int> dict8(checkMas8[0], 1);
	dict8.Add(checkMas8[1], 1);
	dict8.Add(checkMas8[2], 1);
	dict8.Add(checkMas8[3], 1);
	dict8.Add(checkMas8[4], 1);
	dict8.Add(checkMas8[5], 1);
	dict8.Add(checkMas8[6], 1);
	dict8.Add(checkMas8[7], 1);

	test_Mat(m10.GetDict(), &dict10, checkMas10);
	test_Mat(m2.GetDict(), &dict2, checkMas2);
	test_Mat(m14.GetDict(), &dict14, checkMas14);
	test_Mat(m8.GetDict(), &dict8, checkMas8);

	test_GetMatrix(&m10, &matrix10);
	test_GetMatrix(&m2, &matrix2);
	test_GetMatrix(&m14, &matrix14);
	test_GetMatrix(&m8, &matrix8);
	
	test_GetSize(&m10, 10);
	test_GetSize(&m2, 2);
	test_GetSize(&m14, 14);
	test_GetSize(&m8, 8);

	//std::cout << "love me love me, say what you love me";
}





