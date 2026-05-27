/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:30:02 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/13 11:17:14 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string s1 = "HI THIS IS BRAIN";
	std::string s2 = "NOT BRAIN";
	std::string *stringPTR = &s1;
	std::string &stringREF = s1;

	std::cout << "s1: " << &s1 << std::endl;
	std::cout << "PTR: " << stringPTR << std::endl;
	std::cout << "REF: " << &stringREF << std::endl;
	std::cout << "s2: " << &s2 << std::endl << std::endl;
	
	std::cout << s1 << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

	stringPTR = &s2;
	std::cout << std::endl << "Changing only PTR:" << std::endl;
	std::cout << s1 << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl << std::endl;
	
	std::cout << "s1: " << &s1 << std::endl;
	std::cout << "PTR: " << stringPTR << std::endl;
	std::cout << "REF: " << &stringREF << std::endl;
	std::cout << "s2: " << &s2 << std::endl;

	stringPTR = &s1;
	stringREF = s2;
	std::cout << std::endl << "Changing only REF:" << std::endl;
	std::cout << s1 << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl << std::endl;
	
	std::cout << "s1: " << &s1 << std::endl;
	std::cout << "PTR: " << stringPTR << std::endl;
	std::cout << "REF: " << &stringREF << std::endl;
	std::cout << "s2: " << &s2 << std::endl;
}
