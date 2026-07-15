/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 12:59:02 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/09 13:59:55 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main(void)
{
	std::srand(std::time(NULL));

	std::cout << "\n--- random number ---\n" << std::endl;
	Base *b1 = generate();
	Base *b2 = generate();
	Base *b3 = generate();
	Base *b4 = generate();
	Base *b5 = generate();
	Base *b6 = generate();

	std::cout << "\n--- pointers ---\n" << std::endl;
	identify(b1);
	identify(b2);
	identify(b3);
	identify(b4);
	identify(b5);
	identify(b6);

	std::cout << "\n--- reference ---\n" << std::endl;
	identify(*b1);
	identify(*b2);
	identify(*b3);
	identify(*b4);
	identify(*b5);
	identify(*b6);

	delete b1;
	delete b2;
	delete b3;
	delete b4;
	delete b5;
	delete b6;
}

Base *generate(void)
{
	int i = std::rand() % 3;
	std::cout << "i: " << i << std::endl;
	if (i == 0)
		return (new A());
	else if (i == 1)
		return (new B());
	return (new C());
}

void identify(Base *p)
{
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "it's type A." << std::endl;
	else if (b)
		std::cout << "it's type B." << std::endl;
	else if (c)
		std::cout << "it's type C." << std::endl;
	else
		std::cout << "Invalid type." << std::endl;
}

void identify(Base &p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "it's type A." << std::endl;
		(void)a;
		return ;
	}
	catch(const std::exception& e) {
//		std::cerr << e.what() << "\n";
	}
	try {
		B &b = dynamic_cast<B&>(p);
		std::cout << "it's type B." << std::endl;
		(void)b;
		return ;
	}
	catch(const std::exception& e) {
//		std::cerr << e.what() << "\n";
	}
	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "it's type C." << std::endl;
		(void)c;
		return ;
	}
	catch(const std::exception& e) {
//		std::cerr << e.what() << "\n";
	}
}
