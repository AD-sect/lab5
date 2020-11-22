#pragma once
#include "Matrix.h"
#include <assert.h>

void test_MatrixEl(Matrix* mat, int* mas)
{
	int i(0);
	for (int x(0); x < mat->GetRow(); x++)
	{
		for (int y(0); y < mat->GetCol(); y++)
		{
			assert(mat->Get(x, y) == mas[i]);
			i++;
		}
	}
}

void test_GetSize(Matrix* mat, int check)
{
	assert(mat->GetSize() == check);
}

void test_Set(Matrix* mat, int x, int y, int check)
{
	mat->Set(x, y, check);
	assert(mat->Get(x, y) == check);

}

void test_GetCol(Matrix* mat, int check)
{
	assert(mat->GetCol() == check);
}

void test_GetRow(Matrix* mat, int check)
{
	assert(mat->GetRow() == check);
}

void test_Matrix()
{
	int mas10[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Matrix m_10_2_5(mas10, 2, 5);
	Matrix* mat_10_2_5(&m_10_2_5);

	int mas12[12]{ 2, 8, 9, 56, 5, 89, 48, 692, 1, 0, 12 };
	Matrix m_12_6_2(mas12, 6, 2);
	Matrix* mat_12_6_2(&m_12_6_2);

	Matrix m_12_3_4(mas12, 3, 4);
	Matrix* mat_12_3_4(&m_12_3_4);

	Matrix m_12_4_3(mas12, 4, 3);
	Matrix* mat_12_4_3(&m_12_4_3);

	Matrix m_12_1_12(mas12, 1, 12);
	Matrix* mat_12_1_12(&m_12_1_12);

	int mas1[1]{ 3 };
	Matrix m_1_1_1(mas1, 1, 1);
	Matrix* mat_1_1_1(&m_1_1_1);

	int mas2[2]{ 3, 8 };
	Matrix m_2_2_1(mas2, 2, 1);
	Matrix* mat_2_2_1(&m_2_2_1);

	test_MatrixEl(mat_10_2_5, mas10);
	test_GetCol(mat_10_2_5, 2);
	test_GetRow(mat_10_2_5, 5);
	test_GetSize(mat_10_2_5, 10);

	test_MatrixEl(mat_12_6_2, mas12);
	test_GetCol(mat_12_6_2, 6);
	test_GetRow(mat_12_6_2, 2);
	test_GetSize(mat_12_6_2, 12);

	test_MatrixEl(mat_12_3_4, mas12);
	test_GetCol(mat_12_3_4, 3);
	test_GetRow(mat_12_3_4, 4);
	test_GetSize(mat_12_3_4, 12);

	test_MatrixEl(mat_12_4_3, mas12);
	test_GetCol(mat_12_4_3, 4);
	test_GetRow(mat_12_4_3, 3);
	test_GetSize(mat_12_4_3, 12);

	test_MatrixEl(mat_12_1_12, mas12);
	test_GetCol(mat_12_1_12, 1);
	test_GetRow(mat_12_1_12, 12);
	test_GetSize(mat_12_1_12, 12);

	test_MatrixEl(mat_1_1_1, mas1);
	test_GetCol(mat_1_1_1, 1);
	test_GetRow(mat_1_1_1, 1);
	test_GetSize(mat_1_1_1, 1);

	test_MatrixEl(mat_2_2_1, mas2);
	test_GetCol(mat_2_2_1, 2);
	test_GetRow(mat_2_2_1, 1);
	test_GetSize(mat_2_2_1, 2);

}