/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:52:28 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/08 19:12:01 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	get_number(PhoneBook *data)
{
	std::string buffer;
	
	while (1)
	{
		std::cout << "Phone number: ";
		std::getline(std::cin >> std::ws, buffer);
		data->get_contact()[data->index % 8].set_info(buffer, "phone");
		if (std::cin.eof() || !data->get_contact()[data->index % 8].get_info("phone")[0])
			return (0);
		if (!check_number(data->get_contact()[data->index % 8].get_info("phone"), 1))
			continue ;
		if (data->get_contact()[data->index % 8].get_info("phone").length() > 9)
		{
			error_printer("-error: Phone number too big. Maximum 9 digits.\n");
			continue ;
		}
		break ;
	}
	return (1);
}

int	check_number(std::string number, int flag)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (!isdigit(number[i]))
		{
			if (flag)
				std::cout << "-error: Not a valid number. Please try again." << std::endl;
			return (0);
		}
		i++;
	}
	return (1);
}

void	str_crop(std::string data)
{
	if (data.length() > 10)
	{
		data.resize(10);
		data[9] = '.';
		std::cout << data << "|";
	}
	else
		std::cout << std::setw(10) << data << "|";
}

void error_printer(std::string string)
{
	std::cerr << string;
}