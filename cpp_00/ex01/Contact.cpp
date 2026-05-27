/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:42:59 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/08 19:10:55 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	exec_add(PhoneBook *data)
{
	std::string buffer;

	std::cout << "First name: ";
	std::getline(std::cin >> std::ws, buffer);
	data->get_contact()[data->index % 8].set_info(buffer, "first");
	if (std::cin.eof()  || !data->get_contact()[data->index % 8].get_info("first")[0])
		return (error_printer("\n-error: EOF detected."));
	std::cout << "Last name: ";
	std::getline(std::cin >> std::ws, buffer);
	data->get_contact()[data->index % 8].set_info(buffer, "last");
	if (std::cin.eof() || !data->get_contact()[data->index % 8].get_info("last")[0])
		return (error_printer("\n-error: EOF detected."));
	std::cout << "Nickname: ";
	std::getline(std::cin >> std::ws, buffer);
	data->get_contact()[data->index % 8].set_info(buffer, "nick");
	if (std::cin.eof() || !data->get_contact()[data->index % 8].get_info("nick")[0])
		return (error_printer("\n-error: EOF detected."));
	if (!get_number(data))
		return (error_printer("\n-error: EOF detected."));
	std::cout << "Darkest Secret: ";
	std::getline(std::cin >> std::ws, buffer);
	data->get_contact()[data->index % 8].set_info(buffer, "secret");
	if (std::cin.eof() || !data->get_contact()[data->index % 8].get_info("secret")[0])
		return (error_printer("\n-error: EOF detected."));
	data->index++;
}

void	exec_search(PhoneBook *data)
{
	unsigned int	i;
	unsigned int	index;
	std::string		str;

	i = 0;
	if (data->index == 0)
	{
		error_printer("-error: No contacts were added.\n");
		return ;
	}
	while (i < data->index && i < 8)
	{
		std::cout << std::setw(10) << i << "|";
		str_crop(data->get_contact()[i].get_info("first"));
		str_crop(data->get_contact()[i].get_info("last"));
		str_crop(data->get_contact()[i].get_info("nick"));
		std::cout << std::endl;
		i++;
	}
	while (1)
	{
		std::cout << "Index to be displayed: ";
		std::cin >> str;
		if (std::cin.eof())
			return (error_printer("\n-error: EOF detected."));
		std::istringstream tmp(str);
		tmp >> index;
		if (!check_number(str, 0) || index >= data->index || (int)index < 0)
		{
			error_printer("-error: Invalid Index.\n");
			continue ;
		}
		break ;
	}
	std::cout << "\nDetailed information:" << std::endl;
	std::cout << "First name: " << data->get_contact()[index].get_info("first") << std::endl;
	std::cout << "Last name: " << data->get_contact()[index].get_info("last") << std::endl;
	std::cout << "Nickname: " << data->get_contact()[index].get_info("nick") << std::endl;
	std::cout << "Phone number: " << data->get_contact()[index].get_info("phone") << std::endl;
	std::cout << "Darkest Secret: " << data->get_contact()[index].get_info("secret") << std::endl << std::endl;
}

void	Contact::set_info(std::string value, std::string place)
{
	int i = 0;
	std::string ref[] = {"first", "last", "nick", "phone", "secret"};
	
	for ( ; i < 5; i++)
	{
		if (ref[i].compare(place) == 0)
			break ;
	}
	switch(i)
	{
		case 0:
			this->first_name = value;
			break ;
		case 1:
			this->last_name = value;
			break ;
		case 2:
			this->nickname = value;
			break ;
		case 3:
			this->phone_number = value;
			break ;
		case 4:
			this->darkest_secret = value;
			break ;
	}
}

std::string Contact::get_info(std::string place)
{
	int i = 0;
	std::string ref[] = {"first", "last", "nick", "phone", "secret"};
	
	for ( ; i < 5; i++)
	{
		if (ref[i].compare(place) == 0)
			break ;
	}
	switch(i)
	{
		case 0:
			return (this->first_name);
		case 1:
			return (this->last_name);
		case 2:
			return (this->nickname);
		case 3:
			return (this->phone_number);
		case 4:
			return (this->darkest_secret);
	}
	return (NULL);
}