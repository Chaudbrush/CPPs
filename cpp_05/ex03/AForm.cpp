/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:23:27 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/01 15:14:38 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

std::string AForm::getName(void) const
{
	return (this->name);
}

int	AForm::getToSign(void) const
{
	return (this->to_sign);
}

int AForm::getToExec(void) const
{
	return (this->to_exec);
}

bool AForm::checkSignature(void) const
{
	return (this->is_signed);
}

void AForm::beSigned(const Bureaucrat &someone)
{
	if (someone.getGrade() > this->getToSign())
		throw(GradeTooLowException());
	else
		this->is_signed = true;
}

// Orthodox Canonical Form
AForm::AForm()
	: name("Default Form"), to_sign(1), to_exec(1), is_signed(false)
{
	
}

AForm::AForm(std::string name, int to_sign, int to_exec)
	: name(name), to_sign(to_sign), to_exec(to_exec), is_signed(false)
{
	try
	{
		if (to_sign < 1 || to_exec < 1)
			throw(GradeTooHighException());
		else if (to_sign > 150 || to_exec > 150)
			throw(GradeTooLowException());
		else
			return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

AForm::AForm(const AForm& other)
	: name(other.name), to_sign(other.to_sign), to_exec(other.to_exec), is_signed(other.is_signed)
{

}

AForm::~AForm()
{
	
}

AForm &AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->is_signed = other.is_signed;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const AForm& other)
{
	out << "Form name: " << other.getName() << "\n";
	out << "Form grade to sign: " << other.getToSign() << "\n";
	out << "Form grade to exec: " << other.getToExec() << "\n";
	out << "Form sign status: " << std::boolalpha <<(other.checkSignature());
	return (out);
}

// Exceptions
const char *AForm::GradeTooHighException::what() const _GLIBCXX_NOTHROW
{
	return ("form grade is too high.");
}

const char *AForm::GradeTooLowException::what() const _GLIBCXX_NOTHROW
{
	return ("form grade is too low.");
}

const char *AForm::NotSignedException::what() const _GLIBCXX_NOTHROW
{
	return ("form is not signed.");
}