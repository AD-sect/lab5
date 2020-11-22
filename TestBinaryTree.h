#pragma once
#include "BinaryTree.h"
#include <assert.h>

void testBinaryTree()
{
	int item1{ 8 };
	int items7[7]{ 228, 51, 600, 123, 1, 500, 649 };
	int items5[5]{ 327, 215, 400, 138, 150 };

	int subItems7[3]{ 51, 1, 123 };
	int subItems5[3]{ 215, 138, 150 };
	int subItems7_wrong[5]{ 123, 1, 51, 788, 8 };
	int subItems5_wrong[3]{ 568, 55, 3 };

	int item_insert1{ 7 };
	int item_insert2{ 700 };

	BinaryTree<int> tree0;
	BinaryTree<int> tree1(item1);
	BinaryTree<int> tree5(items5, 5);
	BinaryTree<int> tree7(items7, 7);

	BinaryTree<int>* subTree7 = new BinaryTree<int>(subItems7, 3);
	BinaryTree<int>* subTree5 = new BinaryTree<int>(subItems5, 3);
	BinaryTree<int>* subTree7_wrong = new BinaryTree<int>(subItems7_wrong, 3);
	BinaryTree<int>* subTree5_wrong = new BinaryTree<int>(subItems5_wrong, 3);
	BinaryTree<int>* subTree0 = new BinaryTree<int>{ nullptr };

	//тест поиска
	assert(tree0.search(item_insert1) == nullptr);

	assert(tree1.getDataNode(tree1.search(item1)) == item1);
	assert(tree1.search(89) == nullptr);

	assert(tree5.getDataNode(tree5.search(215)) == 215);
	assert(tree5.getDataNode(tree5.search(327)) == 327);
	assert(tree5.getDataNode(tree5.search(150)) == 150);
	assert(tree5.search(89) == nullptr);

	assert(tree7.getDataNode(tree7.search(600)) == 600);
	assert(tree7.getDataNode(tree7.search(228)) == 228);
	assert(tree7.getDataNode(tree7.search(1)) == 1);
	assert(tree7.search(89) == nullptr);

	//std::cout << "Search test: success." << std::endl;
	//тест вставки 
	tree0.insert(item_insert1);
	assert(tree0.getData() == item_insert1);
	assert(tree0.getSize() == 1);

	tree1.insert(item_insert1);
	assert(tree1.getDataNode(tree1.search(item_insert1)) == item_insert1);
	assert(tree1.getSize() == 2);
	tree1.insert(item_insert2);
	assert(tree1.getDataNode(tree1.search(item_insert2)) == item_insert2);
	assert(tree1.getSize() == 3);

	tree5.insert(item_insert1);
	assert(tree5.getDataNode(tree5.search(item_insert1)) == item_insert1);
	assert(tree5.getSize() == 6);
	tree5.insert(item_insert2);
	assert(tree5.getDataNode(tree5.search(item_insert2)) == item_insert2);
	assert(tree5.getSize() == 7);

	tree7.insert(item_insert1);
	assert(tree7.getDataNode(tree7.search(item_insert1)) == item_insert1);
	assert(tree7.getSize() == 8);
	tree7.insert(item_insert2);
	assert(tree7.getDataNode(tree5.search(item_insert2)) == item_insert2);
	assert(tree7.getSize() == 9);

	//std::cout << "Insert test: success." << std::endl;
	//тест удаления
	tree0.remove(item_insert1);
	assert(tree0.getRoot() == nullptr);
	assert(tree0.getSize() == 0);

	tree1.remove(item_insert1);
	assert(tree1.search(item_insert1) == nullptr);
	assert(tree1.getSize() == 2);
	tree1.remove(item_insert2);
	assert(tree1.search(item_insert2) == nullptr);
	assert(tree1.getSize() == 1);

	tree5.remove(item_insert1);
	assert(tree5.search(item_insert1) == nullptr);
	assert(tree5.getSize() == 6);
	tree5.remove(item_insert2);
	assert(tree5.search(item_insert2) == nullptr);
	assert(tree5.getSize() == 5);

	tree7.remove(item_insert1);
	assert(tree7.search(item_insert1) == nullptr);
	assert(tree7.getSize() == 8);
	tree7.remove(item_insert2);
	assert(tree5.search(item_insert2) == nullptr);
	assert(tree7.getSize() == 7);

	//std::cout << "Remove test: success." << std::endl;
	//тест поддерева

	assert(tree1.subTree(8)->getDataNode(tree1.search(8)) == 8);
	assert(tree1.subTree(8)->getSize() == 1);

	assert(tree5.subTree(4564)->getRoot() == nullptr);
	assert(tree5.subTree(215)->getDataNode(tree5.search(215)) == 215);
	assert(tree5.subTree(215)->getDataNode(tree5.search(138)) == 138);
	assert(tree5.subTree(215)->getDataNode(tree5.search(150)) == 150);
	assert(tree5.subTree(215)->getSize() == 3);

	assert(tree5.subTree(400)->getDataNode(tree5.search(400)) == 400);
	assert(tree5.subTree(400)->getSize() == 1);

	assert(tree7.subTree(4564)->getRoot() == nullptr);
	assert(tree7.subTree(600)->getDataNode(tree7.search(600)) == 600);
	assert(tree7.subTree(600)->getDataNode(tree7.search(500)) == 500);
	assert(tree7.subTree(600)->getDataNode(tree7.search(649)) == 649);
	assert(tree7.subTree(600)->getSize() == 3);

	assert(tree7.subTree(228)->getDataNode(tree7.search(228)) == 228);
	assert(tree7.subTree(228)->getDataNode(tree7.search(123)) == 123);
	assert(tree7.subTree(228)->getDataNode(tree7.search(1)) == 1);
	assert(tree7.subTree(228)->getDataNode(tree7.search(51)) == 51);
	assert(tree7.subTree(228)->getDataNode(tree7.search(600)) == 600);
	assert(tree7.subTree(228)->getDataNode(tree7.search(500)) == 500);
	assert(tree7.subTree(228)->getDataNode(tree7.search(649)) == 649);
	assert(tree7.subTree(228)->getSize() == 7);

	//std::cout << "Subtree test: success." << std::endl;
	//тест на вхождение поддерева
	assert(tree5.subTreeCheck(subTree5) == true);
	assert(tree5.subTreeCheck(subTree5_wrong) == false);
	assert(tree7.subTreeCheck(subTree7) == true);
	assert(tree7.subTreeCheck(subTree7_wrong) == false);

	//std::cout << "Subtree check test: success." << std::endl;
	//тест максимума и минимума
	assert(tree5.getMax(tree5.getRoot()) == 400);
	assert(tree7.getMax(tree7.getRoot()) == 649);

	assert(tree5.getMin(tree5.getRoot()) == 138);
	assert(tree7.getMin(tree7.getRoot()) == 1);

	assert(tree1.getMax(tree1.getRoot()) == 8);
	assert(tree1.getMin(tree1.getRoot()) == 8);

	//std::cout << "Maximum/mininmum test: success." << std::endl;
}
