#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("defaultByro"), _grade(50) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (this->_grade < 1)
		throw GradeTooHighException();
	else if (this->_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat& copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other) {
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept{
	return "Byro grade can't be this low";
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return "Byro grade can't be this high.";
}

void Bureaucrat::signForm(AForm& form) {
	if (this->_grade <= form.getGradeToSign())
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	else
		std::cout << this->_name << " couldn't sign " << form.getName() << "because of politics bruh" << std::endl;
}

void Bureaucrat::executeForm(AForm const & Form) {
	if (Form.getIsExec() == true)
		std::cout << this->_name << " executed " << Form.getName() << std::endl;
	else
		std::cout << "for some reason byrokraut wasn't able to execute this form.";
}


std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::increamentGrade(){
	this->_grade--;
	if (this->_grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
	this->_grade++;
	if (this->_grade > 150)
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, Bureaucrat byro) {
	out << byro.getName() + ", bureaucrat grade " << byro.getGrade() << ".";
	return out;
}

Bureaucrat::~Bureaucrat() {}