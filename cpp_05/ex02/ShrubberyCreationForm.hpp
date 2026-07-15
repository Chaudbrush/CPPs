/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:29:48 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/01 19:33:48 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include <iostream>
# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	// sign 145, exec 137
public:
	void execute(const Bureaucrat& executor) const;

	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm& other);

private:
	std::string target;
};

#endif