/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 09:41:56 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/12 09:42:06 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int		get_level(const std::string &level)
{
	int	i;

	i = 0;
	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	while (i < 4)
	{
		if (levels[i] == level)
			return (i);
		i++;
	}
	return (-1);
}

void	Harl::complain(std::string level)
{
	int level_flag;

	level_flag = get_level(level);
	if (level_flag == -1)
		return (std::cout << "[ Probably complaining"\
			" about insignificant problems ]" << std::endl, (void)0);
	switch (level_flag)
	{
	case DEBUG:
		std::cout << "[ DEBUG ]" << std::endl;
		Harl::debug();
		std::cout << "\n[ INFO ]" << std::endl;
		Harl::info();
		std::cout << "\n[ WARNING ]" << std::endl;
		Harl::warning();
		std::cout << "\n[ ERROR ]" << std::endl;
		Harl::error();
		std::cout << "\n";
		break;
	case INFO:
		std::cout << "[ INFO ]" << std::endl;
		Harl::info();
		std::cout << "\n[ WARNING ]" << std::endl;
		Harl::warning();
		std::cout << "\n[ ERROR ]" << std::endl;
		Harl::error();
		std::cout << "\n";
		break;
	case WARNING:
		std::cout << "[ WARNING ]" << std::endl;
		Harl::warning();
		std::cout << "\n[ ERROR ]" << std::endl;
		Harl::error();
		std::cout << "\n";
		break;
	case ERROR:
		std::cout << "[ ERROR ]" << std::endl;
		Harl::error();
		std::cout << "\n";
		break;
	default:
		break;
	}
}

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my"\
			" 7XL-double-cheese-triple-pickle-special"\
			"-ketchup burger\n"
			"I really do!"
			<< std::endl;
}

void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon "\
			"costs more money.\n"
			"You didn’t put enough bacon in my burger!"
			" If you did, I wouldn’t be asking for more!"
			<< std::endl;
}

void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free.\n"
		"I’ve been coming for years whereas you started working here"
		" since last month."
		<< std::endl;
}

void	Harl::error()
{
	std::cout << "This is unacceptable! I want to speak"\
	" to the manager now." << std::endl;
}
