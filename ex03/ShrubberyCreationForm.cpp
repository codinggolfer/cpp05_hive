/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:04:46 by eagbomei          #+#    #+#             */
/*   Updated: 2024/12/30 16:48:31 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrub", 137, 145, false) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string targetti) : AForm("shrubbery", 137, 145, false), target(targetti) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), target(copy.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

void ShrubberyCreationForm::doShurberry(std::string target) const
{
	std::ofstream file(target + "_shrubbery");
	
	if (!file.is_open())
		throw std::invalid_argument("File failed to be opened/created");
	file << "        /\\\n       /00\\\n      /0000\\\n     /000000\\\n    /00000000\\\n   /0000000000\\\n  /____________\\\n       |  |\n       |  |\n       |  |\n";
	file.close();
	std::cout << target << "'s shrubbery file has been executed\n";
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	AForm::execute(executor);
	doShurberry(executor.getName());
}

void ShrubberyCreationForm::beSigned(const Bureaucrat& byro)
{
	bool val = this->getGradeToSign() >= byro.getGrade() ? true : false;
	if (val == true)
		AForm::setIsSigned(val);
	else
   		throw GradeTooHighException();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
