#pragma once

#include <iostream>
#include <exception>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(Bureaucrat& copy);
	Bureaucrat& operator=(Bureaucrat& other);

//member functions: getname and grade, decrement and increment.
	std::string getName();
	int getGrade();
	void increamentGrade();
	void decrementGrade();


//Exception classes	
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const noexcept override;
	};
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const noexcept override;
	};

	~Bureaucrat();
};

std::ostream& operator<<(std::ostream& out, Bureaucrat byro);