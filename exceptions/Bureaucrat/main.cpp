# include "Bureaucrat.hpp"
# include <iostream>

int main()
{
	try {
		Bureaucrat a("Bureaucrat_A", 1);
		std::cout << a << std::endl;

		Bureaucrat b("Bureaucrat_B", 150);
		std::cout << b << std::endl;

		//a.incr_Bureaucrat();
		std::cout << a << std::endl;
		
		b.decr_Bureaucrat();
		std::cout << b << std::endl;
	}
	//catch (std::exception &ex) { // why const refrance not just std::exception ???
	catch (const std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	return (0);
}

