# include <iostream>
# include "RPN.hpp"

int main(int argc, char *argv[])
{
    try
    {
        RPN rpn;

        if (argc != 2)
            throw ("Input Argument is limit to just tow argc");

        rpn.exec_operation(argv[1]);
        std::cout << rpn.get_stackA() << std::endl;
        
    }
    catch (const char *e)
    {
        std::cout << "Exception: " << e << std::endl;
        return (1);
    }
    return (0);
}