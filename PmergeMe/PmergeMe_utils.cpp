# include "PmergeMe.hpp"
# include <sstream>
# include <iostream>
# include <algorithm>

std::string trim(const std::string &s)
{
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end   = s.find_last_not_of(" \t\n\r");
    if (start == std::string::npos)
        return "";
    return s.substr(start, end - start + 1);
}

bool    is_valid_number(std::string token)
{
    int number = 0;
    std::istringstream sst(token);
    sst >> number;

    if (sst.fail() || !sst.eof() || number < 0)
        return (false);
    return (true);
}

bool    there_is_duplicate(std::vector<int> tokens)
{
    std::sort(tokens.begin(), tokens.end());
    iter it = tokens.begin();
    iter ite = tokens.end();

    for (; it != ite; it++)
    {
        if ((it + 1) != ite)
        {
            if (*it == *(it+1))
                return (true);
        }
        else
            break;
    }
    return (false);
}
