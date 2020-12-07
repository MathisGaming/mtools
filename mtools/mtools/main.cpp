#include "stdafx.h"
#include "tree.h"
#include "Trie.h"
#include "SortingAlgorithms.h"
#include "SearchingAlgorithms.h"
#include "LinkedList.h"
#include "Singleton.h"

#include <string.h>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <omp.h>

// needed to indenfity memory leak
// https://msdn.microsoft.com/en-us/library/x98tx3cf.aspx
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  


// this implicitly goes to the ascii table and return
// the numerical value affected to the char.
inline int ctoi(char str)
{
	return str;
}

long long strtoint(char* str)
{
	long long total = 0;
	char* pStr = str;
	while (*pStr != '\0')
	{
		std::cout << *pStr << std::endl;
		total = total * 100 + ctoi(*pStr);
		++pStr;
	}
	return total;
}

void test_trees() {
	mtools::CTree<int>* myTree = new mtools::CTree<int>();
	myTree->insert(2);
	myTree->insert(3);
	myTree->insert(7);
	myTree->insert(1);
	int size = myTree->get_height();
	std::cout << size << std::endl;

	myTree->insert(8);

	size = myTree->get_height();
	std::cout << size << std::endl;
	myTree->display_pre_order();

	delete myTree;
	myTree = NULL;
}

void test_trees2() {
	mtools::CTree<int>* myTree = new mtools::CTree<int>();
	myTree->insert(50);
	myTree->insert(30);
	myTree->insert(20);
	myTree->insert(40);
	myTree->insert(70);
	myTree->insert(60);
	myTree->insert(80);

	std::cout << "Inorder traversal of the given tree \n";
	myTree->display_in_order();

	std::cout << "\nDelete 20\n";
	myTree->remove(20);
	std::cout << "Inorder traversal of the modified tree \n";
	myTree->display_in_order();

	std::cout << "\nDelete 30\n";
	myTree->remove(30);
	std::cout << "Inorder traversal of the modified tree \n";
	myTree->display_in_order();

	std::cout << "\nDelete 50\n";
	myTree->remove(50);
	std::cout << "Inorder traversal of the modified tree \n";
	myTree->display_in_order();

	delete myTree;
}

void display_array(const std::vector<int>& v) {
	for (const auto & i : v) {
		std::cout << i << " ";
	}
}

void test_buble_sort() {
	std::vector<int> v(std::begin(UNSORTED_ARRAY), std::end(UNSORTED_ARRAY));
	double start = omp_get_wtime();
	mtools::buble_sort(v);
	double end = omp_get_wtime();
	std::cout << "# Bubble Sort - Ellapsed time is : " << end - start << std::endl;
	
}
	
void test_quick_Sort() {
	std::vector<int> v(std::begin(UNSORTED_ARRAY), std::end(UNSORTED_ARRAY));
	double start = omp_get_wtime();
	mtools::quick_sort(v,0,UNSORTED_ARRAY_SIZE-1);
	double end = omp_get_wtime();
	std::cout << "# Quick Sort - Ellapsed time is : " << end - start << std::endl;
}

void linked_list_node_test() {
	mtools::LinkedListNode_t<int>* head = new mtools::LinkedListNode_t<int>(1);
	push_back_LinkedListNode_t(head, 2);
	push_back_LinkedListNode_t(head, 3);
	push_back_LinkedListNode_t(head, 4);
	head = push_front_LinkedListNode_t(head, 5);
	display_linked_list(head);
	delete_linked_list(head);
}

void linked_list_test()
{
	mtools::CLinkedList<int>* linkedList = new mtools::CLinkedList<int>(1);
	linkedList->push_back(20);
	linkedList->push_back(30);
	linkedList->push_front(50);
	linkedList->display();
	linkedList->remove_node(20);
	linkedList->display();
	linkedList->push_back(20);
	linkedList->display();
	linkedList->reverse();
	linkedList->display();
	delete linkedList;
}

void trie_test() {
	mtools::CTrie* trie = new mtools::CTrie(LOWERCASE_SIZE);
	trie->add_word("mathiss");
	bool exist = trie->find_word("mathiss");
	trie->add_word("pain");
	trie->add_word("algorithm");
	trie->add_word("attempt");
	delete trie;
}

void binary_search_test()
{
	std::vector<int> test_v = { 1,2,3,4,5,6,7,8,9,10 };
	auto size = test_v.size() - 1;
	bool result = mtools::binary_search(test_v, 0, size, 7);
	std::cout << "binary_search_test for 7 result=" << std::to_string(result) << std::endl;
	result = mtools::binary_search(test_v, 0, size, 11);
	std::cout << "binary_search_test for 11 result=" << result << std::endl;
	result = mtools::binary_search(test_v, 0, size, 2);
	std::cout << "binary_search_test for 2 result=" << result << std::endl;
}

void binary_search_iterative_test()
{
	std::vector<int> test_v = { 1,2,3,4,5,6,7,8,9,10 };
	auto size = test_v.size() - 1;
	bool result = mtools::binary_search_iterative(test_v, 0, size, 7);
	std::cout << "binary_search_iterative_test for 7 result=" << std::to_string(result) << std::endl;
	result = mtools::binary_search_iterative(test_v, 0, size, 11);
	std::cout << "binary_search_iterative_test for 11 result=" << result << std::endl;
	result = mtools::binary_search_iterative(test_v, 0, size, 2);
	std::cout << "binary_search_iterative_test for 2 result=" << result << std::endl;
}

int main()
{
	test_trees();
	test_trees2();
	//test_buble_sort();
	//test_quick_Sort();
	linked_list_test();
	linked_list_node_test();
	trie_test();
	binary_search_test();
	binary_search_iterative_test();

	mtools::A::instance()->test();
	mtools::A::destroy();

	_CrtDumpMemoryLeaks();
    return 0;
}