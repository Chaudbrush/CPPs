/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:44:23 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/08 18:58:43 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	phone_book(PhoneBook *data)
{
	std::string	tmp;

	while (!std::cin.eof())
	{
		std::cout << "Welcome to Phonebook! Accepted Inputs: (ADD, SEARCH, EXIT)" << std::endl;
		std::cout << "Input: ";
		std::getline(std::cin >> std::ws, tmp);
		if (!tmp[0] || std::cin.eof())
		{
			error_printer("\n-error: EOF detected.");
			break ;
		}
		if (!tmp.compare("EXIT"))
		{
			std::cout << "Exiting..." << std::endl;
			return ;
		}
		else if (!tmp.compare("ADD"))
			exec_add(data);
		else if (!tmp.compare("SEARCH"))
			exec_search(data);
		else
		{
			error_printer("-error: Unaccepted Input. Try again.\n");
			continue ;
		}
	}
	std::cout << std::endl;
}

PhoneBook::PhoneBook(void)
{
	index = 0;
}

Contact *PhoneBook::get_contact(void)
{
	return (members);
}

// ADD : saves new contact
/*
	Prompt for inputs for contact fields, once they are all done, add it to contact
	Contact fields are: first name, last name, nickname, phone number, darkest secret
	CAN'T BE EMPTY
*/

// SEARCH: display a contact
/*
	Display contacts as: index, first name, last name, nickname
	Columns must be 10 character wide, separated by a '|'
	Must be right-aligned
	If longer than column, truncate to 9 characters, finish with a '.'

	Prompt again for the index of the entry to display
	If out of range, DEFINE ERROR MESSAGE
	Else, display the contact information, one field per line
*/

// EXIT
// Finish the program and all contact data is lost

// OTHER INPUTS ARE IGNORED

// PROTECT FROM CTRL + D