/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 21:36:01 by vloureir          #+#    #+#             */
/*   Updated: 2026/07/15 09:36:03 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <fstream>
# include <map>
# include <sstream>

# define FEV 2
# define APR 4
# define JUN 6
# define SET 9
# define NOV 11
# define BAD_LINE "\e[38;5;160mError\e[0m: empty input: ''"
# define BAD_EOL "\e[38;5;160mError\e[0m: bad end of line input: '"
# define BAD_HEADER "\e[38;5;160mError\e[0m: invalid header: '"
# define BAD_DATE "\e[38;5;160mError\e[0m: bad date input: '"
# define BAD_SEP "\e[38;5;160mError\e[0m: bad separator input: '"
# define BAD_VALUE "\e[38;5;160mError\e[0m: bad value input: '"

class BitcoinExchange
{
public:
	void				fileClose(void); // Not necessary
	void				parseInput(void);
	int					getDatabase(int &err);
	int					openFile(const char* infile);
	int					hashDate(const std::string& str);
	const std::string	dateToStr(const int& date) const;
	int					validateDate(const std::string& str);
	float				validateNumber(const std:: string& number);
	void				printResult(const int& date, const float& value);
	
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& rhs);
	~BitcoinExchange();

	BitcoinExchange& operator=(const BitcoinExchange& rhs);

	void print_database(void);

private:
	std::fstream file;
	std::map<int, float> data;
};