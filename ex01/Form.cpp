/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:09:04 by eagbomei          #+#    #+#             */
/*   Updated: 2024/11/12 13:04:50 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("defaultForm"), _gradeToExec(1), _gradeToSign(1), _isSigned(false) {}


Form::Form(std::string name, int exec, int sign) : _name(name), _gradeToExec(exec), _gradeToSign(sign), _isSigned(false) {
	checkGrades(exec);
	checkGrades(sign);
}

void Form::beSigned(Bureaucrat& byro)
{
	this->_isSigned = this->_gradeToSign >= byro.getGrade() ? true : false;
	// if (this->_gradeToSign >= byro.getGrade()) 
    // 	this->_isSigned = true;
	// else 
   	// 	throw GradeTooHighException();
}

void Form::singForm() {
	
}










const char* Form::GradeTooHighException::what() const noexcept {
	return ("Grade to sign too high / Form can't be executed");
}

const char* Form::GradeTooLowException::what() const noexcept {
	return ("Grade to sign too low / Form out of bounds");
}



bool Form::getSigned() 		{return this->_isSigned;	}
int  Form::getGradeToSign() {return this->_gradeToSign;	}
int  Form::getGradeToExec() {return this->_gradeToExec;	}
std::string Form::getName() {return this->_name;		}

std::ostream& operator<<(std::ostream& out, Form Form) {
	out <<  "Form name: " +  << ".";
	return out;
}

void Form::checkGrades(int value) {
	if (value < 1)
		throw GradeTooHighException();
	else if (value > 150)
		throw GradeTooLowException();
}