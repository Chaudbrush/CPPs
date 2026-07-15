/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:23:31 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/01 15:10:25 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{ 
public:
	std::string getName(void) const;
	int	getToSign(void) const;
	int getToExec(void) const;
	bool checkSignature(void) const;

	void beSigned(const Bureaucrat& someone);
	virtual void execute(const Bureaucrat& executor) const = 0;

	AForm();
	AForm(std::string name, int to_sign, int to_exec);
	AForm(const AForm& other);
	virtual ~AForm();

	AForm &operator=(const AForm& other);

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const _GLIBCXX_NOTHROW;
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const _GLIBCXX_NOTHROW;
	};

	class NotSignedException : public std::exception
	{
		virtual const char *what() const _GLIBCXX_NOTHROW;
	};

private:
	const std::string name;
	const int to_sign;
	const int to_exec;
	bool is_signed;
};

std::ostream &operator<<(std::ostream &out, const AForm& other);


#endif