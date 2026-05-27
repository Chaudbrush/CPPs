/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:32:49 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/16 12:23:35 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractional = 8;

int	Fixed::getRawBits(void) const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return (fixed);
}

void Fixed::setRawBits(int const raw)
{
	fixed = raw;
}

// Orthodox Cannonical Form
Fixed::Fixed() : fixed(0) // default constructor
{
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) // copy constructor
{
//	std::cout << "Copy constructor called" << std::endl;
	this->fixed = other.getRawBits();
//	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixed = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() // destructor
{
//	std::cout << "Destructor called" << std::endl;
}

// Ex01
Fixed ::Fixed(const int num)
{
//	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(num << fractional);
}

Fixed::Fixed(const float num)
{
//	std::cout << "Float constructor called" << std::endl;
	this->fixed = roundf((num) * static_cast<double>(1 << fractional));
}

float Fixed::toFloat(void) const
{
	return ((this->fixed) / static_cast<double>(1 << fractional));
}

int Fixed::toInt(void) const
{
	return (this->fixed >> fractional);
}

std::ostream &operator<<(std::ostream& out, const Fixed& other)
{
	out << other.toFloat();
	return (out);
}

// Ex 02

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other)
{
	Fixed sum;
	
	sum.fixed = this->fixed + other.fixed;
	return (sum);
}

Fixed Fixed::operator-(const Fixed& other)
{
	Fixed sub;
	
	sub.fixed = this->fixed - other.fixed;
	return (sub);
}

Fixed Fixed::operator*(const Fixed& other)
{
	Fixed 	mult;
	long	res;

	res = static_cast<long>(this->fixed * other.fixed) >> fractional;
	mult.fixed = res;
	return (mult);
}

Fixed Fixed::operator/(const Fixed& other)
{
	Fixed	div;
	long	res;
	
	res = ((this->fixed << fractional) / other.fixed) ;
	div.fixed = res;
	return (div);
}

// Comparison operators
bool Fixed::operator>(const Fixed& other)
{
	if (this->fixed > other.fixed)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& other)
{
	if (this->fixed < other.fixed)
		return (true);
	return (false);

}

bool Fixed::operator>=(const Fixed& other)
{
	if (this->fixed >= other.fixed)
		return (true);
	return (false);

}

bool Fixed::operator<=(const Fixed& other)
{
	if (this->fixed <= other.fixed)
		return (true);
	return (false);

}

bool Fixed::operator==(const Fixed& other)
{
	if (this->fixed == other.fixed)
		return (true);
	return (false);

}

bool Fixed::operator!=(const Fixed& other)
{
	if (this->fixed != other.fixed)
		return (true);
	return (false);
	
}

// Increment / Decrement operators
Fixed Fixed::operator++(void)
{
	this->fixed++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	
	this->fixed++;
	return (tmp);
}

Fixed Fixed::operator--(void)
{
	this->fixed--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	
	this->fixed--;
	return (tmp);
}

// Min and Max
Fixed &Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1.fixed < f2.fixed)
		return (f1);
	return (f2);
}

const Fixed &Fixed::min(const Fixed& f1, const Fixed& f2)
{	
	if (f1.fixed < f2.fixed)
		return (f1);
	return (f2);
}

Fixed &Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1.fixed > f2.fixed)
		return (f1);
	return (f2);
}

const Fixed &Fixed::max(const Fixed& f1, const Fixed& f2)
{	
	if (f1.fixed > f2.fixed)
		return (f1);
	return (f2);
}