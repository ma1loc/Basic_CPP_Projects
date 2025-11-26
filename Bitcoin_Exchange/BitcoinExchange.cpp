# include "BitcoinExchange.hpp"
# include <fstream>
# include <iostream>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# include <string>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {(void)copy;}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {(void)copy; return (*this);}

BitcoinExchange::~BitcoinExchange() {}

// 2012-01-11 | 1
void BitcoinExchange::get_Bitcoin_rate(unsigned int date, double value)
{
    iter ite = this->DB.end();
    iter obj = DB.find(date);

    if (obj == ite)
    {
        iter lower_one = DB.lower_bound(date);
        lower_one--;
        if (lower_one->first <= date)
            show_result(date, value, lower_one);
    }
    else
        show_result(date, value, obj);
}

void    BitcoinExchange::extract_FIpnut_info(std::string &line)
{
    std::string new_date = get_IDate(line);
    std::string new_value = get_IValue(line);
    if (new_date.empty() || new_value.empty())
    {
        std::cout << "Error: bad input => '" << line << "'" << std::endl;
        return ;
    }
    
    unsigned int FI_date = is_date_valid(new_date);
    double FI_value = is_value_valid(new_value);
    if ((FI_date != 1) &&  (FI_value != -1))
        get_Bitcoin_rate(FI_date, FI_value);
}

void    BitcoinExchange::set_FInput(std::string input_file)
{
    std::ifstream inputFile(input_file.c_str(), std::ifstream::in);
    if (!inputFile.is_open())
        throw ("could not open DB file.");
    else if (input_file.empty())
        throw ("provided input file is empty!!!");

    std::string line;
    for (int i = 0; std::getline(inputFile, line); i++)
    {
        if (i == 0)
        {
            if (line == "date | value")
                continue;
            else
                throw ("provided input file doesn't have include the header at first line");
        }
        if (line.empty() || line.size() < 13)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        extract_FIpnut_info(line);
    }
}

void BitcoinExchange::set_DB()
{
    std::ifstream inputFile("data.csv", std::ifstream::in);
    if (!inputFile.is_open())
        throw ("could not open DB file.");

    std::string line;
    for (int i = 0; std::getline(inputFile, line); i++)
    {   
        if (i == 0)
            continue;

        unsigned int date = get_date(line);
        float exchange_rate = get_exchange_rate(line);
        DB[date] = exchange_rate;
    }
}
