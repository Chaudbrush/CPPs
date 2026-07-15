/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:59:09 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/12 15:16:37 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class Complex
{
public:
	void setX(int x);
	void setY(int y);
	int getX(void) const;
	int getY(void) const;
	
	Complex();
	Complex(int x, int y);
	Complex(const Complex& other);
	~Complex();

	Complex &operator=(const Complex& other);

	bool operator<(const Complex& other) const;
	bool operator>(const Complex& other) const;

private:
	int x;
	int y;
};

std::ostream& operator<<(std::ostream& out, const Complex& data);
