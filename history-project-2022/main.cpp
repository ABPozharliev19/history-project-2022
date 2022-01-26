#include <iostream>
#include <vector>
#include "include/backend/LinkedList.h"

int main()
{
	std::vector<int> ok{ 1, 2, 3, 4, 5, 6 };

	LinkedList<int> kekw;

	for (int i = 0; i < 10; i++)
	{
		kekw.push_back(i);
	}
	
	kekw.printList();
}