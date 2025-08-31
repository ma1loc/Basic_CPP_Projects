#include "phone_book.hpp"

int ft_atoi(std::string index)
{
	int i;
	int sign;
	long result;

	i = 0;
	sign = 1;
	result = 0;
	while (index[i] && ((index[i] == ' ') || (index[i] >= 9 && index[i] <= 13)))
		i++;
	if (index[i] == '+' || index[i] == '-')
		return (ERROR);
	while (index[i] && index[i] >= '0' && index[i] <= '9')
	{
		result = result * 10 + (index[i] - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1 && -result < INT_MIN))
			return (ERROR);
		i++;
	}
	return (result * sign);
}

int is_digit(std::string phone_number)
{
	int i;

	i = 0;
	while (phone_number[i])
	{
		if (isdigit(phone_number[i]))
			i++;
		else
			return (1);
	}
	return (0);
}