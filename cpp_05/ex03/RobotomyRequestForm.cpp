/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:29:45 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/01 19:33:36 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (checkSignature() == false)
		throw(NotSignedException());
	if (executor.getGrade() > this->getToExec())
		throw(GradeTooLowException());
	if (std::rand() % 2)
		std::cout << "Vrrrrrrm...Vrrrrrrm... " << target << " was succesfully robotomized." << std::endl;
	else
		std::cout << "Robotomization failed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Default RobotomyRequestForm", 72, 45), target("Default_target")
{
	
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other.getName(), 72, 45), target(other.target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	// Dont understand what am I supposed to do here?
	if (this != &other)
	{
		(void)other;
	}
	return (*this);
}
