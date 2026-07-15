/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:22:23 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/30 14:43:40 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
public:
	void gradePlus(void);
	void gradeMinus(void);
	std::string getName(void) const;
	int	getGrade(void) const;

	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat& other);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const _GLIBCXX_NOTHROW;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		// WHY THIS DOESNT WORK ??
		// _GLIBCXX_NOTHROW or _GLIBCXX_USE_NOEXCEPT works!
		virtual const char* what() const _GLIBCXX_NOTHROW;
	};

private:
	const std::string name;
	int grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat& other);

#endif