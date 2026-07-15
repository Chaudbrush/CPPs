/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 21:36:03 by vloureir          #+#    #+#             */
/*   Updated: 2026/07/15 10:31:53 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::print_database(void)
{
	std::map<int, float>::iterator it = data.begin();
	while (it != data.end())
	{
		std::cout << "date: " << it->first << " value: " << it->second << std::endl;
		it++;
	}
}

int BitcoinExchange::hashDate(const std::string& str)
{
	std::stringstream ss(str);
	short	year = -1, month = -1, day = -1;
	char	sep1 = ' ', sep2 = ' ', err = 0;

	ss >> year >> sep1 >> month >> sep2 >> day >> err;

	if (year < 1 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31)
		return (-1);
	if (sep1 != '-' || sep2 != '-' || err)
		return (-1);
	return ((year << 16) + (month << 8) + day);
}

const std::string BitcoinExchange::dateToStr(const int& date) const
{
	std::stringstream ss;
	std::string res;
	ss << (date >> 16) << "-"
		<< std::setfill('0') << std::setw(2) << ((date >> 8) & 0b11111111)<< "-" 
		<< std::setfill('0') << std::setw(2) << (date & 0b11111111);
	ss >> res;
	return (res);
}

int		BitcoinExchange::validateDate(const std::string& str)
{
	int leap_flag = 0;
	int date = hashDate(str);
	if (date == -1)
		return (-1);

	int year = date >> 16;
	int month = ((date >> 8) & 0b11111111);
	int day = date & 0b11111111;

	if (data.begin()->first > date)
		return (-1);

	if (year % 4 == 0 && year % 100 != 0)
		leap_flag = 1; // fev 29
	else if (year % 100 == 0 && year % 400 == 0)
		leap_flag = 1; // fev 29

	if (month == APR || month == JUN || month == SET || month == NOV)
	{
		if (day > 30)
			return (-1);
	}
	else if (month == FEV)
	{
		if ((leap_flag && day > 29) || (!leap_flag && day > 28))
			return (-1);
	}
	return (date);
}

float		BitcoinExchange::validateNumber(const std:: string& number)
{
	char *end = NULL;
	double value;

	if (number.empty() || number[0] == ' ')
		return (-1);
	value = strtod(number.c_str(), &end);
	if (*end || value < 0 || value > 1000 || value == HUGE_VAL)
		return (-1);
	return (value);
}

void	BitcoinExchange::parseInput(void)
{
	std::string date_str, num, buffer;
	getline(file, buffer); // skip TITLE line
	if (buffer != "date | value")
	{
		std::cout << BAD_HEADER << buffer << "'" << std::endl;
		return ;
	}

	while (getline(file, buffer))
	{
		char c1 = 0, c2 = 0, c3 = 0, err = 0;
		std::stringstream ss(buffer);
		
		ss >> std::noskipws;
		ss >> date_str >> c1 >> c2 >> c3 >> num >> err;
		
		int date = validateDate(date_str);
		float value = validateNumber(num);

		if (date_str == "")
			std::cout << BAD_LINE << std::endl;
		else if (err || ((c1 == 0 || c2 == 0 || c3 == 0) && date != -1))
			std::cout << BAD_EOL << err << "'" << std::endl;
		else if (date == -1)
			std::cerr << BAD_DATE << date_str << "'" << std::endl;
		else if (c1 != ' ' || c2 != '|' || c3 != ' ')
			std::cerr << BAD_SEP << c1 << c2 << c3 << "'" << std::endl;
		else if (value == -1)
			std::cerr << BAD_VALUE << num << "'" << std::endl;
		else
			printResult(date, value);
	}
}


void	BitcoinExchange::printResult(const int& date, const float& value)
{
	std::map<int, float>::iterator it = data.begin();

	for ( ; it != data.end() && it->first <= date; it++)
	{
		if (it->first == date)
			break ;
	}
	if (it != data.begin() && it->first != date)
		it--;
	std::cout << dateToStr(date) << " => " << value << " = " << value * it->second << std::endl;
}


void	BitcoinExchange::fileClose(void)
{ 
	file.close(); 
}

int BitcoinExchange::openFile(const char* infile)
{
	file.open(infile, std::fstream::in);
	if (!file.is_open())
		return (1);
	return (0);
}

int BitcoinExchange::getDatabase(int &err)
{
	if (openFile("data.csv"))
		return (1);

	std::string buffer;
	std::string first;
	int date = 0;
	double second = 0;
	char *end = NULL;

	getline(file, buffer); // skip TITLE line
	if (buffer != "date,exchange_rate")
	{
		err = 1;
		return (1);
	}
	while (getline(file, buffer))
	{
		std::stringstream ss(buffer);
		getline(ss, first, ','); // get in first everything before the ,
		ss >> buffer; // then put into second the number

		second = strtod(buffer.c_str(), &end);
		date = hashDate(first);
		if (date == -1 || *end)
		{
			err = 1;
			return (1);
		}
		data[date] = second; // create map, when map doesn't find the index, it creates it
	}
	file.close();
	return (0);
}


// Orthodox Cannonical Form
BitcoinExchange::BitcoinExchange()
{
	
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs)
{
	*this = rhs;
}

BitcoinExchange::~BitcoinExchange()
{
	
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this != &rhs)
	{
		data = rhs.data;
	}
	return (*this);
}
