/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:29:45 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/01 19:33:45 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	std::string file_name;
	std::fstream out_file;

	file_name = target + "_schrubbery";
	if (checkSignature() == false)
		throw(NotSignedException());
	if (executor.getGrade() > this->getToExec())
		throw(GradeTooLowException());
	out_file.open(file_name.c_str(), std::fstream::out);
	
	out_file << "\n                    &&\n";
	out_file << "                  && &&&\n";
	out_file << "               &&&&&&    &  &&&&\n";
	out_file << "              &/|&   &   &&&  &&&&\n";
	out_file << "             &&  &/&/&~   &&&_/&&& &\n";
	out_file << "                 /~/     _/     &&\n";
	out_file << "                  /| _/   \\|_/\n";
	out_file << "                  \\   _/\n";
	out_file << "        &  &&  &&  \\\n";
	out_file << "        &&&/ &   & /|         &&\n";
	out_file << "      & &&& &&& &   / |__    &&&& &&\n";
	out_file << "       &&&&& /\\_ /   \\___ &&&&&  &&&\n";
	out_file << "          &    / /         &&&&_/ &&& \n";
	out_file << "                /~/|      &&  &&&&\n";
	out_file << "                  /\n";
	out_file << "                 /-/~\n";
	out_file << "                   /~/|\n";
	out_file << "                   /|\n";
	out_file << "     :___________./~~\\.___________:\n";
	out_file << "      \\                          /\n";
	out_file << "       \\________________________/\n";
	out_file << "        (_)                  (_)" << std::endl;
	
	out_file.close();
}

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Default ShrubberyCreationForm", 145, 137), target("Default_target")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other.getName(), 145, 137), target(other.target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	// Dont understand what am I supposed to do here?
	if (this != &other)
	{
		(void)other;
	}
	return (*this);
}
