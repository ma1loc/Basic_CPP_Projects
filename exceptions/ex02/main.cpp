# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <iostream>
# include <cstdlib>
# include <ctime>

int main()
{
	std::srand(std::time(NULL));
    std::cout << "=== Test 1: Successful Execution ===" << std::endl;
    try
    {
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        Bureaucrat boss("Boss", 1);

        shrub.beSigned(boss);
        robot.beSigned(boss);
        pardon.beSigned(boss);
        
        boss.executeForm(shrub);
        boss.executeForm(robot);
        boss.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Unsigned Form ===" << std::endl;
    try
    {
        ShrubberyCreationForm unsignedForm("test");

        Bureaucrat boss("Boss", 1);
        
        boss.executeForm(unsignedForm);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Grade Too Low ===" << std::endl;
    try
    {
        PresidentialPardonForm pardon("Criminal");
        Bureaucrat lowLevel("Intern", 50);
        
        pardon.beSigned(Bureaucrat("Boss", 1));
        lowLevel.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}