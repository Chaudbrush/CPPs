/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:41:58 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/10 13:47:15 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef	__PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

# include <cstring>
# include <iomanip>
# include <iostream>
# include <sstream>

# include "Contact.hpp"

class PhoneBook
{
public:
	unsigned int	index;
	Contact *get_contact(void);
	PhoneBook();

private:
	Contact			members[8];
};

// Phonebook
void	phone_book(PhoneBook *data);

// Contact
void	exec_add(PhoneBook *data);
void	exec_search(PhoneBook *data);

// Utils
void	str_crop(std::string data);
int		get_number(PhoneBook *data);
void 	error_printer(std::string string);
int		check_number(std::string number, int flag);

#endif