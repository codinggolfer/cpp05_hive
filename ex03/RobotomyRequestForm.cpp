/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:04:16 by eagbomei          #+#    #+#             */
/*   Updated: 2024/12/30 16:48:26 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("roubou", 45, 72, false) {}

RobotomyRequestForm::RobotomyRequestForm(std::string targetti) : AForm("ropotti", 45, 72, false), target(targetti) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy), target(copy.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

void RobotomyRequestForm::beSigned(const Bureaucrat& byro)
{
	
	bool val = this->getGradeToSign() >= byro.getGrade() ? true : false;
	if (val == true)
		AForm::setIsSigned(val);
	else
   		throw GradeTooHighException();
}

void RobotomyRequestForm::robotomy(const Bureaucrat& target) const {
	std::cout << "loud drilling noices" << std::endl;
	int success = rand() % 2;
    if (success) {
        std::cout << target.getName() << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy of " << target.getName() << " failed." << std::endl;
	}
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	robotomy(executor);
}

RobotomyRequestForm::~RobotomyRequestForm() {}