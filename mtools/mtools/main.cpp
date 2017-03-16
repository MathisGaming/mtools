#include "stdafx.h"
#include "tree.h"
#include "SortingAlgorithms.h"
#include "LinkedList.h"

#include <string.h>
#include <iostream>
#include <stack>
#include <queue>

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

void test_buble_sort() {
	std::vector<int> v;
	//v.push_back(7); v.push_back(5); v.push_back(9); v.push_back(8); v.push_back(2); v.push_back(3); v.push_back(1);
	v.push_back(3); v.push_back(2); v.push_back(1);
	for (auto i : v) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	mtools::buble_sort(v);
	for (auto i : v) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

int main()
{
	test_trees();
	test_buble_sort();

    return 0;
}