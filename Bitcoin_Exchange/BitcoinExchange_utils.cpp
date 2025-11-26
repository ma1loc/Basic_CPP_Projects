# include "BitcoinExchange.hpp"
# include <iostream>
# include <cstdlib>
# include <sstream>

unsigned int get_date(std::string &line)
{
    std::string date;
    date = line.substr(0, 10);
    date.erase(date.find('-'), 1);
    date.erase(date.find('-'), 1);
    return (std::atoi(date.c_str()));
}

float   get_exchange_rate(std::string &line)
{
    std::string ex_rate = line.substr(line.find(',') + 1, line.size());
    return (std::atof(ex_rate.c_str()));
}

std::string get_IDate(std::string &date)
{
    std::string::iterator it = date.begin();
    std::string::iterator ite = date.begin() + 8;

    std::string new_date;
    if (*(it + 4) == '-' && *(it + 7) == '-')
    {
        date.erase(it + 4);
        date.erase(it + 6);
        for (int i = 0; it != ite; it++)
        {
            if (isdigit(*it))
            {
                new_date.push_back(*it);
                i++;
            }
            else
                return ("");
        }
    }
    else
        return ("");
    return (new_date);
}

std::string get_IValue(std::string &value)
{
    (void)value;
    std::string::iterator it = value.begin() + 8;
    std::string::iterator ite = value.end();
    std::string new_value;

    if ((ite - it) < 3)
        return ("");
    if (!std::isspace(*it))
        return ("");
    it++;
    if (*it != '|')
        return ("");
    it++;
    if (!std::isspace(*it))
        return ("");
    it++;
    for (;it != ite; it++)
    {
        new_value.push_back(*it);    
    }
    return (new_value);
}


// NOTE: check the 1900year tests to understand batter.
unsigned int get_days_of_month(int year, int month)
{
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)  // check leap year here
            return 29;  // leap year
        else
            return 28; // normal
    }
    return 31;
};

int is_date_valid(std::string &date)
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
    
    year = std::atoi(date.substr(0, 4).c_str());
    month = std::atoi(date.substr(4, 2).c_str());
    day = std::atoi(date.substr(6, 2).c_str());

    if (month > 12)
    {
        std::cout << "Error: bad month provided => " << month << std::endl;
        return (-1);
    }
    if (day > 31 ||  day > get_days_of_month(year, month))
    {
        std::cout << "Error: bad day provided => " << day << std::endl;
        return (-1);
    }
    return (std::atoi(date.c_str()));
}

double    is_value_valid(std::string value)
{
    std::stringstream iss(value);
    double new_value ;
    iss >> new_value;

    if (iss.fail() || !iss.eof())
    {
        std::cout << "Error: fail to convert provided value => '" << value << "'" << std::endl;
        return (-1);
    }
    if (new_value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return (-1);
    }
    if (new_value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return (-1);
    }
    return (new_value);
}

void            show_result(unsigned int date, double value, iter obj)
{
    std::stringstream ss;
    ss << date;

    std::string s_date = ss.str();

    s_date.insert(4, 1, '-');
    s_date.insert(7, 1, '-');
    std::cout << s_date << " => " << value << " = " << (obj->second * value) << std::endl;
}