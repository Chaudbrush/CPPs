/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:33:39 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/01 13:34:49 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat a;
	Bureaucrat b("Nick", 148);
	Bureaucrat c("John", 3);

	Bureaucrat d("Failure low", 160);
	Bureaucrat e("Failure high", -160);

	std::cout << "\n--- Operator << ---\n" << std::endl;
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;

	std::cout << "\n--- Decreasing grade ---\n" << std::endl;
	
	b.gradeMinus();
	std::cout << b.getName() << " " << b.getGrade() << std::endl;
	b.gradeMinus();
	std::cout << b.getName() << " " << b.getGrade() << std::endl;
	b.gradeMinus();
	std::cout << b.getName() << " " << b.getGrade() << std::endl;
	b.gradeMinus();
	std::cout << b.getName() << " " << b.getGrade() << std::endl;

	std::cout << "\n--- Increasing grade ---\n" << std::endl;

	c.gradePlus();
	std::cout << c.getName() << " " << c.getGrade() << std::endl;
	c.gradePlus();
	std::cout << c.getName() << " " << c.getGrade() << std::endl;
	c.gradePlus();
	std::cout << c.getName() << " " << c.getGrade() << std::endl;
	c.gradePlus();
	std::cout << c.getName() << " " << c.getGrade() << std::endl;
}