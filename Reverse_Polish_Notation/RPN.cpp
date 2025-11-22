# include "RPN.hpp"
# include <iostream>
# include <algorithm>
# include <cctype> 

RPN::RPN() {}

RPN::RPN(const RPN &copy) {(void)copy;}

RPN &RPN::operator=(const RPN &copy) {(void)copy; return (*this);}

RPN::~RPN() {}

void RPN::input_parsing(std::string input)
{
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
                new_input.push_back(*it);
            else
                throw ("Input provided not follow syntax req.");
        }
        else
            throw ("Input provided can done with it an operation.");
    }
}

void RPN::set_stackA()
{
    std::reverse(new_input.begin(), new_input.end());

    std::string::iterator it = new_input.begin();
    std::string::iterator ite = new_input.end();

    for (; it != ite; it++)
        stackA.push(*it);
}

void RPN::operation_exec()
{
    int first_number = 0;
    int second_number = 0;

	while (stackA.size() > 0)
	{
		if (stackB.size() == 0 && stackA.size() >= 3)
		{
			first_number = (stackA.top() - '0');
			stackA.pop();
			second_number = (stackA.top() - '0');
			stackA.pop();
			std::cout << first_number << " " << stackA.top() << " " << second_number;
			if (isoperator(stackA.top()))
			{
				stackB.push(operation_between_two(first_number, second_number, stackA.top()));
				stackA.pop();
				std::cout << " result -> " << stackB.top() << std::endl;
			}
			else
				throw("Invalid operation arithmetic provided.");
		}
		else if (stackB.size() == 1 && stackA.size() >= 2)	// here i excepact that stackb have a element
		{
			first_number = (stackB.top());
			stackB.pop();
			second_number = (stackA.top() - '0');
			stackA.pop();
			std::cout << first_number << " " << stackA.top() << " " << second_number;
			if (isoperator(stackA.top()))
			{
				stackB.push(operation_between_two(first_number, second_number, stackA.top()));
				stackA.pop();
				std::cout << " result -> " << stackB.top() << std::endl;
			}
		}
		else
			throw ("Invalid input provied");
	}
	
}

int	RPN::get_stackB()
{
	return (stackB.top());
}