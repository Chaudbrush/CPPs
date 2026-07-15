/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:33:39 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/30 11:48:42 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat a;
	Bureaucrat b("Nick", 148);
	Bureaucrat c("John", 3);

	std::cout << a.getName() << " " << a.getGrade() << std::endl;
	std::cout << b.getName() << " " << b.getGrade() << std::endl;
	std::cout << c.getName() << " " << c.getGrade() << std::endl;
	
	Form form1;
	Form form2("Piscine", 35, 12);
	
	std::cout << "\n--- Signing test ---\n" << std::endl;
	
	b.signForm(form2);
	std::cout << form2 << "\n" << std::endl;;
	c.signForm(form2);
	std::cout << form2 << std::endl;
	
	Form form3(form2);

	std::cout << "\n" << form1 << std::endl;
	std::cout << "\n" << form3 << std::endl;

	std::cout << "\n--- Checking invalid init ---" << std::endl; 
	Form form_err1("Error high", -1, 1);
	Form form_err2("Error high", 1, -1);
	Form form_err3("Error low", 160, 1);
	Form form_err4("Error low", 1, 160);
}