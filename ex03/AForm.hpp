/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:57:19 by eagbomei          #+#    #+#             */
/*   Updated: 2024/12/30 16:35:18 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"


class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	mutable bool isExec;
	const int _gradeToExec;
	const int _gradeToSign;
	bool  _isSigned;
public:
	AForm();
	AForm(std::string, int, int, bool);
	AForm(const AForm& copy);
	const AForm& operator=(const AForm& other);

	bool getSigned() const;
	int  getGradeToSign() const;
	int  getGradeToExec() const;
	std::string getName() const;
	bool getIsExec() const;

	void setIsExec(bool) const;
	void setIsSigned(bool val);
	virtual void beSigned(const Bureaucrat&) = 0;
	void checkGrades(int value);

	void execute(Bureaucrat const & executor) const;

	class GradeTooHighException : public std::exception {
		virtual const char* what() const noexcept override;
	} ;
	class GradeTooLowException : public std::exception {
		virtual const char* what() const noexcept override;
	} ;


	virtual ~AForm() = 0;
};

std::ostream& operator<<(std::ostream& out, AForm const& Form);