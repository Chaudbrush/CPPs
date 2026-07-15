/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 11:16:40 by vloureir          #+#    #+#             */
/*   Updated: 2026/07/14 12:53:56 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::string RPN::evalLine(std::string line)
{
	float lhs = 0, rhs = 0;
	
	if (line.size() == 0)
		return ("empty line");
	for (size_t i = 0; i < line.size(); i++)
	{
		if (i % 2 && i < line.size() - 1 && line[i] == ' ')
			continue;
		if (i % 2 && line[i] != ' ')
			return ("unexpected token");
		else if (isdigit(line[i]))
			nums.push_back(line[i] - '0');
		else
		{
			if (line[i] != '+' && line[i] != '-' && line[i] != '/' && line[i] != '*')
				return ("unexpected token");
			if (nums.size() < 2)
					return ("missing numeric arguments");
			rhs = nums.back();
			nums.pop_back();
			lhs = nums.back();
			nums.pop_back();
			switch(line[i])
			{
				case('+'):
					nums.push_back(lhs + rhs);
					break ;
				case('-'):
					nums.push_back(lhs - rhs);
					break ;
				case('*'):
					nums.push_back(lhs * rhs);
					break ;
				case('/'):
					if (rhs == 0)
						return ("division by 0");
					nums.push_back(lhs / rhs);
			}
//			std::cout << lhs << " " << line[i] << " " << rhs << std::endl;
		}
	}
	if (nums.size() > 1)
		return ("missing arithmetic operator");
	std::cout << nums.back() << std::endl;
	return ("ok");
}

// Orthodox Cannonical Form
RPN::RPN()
{

}

RPN::RPN(const RPN& rhs)
{
	*this = rhs;
}

RPN::~RPN()
{

}

RPN& RPN::operator=(const RPN& rhs)
{
	if (this != &rhs)
	{
		nums = rhs.nums;
	}
	return (*this);
}
