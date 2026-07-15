/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:29:48 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/01 19:33:30 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
// sign 25, exec 5
public:
	void execute(const Bureaucrat& executor) const;

	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm& other);

private:
	std::string target;
};

#endif