/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:58:04 by eagbomei          #+#    #+#             */
/*   Updated: 2024/12/30 16:40:40 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("defaultForm"), isExec(false) ,_gradeToExec(1), _gradeToSign(1), _isSigned(false) {}


AForm::AForm(std::string name, int exec, int sign, bool isExe) : _name(name), isExec(isExe) , _gradeToExec(exec), _gradeToSign(sign), _isSigned(false) {
	checkGrades(exec);
	checkGrades(sign);
}

AForm::AForm(const AForm& copy) : _name(copy._name), _gradeToExec(copy._gradeToExec), _gradeToSign(copy._gradeToSign), _isSigned(copy._isSigned) {
	checkGrades(this->_gradeToExec);
	checkGrades(this->_gradeToSign);
}

const AForm& AForm::operator=(const AForm& other){
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

void AForm::beSigned(const Bureaucrat& byro)
{
	bool val = this->getGradeToSign() >= byro.getGrade() ? true : false;
	if (val == true)
		AForm::setIsExec(val);
	else
   		throw GradeTooHighException();
}

void AForm::execute(Bureaucrat const & executor) const {
	if (_isSigned == false)
		throw std::invalid_argument("Form is not signed");
	if (isExec == true)
		throw std::invalid_argument("Forn has been executed already");
	if (executor.getGrade() > getGradeToExec())
		throw std::invalid_argument("grade too low to exec");
	setIsExec(true);
}

const char* AForm::GradeTooHighException::what() const noexcept {
	return ("Grade to sign too high / AForm can't be executed");
}

const char* AForm::GradeTooLowException::what() const noexcept {
	return ("Grade to sign too low / AForm out of bounds");
}



bool AForm::getSigned() const      {return this->_isSigned;		}
int  AForm::getGradeToSign() const {return this->_gradeToSign;	}
int  AForm::getGradeToExec() const {return this->_gradeToExec;	}
std::string AForm::getName() const {return this->_name;			}
bool AForm::getIsExec() const      {return this->isExec;        }
void AForm::setIsExec(bool val) const      {this->isExec = val; }
void AForm::setIsSigned(bool val) {this->_isSigned = val;}

 
std::ostream& operator<<(std::ostream& out, AForm const& AForm) {
	out <<  "AForm name: " << AForm.getName() << "." 
		<< " Grade to sign: " << AForm.getGradeToSign()
		<< " Grade to execute: " << AForm.getGradeToExec()
		<< " Is Grade signed: " << std::boolalpha << AForm.getSigned();
	return out;
}

void AForm::checkGrades(int value) {
	if (value < 1)
		throw GradeTooHighException();
	else if (value > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}