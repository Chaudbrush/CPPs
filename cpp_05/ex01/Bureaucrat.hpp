/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:22:23 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/01 14:19:27 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{
public:
	void gradePlus(void);
	void gradeMinus(void);
	std::string getName(void) const;
	int	getGrade(void) const;
	void signForm(Form& form);

	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat& other);

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const _GLIBCXX_NOTHROW;
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const _GLIBCXX_NOTHROW;
	};

private:
	const std::string name;
	int grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat& other);

#endif