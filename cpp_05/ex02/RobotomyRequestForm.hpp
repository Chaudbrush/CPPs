/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:29:48 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/01 19:33:40 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include <iostream>
# include <string>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	// sign 145, exec 137
public:
	void execute(const Bureaucrat& executor) const;

	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm& other);

private:
	std::string target;
};

#endif