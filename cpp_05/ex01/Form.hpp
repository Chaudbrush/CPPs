/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:23:31 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/01 14:19:37 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{ 
public:
	std::string getName(void) const;
	int	getToSign(void) const;
	int getToExec(void) const;
	bool checkSignature(void) const;

	void beSigned(const Bureaucrat& someone);

	Form();
	Form(std::string name, int to_sign, int to_exec);
	Form(const Form& other);
	~Form();

	Form &operator=(const Form& other);

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const _GLIBCXX_NOTHROW;
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const _GLIBCXX_NOTHROW;
	};

private:
	const std::string name;
	const int to_sign;
	const int to_exec;
	bool is_signed;
};

std::ostream &operator<<(std::ostream &out, const Form& other);


#endif