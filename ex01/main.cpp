#include "Bureaucrat.hpp"

int main()
{
	try{
		Bureaucrat alpo("Tim", 10);
	
		alpo.increamentGrade();
		Bureaucrat josh(alpo);
		Bureaucrat jerry;

		jerry = josh;
		try
		{
			Bureaucrat topi("timo", 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		alpo.increamentGrade();
		alpo.increamentGrade();
		alpo.increamentGrade();
		alpo.increamentGrade();
		alpo.increamentGrade();
		alpo.increamentGrade();
		alpo.increamentGrade();
		alpo.increamentGrade();
		


		std::cout << jerry << std::endl;
		std::cout << josh << std::endl;
		std::cout << alpo << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}