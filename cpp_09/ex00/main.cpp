/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 21:35:58 by vloureir          #+#    #+#             */
/*   Updated: 2026/07/14 12:49:14 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	int err = 0;
	BitcoinExchange btc;
	
	if (ac < 2 || btc.getDatabase(err) || btc.openFile(av[1]))
	{
		if (err)
			std::cerr << "Error: invalid database.\n";
		else
			std::cerr << "Error: could not open file.\n";
		return (1);
	}
	btc.parseInput();
	btc.fileClose();
}