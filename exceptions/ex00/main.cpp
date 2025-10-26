# include "Bureaucrat.hpp"
# include <iostream>

int main()
{
	try
	{
		std::cout << "=== TEST 1: decr/incr ===" << std::endl;

		Bureaucrat a("Bureaucrat_A", 1);
		std::cout << a << std::endl;

		Bureaucrat b("Bureaucrat_B", 150);
		std::cout << b << std::endl;

		std::cout << a << std::endl;
		
		b.decr_Bureaucrat();
		std::cout << b << std::endl;
	}
	catch (const std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	try
	{
		std::cout << "=== TEST 2: decr/incr ===" << std::endl;

		Bureaucrat a("Bureaucrat_A", 1);
		std::cout << a << std::endl;

		a.incr_Bureaucrat();
		std::cout << a << std::endl;
	}
	catch (const std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	try
	{
		std::cout << "=== TEST 3: Bureaucrat with -1  ===" << std::endl;

		Bureaucrat a("Bureaucrat_C", -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "=== TEST 4 Bureaucrat with 999  ===" << std::endl;

		Bureaucrat a("Bureaucrat_D", 999);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	return (0);
}
