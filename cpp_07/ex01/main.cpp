/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 09:42:44 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/15 17:12:39 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "function.hpp"
#include "Complex.hpp"

int	main(void)
{
	int i1[10] = {0, 1, 2, 3, 33, 42, 52, 62, 72, 100};
	float f1[10] = {0.33, 1.67, 2.99, 3.00, 33.5, 42.4242, 52.123, 62.456, 72.789, 100.299};
	const char s1[10] = "cowabanga";
	const std::string s2[3] = {"it's sunny outside", "hurricane hurricane", "now it's freezing"};
	Complex cx[10] = {};
	
	for (int i = 0; i < 10; i++)
	{
		cx[i].setX(i);
		cx[i].setY(i * 3);
	}

	std::cout << "--- int array ---" << std::endl;
	::iter(i1, 10, func1);
	std::cout << "\n--- float array ---" << std::endl;
	::iter(f1, 10, func1);
	std::cout << "\n--- char array ---" << std::endl;
	::iter(s1, 9, func1);
	std::cout << "\n--- string array ---" << std::endl;
	::iter(s2, 3, func1);
	std::cout << "\n--- complex array ---" << std::endl;
	::iter(cx, 10, func1);
}