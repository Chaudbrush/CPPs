/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:01:50 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/12 15:16:12 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Complex.hpp"

void Complex::setX(int x)
{
	this->x = x;
}

void Complex::setY(int y)
{
	this->y = y;
}

int Complex::getX(void) const
{
	return (this->x);
}

int Complex::getY(void) const
{
	return (this->y);
}

// Orthodox Cannonical Form
Complex::Complex() : x(0), y(-2)
{

}

Complex::Complex(int x, int y) : x(x), y(y)
{

}

Complex::Complex(const Complex& other) : x(other.x), y(other.y)
{
	
}

Complex::~Complex()
{
	
}

Complex &Complex::operator=(const Complex& other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return (*this);
}

// Comparison
bool Complex::operator<(const Complex& other) const
{
	if (this->x + this->y < other.x + other.y)
		return (true);
	return (false);
}

bool Complex::operator>(const Complex& other) const
{
	if (this->x + this->y > other.x + other.y)
		return (true);
	return (false);
}

// Operator <<
std::ostream& operator<<(std::ostream& out, const Complex& data)
{
	out << data.getX() << ", " << data.getY();
	return (out);
}