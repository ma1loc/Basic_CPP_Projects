# include <iostream>
# include "RPN.hpp"

int main(int argc, char *argv[])
{
    // TODO: most parse this and first 
    // TODO: reverse order to easy access to the element
    // TODO: perfforem the operation

    try
    {
        RPN rpn;

        if (argc != 2)
            throw ("Input Argument is limit to just tow argc");
        
        rpn.input_parsing(argv[1]);
        rpn.set_stackA();
        rpn.operation_exec();
		std::cout << rpn.get_stackB() << std::endl;
    }
    catch (const char *e)
    {
        std::cout << "Exception: " << e << std::endl;
        return (1);
    }
    return (0);
}