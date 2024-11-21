#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try{
		Bureaucrat alpo("Tim", 10);
		Form first("killable", -1, 9);
		first.beSigned(alpo);
		alpo.signForm(first);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}