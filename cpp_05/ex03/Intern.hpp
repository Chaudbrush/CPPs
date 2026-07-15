/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:16:12 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/01 21:26:30 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	AForm *makeForm(std::string form, std::string target);

	Intern();
	Intern(const Intern& other);
	~Intern();

	Intern& operator=(const Intern& other);

	class FormDoesntExists : public std::exception
	{
		virtual const char *what() const _GLIBCXX_NOTHROW;
	};

private:
	typedef struct s_list
	{
		AForm *data;
		struct s_list *next;
	}	t_list;

	t_list *to_del;

	void addToList(AForm *data);
	void clearList(void);
};

#endif