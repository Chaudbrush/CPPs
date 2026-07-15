/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:37:29 by vloureir          #+#    #+#             */
/*   Updated: 2026/07/01 07:59:00 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void Span::addNumber(int num)
{
	try
	{
		if (index >= max)
			throw(std::out_of_range("-error: cannot add number, out of range"));	
		data[index] = num;
		index++;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

// Utils
void Span::print(void) const
{
	std::vector<int>::const_iterator it;
	std::cout << "data: " << std::endl;
	for (it = data.begin(); it < data.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void Span::printAddr(void) const
{
	std::cout << "addr" << std::endl;
	for (unsigned int i = 0; i < max; i++)
		std::cout << &data[i] << " ";
	std::cout << std::endl;
}

size_t Span::get_size(void) const
{
	return (data.size());
}

int Span::shortestSpan(void)
{
	int res = __INT_MAX__;
	try
	{
		if (index < 2)
			throw(std::out_of_range("-error: not enough numbers to get the span"));
		std::vector<int> tmp;
		tmp = data;
		std::sort(tmp.begin(), tmp.end());

		for (unsigned int i = 0; i < index - 1; i++)
		{
			if (tmp[i + 1] - tmp[i] < res)
				res = tmp[i + 1] - tmp[i];
		}
		return (res);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (-1);
}

int Span::longestSpan(void)
{
	try
	{
		if (index < 2)
			throw(std::out_of_range("-error: not enough numbers to get the span"));	
//		t_pair_iterator it = std::minmax_element(data.begin(), data.begin() + index);
		std::vector<int>::iterator min = std::min_element(data.begin(), data.begin() + index);
		std::vector<int>::iterator max = std::max_element(data.begin(), data.begin() + index);
		std::cout << "biggest: " << *max << ", smallest: " << *min << std::endl;
		return (*max - *min);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (-1);
}

std::vector<int>::const_iterator Span::getBegin() const
{
	return (data.begin());
}

std::vector<int>::const_iterator Span::getEnd() const
{
	return (data.end());
}


// Orthodox Cannonical Form
Span::Span() : max(0), index(0), data(0)
{

}

Span::Span(unsigned int num) : max(num), index(0), data(num)
{

}

Span::Span(const Span& other) : max(other.max), index(other.index), data(other.max)
{
	for (unsigned int i = 0; i < max; i++)
		data[i] = other.data[i];
}

Span::~Span()
{

}

Span &Span::operator=(const Span& other)
{
	if (this != &other)
	{
		max = other.max;
		index = other.index;
		data = other.data;
	}
	return (*this);
}
