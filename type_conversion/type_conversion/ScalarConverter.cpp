#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <climits>
#include <limits>
#include <string>

enum InputType {
    CHAR_TYPE,
    INT_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE,
    INVALID_TYPE
};

static InputType detectType(const std::string &input)
{
    if (input.empty())
        return INVALID_TYPE;
    
    if (input.length() == 1 && !isdigit(input[0]) && 
        input[0] != '+' && input[0] != '-' && isprint(input[0]))
        return CHAR_TYPE;
    
    if (input == "nan" || input == "+inf" || input == "-inf")
        return DOUBLE_TYPE;
    if (input == "nanf" || input == "+inff" || input == "-inff")
        return FLOAT_TYPE;
    
    size_t i = 0;
    if (input[i] == '+' || input[i] == '-')
        i++;
    
    if (!isdigit(input[i]))
        return INVALID_TYPE;
    
    bool hasDot = false;
    bool hasF = false;
    
    for (; i < input.length(); i++)
    {
        if (input[i] == '.')
        {
            if (hasDot)
                return INVALID_TYPE;
            hasDot = true;
            if (i + 1 >= input.length() || !isdigit(input[i + 1]))
                return INVALID_TYPE;
        }
        else if (input[i] == 'f')
        {
            if (i != input.length() - 1 || !hasDot)
                return INVALID_TYPE;
            hasF = true;
        }
        else if (!isdigit(input[i]))
            return INVALID_TYPE;
    }
    
    if (hasF)
        return FLOAT_TYPE;
    if (hasDot)
        return DOUBLE_TYPE;
    return INT_TYPE;
}

void ScalarConverter::convert_to_char(std::string &input)
{
    InputType type = detectType(input);
    
    if (type == CHAR_TYPE)
    {
        std::cout << "char: " << input[0] << std::endl;
        return;
    }
    
    double value = std::atof(input.c_str());
    
    if (std::isnan(value) || std::isinf(value) ||
        value < 0 || value > 127)
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    char c = static_cast<char>(value);
    if (c < 32 || c > 126)
    {
        std::cout << "char: Non displayable" << std::endl;
        return;
    }
    
    std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::convert_to_int(std::string &input)
{
    InputType type = detectType(input);
    
    if (type == CHAR_TYPE)
    {
        int value = static_cast<int>(input[0]);
        std::cout << "int: " << value << std::endl;
        return;
    }
    
    double value = std::atof(input.c_str());
    
    if (std::isnan(value) || std::isinf(value) ||
        value > INT_MAX || value < INT_MIN)
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    
    int intValue = static_cast<int>(value);
    std::cout << "int: " << intValue << std::endl;
}

void ScalarConverter::convert_to_float(std::string &input)
{
    InputType type = detectType(input);
    
    if (type == CHAR_TYPE)
    {
        float value = static_cast<float>(input[0]);
        std::cout << "float: " << value << ".0f" << std::endl;
        return;
    }
    
    float value = std::atof(input.c_str());
    std::cout << std::fixed << "float: " << value << "f" << std::endl;

}

void ScalarConverter::convert_to_double(std::string &input)
{
    InputType type = detectType(input);
    
    if (type == CHAR_TYPE)
    {
        double value = static_cast<double>(input[0]);
        std::cout << "double: " << value << ".0" << std::endl;
        return;
    }
    
    double value = std::atof(input.c_str());
    std::cout << std::fixed << "double: " << value << std::endl;
}

void ScalarConverter::convert(std::string &input)
{
    InputType type = detectType(input);
    
    if (type == INVALID_TYPE)
    {
        std::cout << "Error: Invalid input" << std::endl;
        return;
    }
    
    convert_to_char(input);
    convert_to_int(input);
    convert_to_float(input);
    convert_to_double(input);
}
