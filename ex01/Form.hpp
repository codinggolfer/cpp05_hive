/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:01:05 by eagbomei          #+#    #+#             */
/*   Updated: 2024/11/21 13:54:55 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	const int _gradeToExec;
	const int _gradeToSign;
	bool  _isSigned;
public:
	Form();
	Form(std::string, int, int);
	Form(Form& copy);
	Form& operator=(Form& other);

	bool getSigned();
	int  getGradeToSign();
	int  getGradeToExec();
	std::string getName();

	void beSigned(Bureaucrat&);
	void checkGrades(int value);

	class GradeTooHighException : public std::exception {
		virtual const char* what() const noexcept override;
	} ;
	class GradeTooLowException : public std::exception {
		virtual const char* what() const noexcept override;
	} ;


	~Form();
};

std::ostream& operator<<(std::ostream& out, Form Form);