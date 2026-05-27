/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:32:49 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/16 11:42:38 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractional = 8;

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixed);
}

void Fixed::setRawBits(int const raw)
{
	fixed = raw;
}

// Orthodox Cannonical Form
Fixed::Fixed() : fixed(0) // default constructor
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) // copy constructor
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed = other.getRawBits();
//	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixed = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() // destructor
{
	std::cout << "Destructor called" << std::endl;
}

// Ex01
Fixed ::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(num << fractional);
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
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