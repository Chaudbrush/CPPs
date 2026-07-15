/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:22:27 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/01 14:19:23 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// https://cplusplus.com/doc/oldtutorial/exceptions/

Bureaucrat::Bureaucrat() : name("Default Bureaucrat"), grade(150)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	try
	{
		if (this->grade > 150)
		{
			this->grade = 150;
			throw(GradeTooLowException());
		}
		if (this->grade < 1)
		{
			this->grade = 1;
			throw(GradeTooHighException());
		}
		else
			return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	this->grade = other.grade;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
	this->grade = other.grade;
	return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return (name);
}

int Bureaucrat::getGrade(void) const
{
	return (grade);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat& other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (out);
}

void Bureaucrat::gradePlus(void)
{
	try
	{
		if (this->grade > 1)
			this->grade--;
		else
			throw(GradeTooHighException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::gradeMinus(void)
{
	try
	{
		if (this->grade < 150)
			this->grade++;
		else
			throw(GradeTooLowException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign ";
		std::cerr << form.getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const _GLIBCXX_NOTHROW
{
	return ("-error: grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const _GLIBCXX_NOTHROW
{
	return ("-error: grade is too low.");
}