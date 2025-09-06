/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book_utils.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:36:12 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/06 16:42:02 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"


int overflow_check(std::string index)
{
	int i;
	int sign;
	long result;

	i = 0;
	sign = 1;
	result = 0;
	while (index[i])
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
		if (std::isdigit(phone_number[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

bool	is_non_print(std::string input)
{
	int i;

	i = 0;
	while (input[i])
	{
	    if (!std::isprint(static_cast<unsigned char>(input[i])))
		{
	        std::cout << "NOTE: Non-printable is not valid as an input" << std::endl;
			return (true);
    	}
		i++;
	}
	return (false);
}

std::string	input(std::string output, bool info)
{
	std::string	input;

	std::cout << output << ": ";
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << "\nEOF" << std::endl;
		exit(0);
	}
	if (info && input.empty())
	std::cout << "error: " 
			<< output << " is not optional to be empty"
			<< std::endl;
	if (is_non_print(input))
		input = "";
	return (input);
}
