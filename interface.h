#pragma once
#include "SortedSequence.h"
#include "Sequence.h"
#include "ArraySequence.h"
#include <stdlib.h>
#include "TestSortedSequence.h"
#include "Dictionary.h"
#include "TestDictionary.h"
#include "Index.h"
#include "TestIndex.h"
#include "SearchRepetitiveSeq.h"
#include "TestSearchRepetitiveSeq.h"
#include "SparseVectors.h"
#include "Matrix.h"
#include "TestMatrix.h"
#include "TestSparseVector.h"
#include "TestBinaryTree.h"


void interface()
{
	int choice{ 0 };
	std::cout << "*** TASKS ***" << std::endl;
	bool exit{ false };

	while (!exit)
	{

		SparseVectors<int>* vector{ nullptr };
		SparseVectors<pair_for_matrix<int, int>>* matrix{ nullptr };
		SearchRepetitiveSeq* repSeq{ nullptr };
		Index<std::string>* index{ nullptr };

		std::cout << " " << std::endl;
		std::cout << "Choose the task:" << std::endl <<
			"1. Find repetitive sequense" << std::endl <<
			"2. Make sparse vector" << std::endl <<
			"3. Make index" << std::endl <<
			"4. See the test results" << std::endl <<
			"5. Exit" << std::endl;

		std::cin >> choice;

		int size{ 0 };
	
		switch(choice)
		{
		case 1:
		{
			std::cout << " Write the size of your sequence: " << std::endl;
			std::cin >> size;
			char letter('a');

			char* mas = new char[size];
			std::cout << " Write the sequence: " << std::endl;
			for (int i(0); i < size; i++)
			{
				std::cin >> letter;
				mas[i] = letter;
			}

			int lowBorder(0);
			int highBorder(0);
			std::cout << " Write range: " << std::endl;
			std::cout << " From: ";
			std::cin >> lowBorder;
			std::cout << " To: ";
			std::cin >> highBorder;
			std::cout << "  " << std::endl;

			ArraySequence<char> arr(mas, size);
			Sequence<char>* seq = &arr;
			repSeq = new SearchRepetitiveSeq(seq, lowBorder, highBorder);

			std::cout << "The most repetitive sequence: " << std::endl;
			std::cout << "Sequense: " << repSeq->GetMaxStr() << std::endl;
			std::cout << "Quontaty: " << repSeq->GetMaxCount() << std::endl;

			std::cout << " To display dictionary?" << std::endl;
			std::cout << " 1.Yes " << std::endl << " 2.No" << std::endl;
			std::cin >> size;

			if (size == 1)
				repSeq->Print();
		}
			break;

		case 2:
		{
			std::cout << " Matrix or vector?" << std::endl;
			std::cout << " 1.Matrix" << std::endl << " 2.Vector" << std::endl;
			std::cin >> choice;

			if (choice != 1 && choice != 2)
			{
				std::cout << " WRONG CHOISE" << std::endl;
				break;
			}

			std::cout << " Write quontaty of element: " << std::endl;
			std::cin >> size;

			int* mas = new int[size];

			if (choice == 1)
			{
				int element(0);
				int coll(0);
				int row(0);
				std::cout << " Write collumns and rows:" << std::endl;
				std::cout << " Collumns:";
				std::cin >> coll;
				std::cout << " Rows:";
				std::cin >> row;

				if( coll * row != size)
				{
					std::cout << " WRONG SIZE" << std::endl;
					break;
				}

				std::cout << " Write elements:"  << std::endl;
				for (int i(0); i < size; i++)
				{
					std::cin >> element;
					mas[i] = element;
				}

				Matrix mat(mas, coll, row);
				matrix = new SparseVectors<pair_for_matrix<int, int>>(&mat);

				std::cout << " The sparse matrix: " << std::endl;
				std:: cout << "x y  el" << std::endl;
				matrix->Print();

				std::cout << " To display the matrix?" << std::endl;
				std::cout << " 1.Yes" << std::endl << " 2.No" << std::endl;
				std::cin >> element;

				if (element == 1)
				{
					std::cout << " Matrix" << std::endl;
					matrix->GetMatrix()->Print();
				}
					
				if (element != 1 && element != 2)
					std::cout << " WRONG CHOISE" << std::endl;
			}
			if (choice == 2)
			{
				int element(0);
				std::cout << " Write elements:" << std::endl;
				for (int i(0); i < size; i++)
				{
					std::cin >> element;
					mas[i] = element;
				}
				ArraySequence<int> arr(mas, size);
				Sequence<int>* seq(&arr);
				vector = new SparseVectors<int>(seq);

				std::cout << " The sparse vector: " << std::endl;
				std::cout << "x el" << std::endl;
				vector->Print();

				std::cout << " To display the vector?" << std::endl;
				std::cout << " 1.Yes" << std::endl << " 2.No" << std::endl;
				std::cin >> element;

				if (element == 1)
				{
					std::cout << " The Vector:" << std::endl;
					vector->GetVector()->Print();
				}
				if (element != 1 && element != 2)
					std::cout << " WRONG CHOISE" << std::endl;
			}
		}
			break;

		case 3:
		{
			std::cout << " Write the quontaty of words:" << std::endl;
			std::cin >> size;
			std::string s{ "" };
			std::string str{ "" };
			std::cout << " Write the words:" << std::endl;
			for (int i(0); i < size; i++)
			{
				std::cin >> s;
				str.append(s);
				str.push_back(' ');
			}

			index = new Index<std::string>(str,  size);
			std::cout << " Alphabetical index:" << std::endl;
			index->Print();
		}
			break;

		case 4:
			testBinaryTree();
			test_Dictionary();
			test_index();
			test_Matrix();
			test_SearchRepetitiveSeq();
			test_SortedSequence();
			test_SparseVector_Matrix();
			test_SparseVector_Vector();

			std::cout << " ALL THE TESTS WORKED SUCSESSFULLY" << std::endl;

			break;

		case 5:
			std::cout << "Goodbye!" << std::endl;
			exit = true;
			break;

		default:
			std::cout << "WRONG CHOISE";
		}
		std::cout << std::endl << std::endl;
	}
}











