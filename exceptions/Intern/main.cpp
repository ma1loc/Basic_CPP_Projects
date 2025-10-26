# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"
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
	
	std::cout << "\n=== Test 4: Intern Creates Forms ===" << std::endl;
    try
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);
        
        AForm *form1 = intern.makeForm("shrubbery creation", "garden");
        AForm *form2 = intern.makeForm("robotomy request", "Target");
        AForm *form3 = intern.makeForm("presidential pardon", "Prisoner");
        
        form1->beSigned(boss);
        form2->beSigned(boss);
        form3->beSigned(boss);
        
        boss.executeForm(*form1);
        boss.executeForm(*form2);
        boss.executeForm(*form3);
        
        delete form1;
        delete form2;
        delete form3;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 5: Intern Invalid Form ===" << std::endl;
    try
    {
        Intern intern;
        AForm *form = intern.makeForm("invalid form", "target");
        delete form;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
