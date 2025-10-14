# include "Bureaucrat.hpp"
# include "Form.hpp"
# include <iostream>

int main() {
    std::cout << "=== TEST 1: Valid Forms ===" << std::endl;
    try {
        Form form1("Tax Form", 50, 25);
        Form form2("Permit", 100, 75);
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Invalid Form (grade 0) ===" << std::endl;
    try {
        Form invalid("Bad Form", 0, 50);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Successful Signing ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 30);
        Form form("Simple Form", 50, 40);
        std::cout << alice << std::endl;
        std::cout << form << std::endl;
        
        form.beSigned(alice);
        alice.signForm(form);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Failed Signing ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 100);
        Form important("Important Form", 50, 25);
        std::cout << bob << std::endl;
        std::cout << important << std::endl;
        
        try {
            important.beSigned(bob);
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        bob.signForm(important);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: Edge Cases ===" << std::endl;
    try
    {
        Bureaucrat top("Boss", 1);
        Bureaucrat bottom("Intern", 150);

        Form easy("Easy", 150, 150);
        Form hard("Hard", 1, 1);
        
        easy.beSigned(bottom);
        bottom.signForm(easy);
        
        hard.beSigned(top);
        top.signForm(hard);
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
