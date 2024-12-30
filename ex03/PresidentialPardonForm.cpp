/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:04:05 by eagbomei          #+#    #+#             */
/*   Updated: 2024/12/30 16:48:15 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("pressa", 5, 25, false) {}

PresidentialPardonForm::PresidentialPardonForm(std::string targetti) : AForm("pressa", 5, 25, false), target(targetti) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy), target(copy.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

void PresidentialPardonForm::pardon(const Bureaucrat& target) const
{
	std::cout << target.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	pardon(executor);
}

void PresidentialPardonForm::beSigned(const Bureaucrat& byro)
{
	bool val = this->getGradeToSign() >= byro.getGrade() ? true : false;
	if (val == true)
		AForm::setIsSigned(val);
	else
   		throw GradeTooHighException();
}
PresidentialPardonForm::~PresidentialPardonForm() {}