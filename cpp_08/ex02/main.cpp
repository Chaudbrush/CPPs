# include <iostream>
# include <list>
#include "MutantStack.hpp"

int main()
{
	std::cout << "|--- MutantStack ---|" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "front: " <<  mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " <<  mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\n|--- List ---|" << std::endl;

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "front: " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "size: " <<  lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator itl = lst.begin();
	std::list<int>::iterator itel = lst.end();

	++itl;
	--itl;

	while (itl != itel)
	{
		std::cout << *itl << std::endl;
		++itl;
	}

		{
		std::cout << "\n|--- Copy, Operator= and Reverse Iterator ---|" << std::endl;

		MutantStack<int> m2(mstack);
		MutantStack<int> m3;
		m2.push(3);
		m2.push(3);
		m2.push(3);

		m3 = m2;
		m3.pop();
		m3.pop();
		m3.pop();
		m3.pop();

		std::cout << "\n|--- m2 ---|" << std::endl;
		MutantStack<int>::reverse_iterator it2 = m2.rbegin();
		MutantStack<int>::reverse_iterator ite2 = m2.rend();
		while (it2 != ite2)
		{
			std::cout << *it2 << std::endl;
			++it2;
		}
		
		std::cout << "\n|--- m3 ---|" << std::endl;
		MutantStack<int>::reverse_iterator it3 = m3.rbegin();
		MutantStack<int>::reverse_iterator ite3 = m3.rend();
		while (it3 != ite3)
		{
			std::cout << *it3 << std::endl;
			++it3;
		}
	}
	return 0;
}