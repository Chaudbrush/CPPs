/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:21:58 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/08 18:47:55 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string captalize(std::string str);

int	main(int argc, char **argv)
{
	std::string result;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; ++i)
			std::cout << captalize(argv[i]);
	}
	std::cout << std::endl;
	return (0);
}

std::string captalize(std::string str)
{
	for (int i = 0; str[i] != '\0'; ++i)
		str[i] = toupper(str[i]);
	return (str);
}