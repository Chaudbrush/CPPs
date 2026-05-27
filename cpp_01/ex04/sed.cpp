/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:06:24 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/09 14:13:51 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

std::string	not_sed(std::string s1, std::string s2, std::string s3);

int	main(int argc, char **argv)
{
	std::string		buffer;
	std::string		replace_file;
	std::fstream	in_file;
	std::fstream	out_file;

	if (argc != 4)
		return (1);
	replace_file = argv[1];
	replace_file = replace_file + ".replace";
	in_file.open(argv[1], std::fstream::in);
	out_file.open(replace_file.c_str(), std::fstream::out);
	if (!in_file.is_open())
	{
		std::cerr << "-error: Unable to open file" << std::endl;
		return (2);
	}
	while (getline(in_file, buffer))
		out_file << not_sed(buffer, argv[2], argv[3]) << std::endl;
	in_file.close();
	out_file.close();
}

std::string	not_sed(std::string s1, std::string s2, std::string s3)
{
	int	found;

	if (s1.empty() || s2.empty())
		return (s1);
	for (int i = 0; i < (int)(s1.length() - s2.length() + 1); i++)
	{
		found = s1.find(s2);
		if (found != -1)
		{
			s1.erase(found, s2.length());
			s1.insert(found, s3);
		}
	}
	return (s1);
}
