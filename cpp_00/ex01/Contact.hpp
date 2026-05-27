/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:45:36 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/10 13:41:22 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CONTACT_HPP_
# define __CONTACT_HPP__

# include <cstring>
# include <iomanip>
# include <iostream>
# include <sstream>

# include "PhoneBook.hpp"

class Contact
{
public:
	void		set_info(std::string value, std::string place);
	std::string	get_info(std::string place);

private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

#endif