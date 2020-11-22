#pragma once
#include "SortedSequence.h"
#include <assert.h>
#include "ArraySequence.h"

void test_GetLength( SortedSequence<int>* seq, int length)
{
	assert(seq->GetLength() == length);
}
void test_GetIsEmpty(SortedSequence<int>* seq, int rez)
{
	assert(seq->GetIsEmpty() == rez);
}
void test_Get(SortedSequence<int>* seq, int* check, int size)
{
	for (int i(0); i < size; i++)
		assert(check[i] == seq->Get(i));
	
}
void test_GetFirst(SortedSequence<int>* seq, int rez)
{
	assert(seq->GetFirst() == rez);
}
void test_GetLast(SortedSequence<int>* seq, int rez)
{
	assert(seq->GetLast() == rez);
}

void test_IndexOf(SortedSequence<int>* seq)
{
	for (int i(0); i < seq->GetLength(); i++)
		assert(seq->IndexOf(seq->Get(i)) == i);
}
void test_GetSubsequence(SortedSequence<int>* seq, int start, int end)
{
	SortedSequence<int>* testseq = seq->GetSubsequence(start, end);
	for (int i(start); i < start - end + 1; i++)
		assert(seq->Get(i) == testseq->Get(i));

}

void test_Add(SortedSequence<int>* seq, int prev, int next, int cur, int i)
{
	if (i == 0)
	{
		seq->Add(cur);
		assert(cur == seq->Get(i));
		assert(next == seq->Get(i + 1));
	}
	else if (i == seq->GetLength())
	{
		seq->Add(cur);
		assert(cur == seq->Get(i));
		assert(prev == seq->Get(i - 1));
	}
	else
	{
		seq->Add(cur);
		assert(cur == seq->Get(i));
		assert(next == seq->Get(i + 1));
		assert(prev == seq->Get(i - 1));
	}

}

void test_BinarySearch(SortedSequence<int>* seq, int rez, int check)
{
	assert(seq->BinarySearch(check) == rez);
}


void test_SortedSequence()
{
	int mas10[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Sequence<int>* test10 = new ArraySequence<int>(mas10, 10);
	SortedSequence<int> test10seq(test10);
	int* checkMas10 = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	
	Sequence<int>* testEmpty = new ArraySequence<int>;
	SortedSequence<int> testEmptyseq(testEmpty);
	

	int mas0[10]{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	Sequence<int>* test0 = new ArraySequence<int>(mas0, 10);
	SortedSequence<int> test0seq(test0);
	int* checkMas0 = new int[10]{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	int mas2[2]{ 558, 58 };
	Sequence<int>* test2 = new ArraySequence<int>(mas2, 2);
	SortedSequence<int> test2seq(test2);
	int* checkMas2 = new int[2]{ 58, 558 };

	int mas1[1]{ 3 };
	Sequence<int>* test1 = new ArraySequence<int>(mas1, 1);
	SortedSequence<int> test1seq(test1);
	int* checkMas1 = new int[1]{ 3 };

	int mas6[6]{ 6, 6, 6, 6, 6, 6 };
	Sequence<int>* test6 = new ArraySequence<int>(mas6, 6);
	SortedSequence<int> test6seq(test6);
	int* checkMas6 = new int[6]{ 6, 6, 6, 6, 6, 6 };

	int masNeg[8]{ -8888899, -897, -797, -99, -65, -15, -2, -1 };
	Sequence<int>* testNeg = new ArraySequence<int>(masNeg, 8);
	SortedSequence<int> testNegseq(testNeg);
	int* checkMasNeg = new int[8]{ -8888899, -897, -797, -99, -65, -15, -2, -1 };

	int masMix[5]{ -37, -15, -1, 99, 897 };
	Sequence<int>* testMix = new ArraySequence<int>(masMix, 5);
	SortedSequence<int> testMixseq(testMix);
	int* checkMasMix = new int[5]{ -37, -15, -1, 99, 897 };

	test_GetLength(&test10seq, 10);
	test_GetLength(&test0seq, 10);
	test_GetLength(&test1seq, 1);
	test_GetLength(&test6seq, 6);
	test_GetLength(&testNegseq, 8);
	test_GetLength(&testMixseq, 5);
	test_GetLength(&test2seq, 2);

	test_GetIsEmpty(&testEmptyseq, 0);
	test_GetIsEmpty(&test10seq, 1);
	test_GetIsEmpty(&test0seq, 1);
	test_GetIsEmpty(&test1seq, 1);
	test_GetIsEmpty(&test6seq, 1);
	test_GetIsEmpty(&test2seq, 1);

	test_Get(&test10seq, mas10, 10);
	test_Get(&test0seq, mas0, 10);
	test_Get(&test1seq, mas1, 1);
	test_Get(&test6seq, mas6, 6);
	test_Get(&testNegseq, masNeg, 8);
	test_Get(&testMixseq, masMix, 5);
	test_Get(&test2seq, mas2, 2);

	test_GetFirst(&test10seq, 1);
	test_GetFirst(&test0seq,0);
	test_GetFirst(&test1seq,3);
	test_GetFirst(&test6seq, 6);
	test_GetFirst(&testNegseq, -8888899);
	test_GetFirst(&testMixseq, -37);
	test_GetFirst(&test2seq, 558);

	test_GetLast(&test10seq, 10);
	test_GetLast(&test0seq, 0);
	test_GetLast(&test1seq, 3);
	test_GetLast(&test6seq, 6);
	test_GetLast(&testNegseq, -1);
	test_GetLast(&testMixseq, 897);
	test_GetLast(&test2seq, 58);

	test_IndexOf(&test10seq);
	test_IndexOf(&test1seq);
	test_IndexOf(&testNegseq);
	test_IndexOf(&testMixseq);
	test_IndexOf(&test2seq);

	test_GetSubsequence(&test10seq, 3, 8);
	test_GetSubsequence(&test10seq, 1, 5);
	test_GetSubsequence(&test10seq, 8, 9);
	test_GetSubsequence(&test0seq, 3, 8);
	test_GetSubsequence(&test0seq, 2, 6);
	test_GetSubsequence(&test6seq, 2, 4);
	test_GetSubsequence(&testNegseq, 1, 3);

	test_Add(&test10seq, 3, 4, 4, 3);
	test_Add(&test10seq, 7, 8, 7, 8);
	test_Add(&test0seq, 0, 0, -1, 0 );
	test_Add(&test0seq, 0, 0, 9, 11);
	test_Add(&testNegseq, -65, -15, -21, 5);
	test_Add(&testNegseq, -797, -99, -100, 3);
	test_Add(&testMixseq, -1, 99, 5, 3);

	
	test_BinarySearch(&test10seq, 2,  3);
	test_BinarySearch(&test10seq, -1, 78);
	test_BinarySearch(&test0seq, -1, 976);
	test_BinarySearch(&test1seq, 0, 3);
	test_BinarySearch(&test1seq, -1, 288);
	test_BinarySearch(&testNegseq, 0, -8888899);
	test_BinarySearch(&testNegseq, -1, 555);

}