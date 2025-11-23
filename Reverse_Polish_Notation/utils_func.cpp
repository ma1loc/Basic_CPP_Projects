# include "RPN.hpp"

std::string trim(const std::string &s)
{
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end   = s.find_last_not_of(" \t\n\r");
    if (start == std::string::npos)
        return "";
    return s.substr(start, end - start + 1);
}

bool isoperator(char &c)
{
    if (c == '+' || c == '*' || c == '/' || c == '-')
        return (true);
    return (false);
}

int operation_between_two(int f_nbr, int s_nbr, char operation)
{
    switch (operation)
    {
        case '+':
            return (f_nbr + s_nbr);
            break;
        case '-':
            return (f_nbr - s_nbr);
            break;
        case '*':
            return (f_nbr * s_nbr);
            break;
        case '/':
            if (s_nbr == 0)
                throw ("Divition by zero is not valie");
            return (f_nbr / s_nbr);
            break;
        default:
            break;
    }
    return (0);
}
