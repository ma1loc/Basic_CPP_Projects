# include "RPN.hpp"
# include <iostream>
# include <algorithm>
# include <cctype> 

RPN::RPN() {}

RPN::RPN(const RPN &copy) {(void)copy;}

RPN &RPN::operator=(const RPN &copy) {(void)copy; return (*this);}

RPN::~RPN() {}

void RPN::input_parsing(std::string &input)
{
    if (input.empty())
        throw ("Empty args proveded");

    std::string input_trim = trim(input);
    std::string::iterator it = input_trim.begin();
    std::string::iterator ite = input_trim.end();

    for (; it != ite; it++)
    {
        if (std::isspace(*it))
            continue;

        else if (std::isdigit(*it) || isoperator(*it))
        {
            if ((it + 1 == ite) || std::isspace(*(it + 1)))
                v_input.push_back(*it);
            else
                throw ("Input provided not follow syntax req.");
        }
        else
            throw ("Input provided can done with it an operation.");
    }
    if (v_input.size() == 2)
        throw ("Opeation is not valid wiht provide input");
}

void RPN::exec_operation(std::string argv)
{
    input_parsing(argv);
    if (v_input.empty())
        throw ("Empty args provided");
    
    size_t i = 0;
    while (i < v_input.size())
    {
        std::cout << "isdigit -> " << v_input.at(i) << std::endl;
        if (isdigit(v_input.at(i)))
            stackA.push(v_input.at(i) - '0');
        else
        {
            if (stackA.size() <= 1)
                throw ("invalid operation");
            int left = stackA.top();
            stackA.pop();
            int right = stackA.top();
            stackA.pop();

            std::cout << "\tleft -> " << left << std::endl;
            std::cout << "\tright -> " << right << std::endl;
            std::cout << "\toper -> " << v_input.at(i) << std::endl;

            stackA.push(operation_between_two(right, left, v_input.at(i)));
        }
        i++;
    }
    if (stackA.size() == 2)
        throw ("Operation not valie");
}

long RPN::get_stackA()
{
    return (stackA.top());
}