/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 08:23:00 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/13 14:13:26 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
#include "Complex.hpp"
#include "whatever.hpp"


int	main(void)
{
	std::cout << "\n--- int ---\n" << std::endl;
	int x = 10;
	int y = -42;

	std::cout << x << ", " << y << std::endl;
	swap(x, y);
	std::cout << x << ", " << y << std::endl;

	std::cout << "min: " << ::min(x, y) << std::endl;
	std::cout << "max: " << ::max(x, y) << std::endl;

	std::cout << "\n--- float ---\n" << std::endl;
	float f = 10.42f;
	float d = -42.100f;

	std::cout << f << ", " << d << std::endl;
	swap(f, d);
	std::cout << f << ", " << d << std::endl;

	std::cout << "min: " << ::min(f, d) << std::endl;
	std::cout << "max: " << ::max(f, d) << std::endl;

	std::cout << "\n--- std::string ---\n" << std::endl;
	std::string  s1 = "hello";
	std::string  s2 = "bye bye";

	std::cout << s1 << ", " << s2 << std::endl;
	swap(s1, s2);
	std::cout << s1 << ", " << s2 << std::endl;

	std::cout << "min: " << ::min(s1, s2) << std::endl;
	std::cout << "max: " << ::max(s1, s2) << std::endl;

	std::cout << "\n--- char * ---\n" << std::endl;
	const char *c1 = "a char*";
	const char *c2 = "just another char*";

	std::cout << c1 << ", " << c2 << std::endl;
	swap(c1, c2);
	std::cout << c1 << ", " << c2 << std::endl;

	std::cout << "min: " << ::min(c1, c2) << std::endl;
	std::cout << "max: " << ::max(c1, c2) << std::endl;

	std::cout << "\n--- complex type ---\n" << std::endl;
	Complex p1(10, 25);
	Complex p2(42, -42);

	std::cout << "p1: " << p1 << "\n" << "p2: " << p2 << std::endl;
	swap(p1, p2);
	std::cout << "p1: " << p1 << "\n" << "p2: " << p2 << std::endl;

	std::cout << "min: " << ::min(p1, p2) << std::endl;
	std::cout << "max: " << ::max(p1, p2) << std::endl;
}