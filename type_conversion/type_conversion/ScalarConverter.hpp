# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
	private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &copy);
        ~ScalarConverter();

        static void convert_to_char(std::string &input);
        static void convert_to_int(std::string &input);
        static void convert_to_float(std::string &input);
        static void convert_to_double(std::string &input);
    public:
        static void convert(std::string &input);
};

int input_parsing(std::string &input);

# endif