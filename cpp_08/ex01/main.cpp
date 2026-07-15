/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:30:28 by vloureir          #+#    #+#             */
/*   Updated: 2026/06/20 13:05:50 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	Span array0;
	Span array1(10);
	Span array2(5);

	std::cout << "\n--- Populating Arrays ---" << std::endl;
	array0.addNumber(10);

	array1.addNumber(-1);
	array1.addNumber(-3);
	
	array2.addNumber(6);
	array2.addNumber(3);
	array2.addNumber(17);
	array2.addNumber(9);
	array2.addNumber(11);

	std::cout << "\n--- Printing Values ---" << std::endl;
	array1.print();
	array2.print();

	std::cout << "\n--- Checking Sizes ---" << std::endl;
	std::cout << "array1 size: " << array0.get_size() << std::endl;
	std::cout << "array1 size: " << array1.get_size() << std::endl;
	std::cout << "array2 size: " << array2.get_size() << std::endl;

	std::cout << "\n--- Checking Longest Span ---" << std::endl;
	std::cout << "array0 longest: " << array0.longestSpan() << std::endl;
	std::cout << "array1 longest: " << array1.longestSpan() << std::endl;
	std::cout << "array2 longest: " << array2.longestSpan() << std::endl;

	std::cout << "\n--- Checking Shortest Span ---" << std::endl;
	std::cout << "array0 shortest: " << array0.shortestSpan() << std::endl;
	std::cout << "array1 shortest: " << array1.shortestSpan() << std::endl;
	std::cout << "array2 shortest: " << array2.shortestSpan() << std::endl;

	std::cout << "\n--- Adding Range of Numbers ---" << std::endl;
	int tmp[] = {3, 4, 5, 6, 7, -8, 9, -12};
	int size = sizeof(tmp) / sizeof(tmp[0]);
	array0.addRange(tmp, tmp + size);
	array1.addRange(tmp, tmp + size);
	array2.addRange(tmp, tmp + size);

	std::cout << "\n--- Printing Values Again---" << std::endl;
	array1.print();
	array2.print();

	std::cout << "\n--- Checking Sizes ---" << std::endl;
	std::cout << "array1 size: " << array0.get_size() << std::endl;
	std::cout << "array1 size: " << array1.get_size() << std::endl;
	std::cout << "array2 size: " << array2.get_size() << std::endl;
	
	{
		std::cout << "\n--- Checking Copies ---" << std::endl;
		Span array3(array1);
		Span array4;

		array4 = array2;
		array1.printAddr();
		array3.printAddr();
		std::cout << std::endl;
		array2.printAddr();
		array4.printAddr();
	}

	std::cout << "\n--- Adding Range Positional ---" << std::endl;
	int tmp0[] = {20, 21, 22, 23, 24, 25};
	int size0 = sizeof(tmp0) / sizeof(tmp0[0]);

	int tmp1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int size1 = sizeof(tmp1) / sizeof(tmp1[0]);

	Span range1(20);
	Span range2(7);
	Span range3(3);
	
	range1.addRange(tmp0, tmp0 + size0);
	// Correct
	std::vector<int>::const_iterator it1 = range1.getBegin() + 2;
	range1.addRange(it1, tmp1, tmp1 + size1);
	range1.addNumber(42);

	// No capacity
	std::vector<int>::const_iterator it2 = range2.getBegin();
	range2.addRange(it2, tmp1, tmp1 + size1);

	// Invalid
	range3.addRange(it1, tmp1, tmp1 + size1);

	std::cout << "\n--- Printing Values Again---" << std::endl;
	range1.print();
	range2.print();
	range3.print();
}