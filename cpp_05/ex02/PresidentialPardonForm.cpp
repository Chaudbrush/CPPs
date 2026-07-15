/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:29:45 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/01 19:33:22 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (checkSignature() == false)
		throw(NotSignedException());
	if (executor.getGrade() > this->getToExec())
		throw(GradeTooLowException());
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Default PresidentialPardonForm", 25, 5), target("Default_target")
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other.getName(), 25, 5), target(other.target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	// Dont understand what am I supposed to do here?
	if (this != &other)
	{
		(void)other;
	}
	return (*this);
}
