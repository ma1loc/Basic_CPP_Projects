# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <iostream>

int main()
{
	try
	{
		Bureaucrat a("test", 200);
		ShrubberyCreationForm s;
		s.beSigned(a);
		s.execute(a);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}
    return 0;
}
