#include <iostream>
#include <vector>
#include "include/backend/LinkedList.h"

int main()
{
	std::vector<int> ok{ 1};

	LinkedList<int> kekw(ok);

	kekw[0] = 2;

	std::cout << kekw.empty();

	std::cout << kekw.size();

	
}