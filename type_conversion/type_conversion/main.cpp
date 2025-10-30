# include <iostream>
# include "ScalarConverter.hpp"

// struct A { int x;};
// struct B { double y;};

// int main() {
//     A a = {20};
//     B* b1 = static_cast<B*>(&a);
    
//     B* b2 = (B*)&a;
// }

int main(int argc, char **argv)
{
    if (argc != 2)
		return (std::cout << "args not valid" << std::endl, 1);
	std::string input = argv[1];
    ScalarConverter::convert(input);

    return (0);
}
