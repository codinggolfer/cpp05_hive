#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	try 
	{
		Bureaucrat	Bob("Bob", 134); 
		Bureaucrat	Mary("Mary", 44);
		Bureaucrat	Tom("Tom", 4);
		
		ShrubberyCreationForm	Shrub("Bob"); //Grade 145 Exec 137
		RobotomyRequestForm		Robot("Mary"); //Grade 72 Exec 45
		PresidentialPardonForm	Zaphod("Tom"); //Grade 25 Exec 5
		
		std::cout << "\n*****BUREAUCRAT INFO*****\n\n";
		std::cout << Mary << "\n";
		std::cout << Bob << "\n";
		std::cout << Tom << "\n";
		std::cout << "\n*****FORM INFO*****\n\n";
		std::cout << Shrub << "\n";
		std::cout << Robot << "\n";
		std::cout << Zaphod << "\n";

		Shrub.beSigned(Bob);
		Robot.beSigned(Mary);
		Zaphod.beSigned(Tom);

		Shrub.execute(Bob);
		Robot.execute(Mary);
		Zaphod.execute(Tom);
		//Shrub.execute(Bob);
		
		std::cout << "\n*****BUREAUCRAT SIGNING FORMS*****\n\n";
		Bob.signForm(Shrub);
		Mary.signForm(Robot);
		Tom.signForm(Zaphod);

		std::cout << "\n*****BUREAUCRAT EXECUTING FORMS*****\n\n";
		Bob.executeForm(Shrub);
		Mary.executeForm(Robot);
		Tom.executeForm(Zaphod);
		
		std::cout << "\n*****FORM STATUS POST-SIGNING*****\n\n";
		std::cout << Shrub;
		std::cout << Robot;
		std::cout << Zaphod;
		
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}