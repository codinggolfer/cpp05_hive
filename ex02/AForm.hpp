/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:57:19 by eagbomei          #+#    #+#             */
/*   Updated: 2024/12/23 16:16:00 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>


class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	const int _gradeToExec;
	const int _gradeToSign;
	bool  _isSigned;
public:
	AForm();

	bool getSigned();
	int  getGradeToSign();
	int  getGradeToExec();
	std::string getName();

	void beSigned(Bureaucrat&);
	virtual void checkGrades(int value) const = 0;

	class GradeTooHighException : public std::exception {
		virtual const char* what() const noexcept override;
	} ;
	class GradeTooLowException : public std::exception {
		virtual const char* what() const noexcept override;
	} ;


	virtual ~AForm() = 0;
};