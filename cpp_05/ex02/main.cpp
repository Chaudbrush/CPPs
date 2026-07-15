/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:33:39 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/01 19:28:26 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat a;
	Bureaucrat b("Nick", 70);
	Bureaucrat c("John", 3);

	ShrubberyCreationForm form1;
	ShrubberyCreationForm form2("Bonsai");
	RobotomyRequestForm robot1;
	PresidentialPardonForm exam2("Caught Cheating");
	
	std::cout << "\n--- Forms before signing ---\n" << std::endl;	
	std::cout << form1 << std::endl << std::endl;
	std::cout << form2 << std::endl << std::endl;
	std::cout << robot1 << std::endl << std::endl;
	std::cout << exam2 << std::endl << std::endl;
	
	b.signForm(form1);
	b.signForm(form2);
	b.signForm(robot1);
	c.signForm(exam2);
	
	std::cout << "\n--- Forms after signing ---\n" << std::endl;	
	std::cout << form1 << std::endl << std::endl;
	std::cout << form2 << std::endl << std::endl;
	std::cout << robot1 << std::endl << std::endl;
	std::cout << exam2 << std::endl << std::endl;

	std::cout << "\n--- ShrubberyCreationForm tests ---\n" << std::endl;	
	a.executeForm(form1);
	b.executeForm(form1);
	c.executeForm(form2);

	std::cout << "\n--- RobotomyRequestForm tests ---\n" << std::endl;
	a.executeForm(robot1);
	b.executeForm(robot1);
	c.executeForm(robot1);

	std::cout << "\n--- PresidentialPardonForm tests ---\n" << std::endl;
	a.executeForm(exam2);
	b.executeForm(exam2);
	c.executeForm(exam2);
}