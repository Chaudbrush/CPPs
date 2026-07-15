/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:16:09 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/06 15:50:35 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm *Intern::makeForm(std::string form, std::string target)
{
	int i = 0;
	std::string formsList[3] = {"shrubbery request", "robotomy request", "pardon request"};
	for (; i < 3; i++)
		if (formsList[i].compare(form) == 0)
			break ;
	AForm *tmp = NULL;
	try
	{
		switch(i)
		{
			case 0:
				tmp = new ShrubberyCreationForm(target);
				break ;
			case 1:
				tmp = new RobotomyRequestForm(target);
				break ;
			case 2:
				tmp = new PresidentialPardonForm(target);
				break ;
			default:
				throw(FormDoesntExists());
		}
		addToList(tmp);
		std::cout << "Intern creates " << tmp->getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (tmp);
}

void Intern::addToList(AForm *data)
{
	t_list *node = new t_list;
	node->data = data;
	node->next = to_del;
	to_del = node;
}

void Intern::clearList(void)
{
	t_list *ptr;
	ptr = to_del;

	while(ptr)
	{
		to_del = to_del->next;
		delete ptr->data;
		delete ptr;
		ptr = to_del;
	}
}

Intern::Intern() : to_del(NULL)
{

}

Intern::Intern(const Intern& other) : to_del(NULL)
{
	(void)other;
}

Intern::~Intern()
{
	if (to_del)
		clearList();
}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
	{
		if (to_del)
			clearList();
		to_del = NULL;
		(void)other;
	}
	return (*this);
}

const char *Intern::FormDoesntExists::what() const _GLIBCXX_NOTHROW
{
	return ("form does not exists.");
}