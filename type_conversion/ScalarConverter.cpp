# include "ScalarConverter.hpp"

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <cmath>
# include <cctype>
# include <climits>
#include <string>

bool is_number = false;

int input_parsing(std::string &input)
{
    long num = std::strtol(str);
    if (!input.length())
        return (std::cout << "catch enter empty!" << std::endl, 1);

    if (input.length() == 1 && isprint(input[0]) && !isspace(input[0]))
        return (is_number = false, 0);
        
    size_t i = 0;
    if (input[i] == '-' || input[i] == '+')
        i++;
    if (!isdigit(input[i]))
    {
        if (input == "nanf" ||
                input == "-inff" ||
                input == "+inff" ||
                input == "nan" ||
                input == "-inf" ||
                input == "+inf")
                return (is_number = true, 0);
        else
            return (std::cout << "catch type conversion is impossible" << std::endl, 1);
    }

    int dot_counter = 0;
    for ( ; input[i]; i++)
    {
        if (isspace(input[i]))
            return (std::cout << "catch whitespace character!" << std::endl, 1);
        else if (!isprint(input[i]))
            return (std::cout << "catch Non printable character!" << std::endl, 1);
        if (isdigit(input[i]))
        {
            if (input[i + 1] == '.' && dot_counter == 0)
            {
                dot_counter++;
                i++;
            }
            if ((input[i + 1] == 'f') && ((input.length() -1) == (i + 1)))
            {
                is_number = 1;
                break;
            }
        }
        else
            return (std::cout << "$catch type conversion is impossible" << std::endl, 1);
    }

    return (0);

}

void ScalarConverter::convert_to_char(std::string &input)
{
    std::cout << "convert_to_char -> " << is_number << std::endl;
    if (is_number)
    {
        double new_input = atof(input.c_str());
        if (std::isnan(new_input))
        {
            std::cout << "char: impossible" << std::endl;
            return ;
        }
    
        if (new_input < 32 || new_input > 126)
            std::cout << "char: Non displayable"<< std::endl;
        else
            std::cout << "char: " << static_cast<char>(new_input) << std::endl;
    }
    else
        std::cout << "char: " << static_cast<char>(input[0]) << std::endl;
}

void ScalarConverter::convert_to_int(std::string &input)
{
    std::cout << "convert_to_int -> " << is_number << std::endl;

    double int_digit = atof(input.c_str());
    if (is_number || int_digit > INT_MAX || int_digit < INT_MIN || std::isnan(int_digit))
    {
        std::cout << "int: impossible" << std::endl;
        return ;
    }


    int new_digit = static_cast<int>(int_digit);
    std::cout << std::fixed << "int: " << new_digit << std::endl;
}

void ScalarConverter::convert_to_float(std::string &input)
{
    std::cout << "convert_to_float -> " << is_number << std::endl;

    if (is_number)
    {
        std::cout << "float: impossible" << std::endl;
        return ;
    }
    float float_digit = atof(input.c_str());

    float new_digit = static_cast<float>(float_digit);

    std::cout << std::fixed << std::setprecision(1) << "float: " << new_digit << 'f' << std::endl;
}

void ScalarConverter::convert_to_double(std::string &input)
{
    std::cout << "convert_to_double -> " << is_number << std::endl;

    if (is_number)
    {
        std::cout << "double: impossible" << std::endl;
        return ;
    }
    double double_digit = atof(input.c_str());

    double new_digit = static_cast<double>(double_digit);

    std::cout << "double: " << new_digit << std::endl;

}

void ScalarConverter::convert(std::string &input)
{
    ScalarConverter::convert_to_char(input);
    ScalarConverter::convert_to_int(input);
    ScalarConverter::convert_to_float(input);
    ScalarConverter::convert_to_double(input);
}
