#include <algorithm>
#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include "easyfind.hpp"

int main(void)
{
	// EASYFIND TESTS
	int tmp[] = {2, 4, 1, 5, -1, 10, -11};

	std::cout << "--- TEST VECTOR ---" << std::endl;
	{
		std::vector<int> vec(tmp, tmp + (sizeof(tmp) / sizeof(tmp[0])));
		
		if (easyfind(vec, -1) != -1)
			std::cout << "found\n" << std::endl;
		else
			std::cout << "NOT FOUND\n" << std::endl;
	}

	std::cout << "--- TEST LIST ---" << std::endl;
	{
		std::list<int> lst(tmp, tmp + (sizeof(tmp) / sizeof(tmp[0])));

		if (easyfind(lst, -1) != -1)
			std::cout << "found\n" << std::endl;
		else
			std::cout << "NOT FOUND\n" << std::endl;
	}

	std::cout << "--- TEST DEQUE ---" << std::endl;
	{
		std::list<int> dqueue(tmp, tmp + (sizeof(tmp) / sizeof(tmp[0])));

		if (easyfind(dqueue, -12) != -1)
			std::cout << "found\n" << std::endl;
		else
			std::cout << "NOT FOUND\n" << std::endl;
	}
}