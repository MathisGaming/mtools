#include "stdafx.h"
#include "tree.h"
#include <string.h>
#include <iostream>

// this implicitly goes to the ascii table and return
// the numerical value affected to the char.
int ctoi(char str)
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

int main()
{
	mtools::CTree<int>* myTree = new mtools::CTree<int>();
	myTree->insert(2);
	myTree->insert(3);
	myTree->insert(7);
	myTree->insert(1);

	std::cout << strtoint("ABCDEFGH") << std::endl;

    return 0;
}

