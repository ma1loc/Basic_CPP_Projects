# include <iostream>
# include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (std::cout << "args not valid" << std::endl, 1);
    
    std::string input = argv[1];
    if (input_parsing(input))
        return (1);
    
    ScalarConverter::convert(input);

    return (0);
}
