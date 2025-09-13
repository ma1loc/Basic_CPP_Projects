/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:12:43 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/13 18:18:32 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

void	Harl::complain ( std::string level)
{
	int i;
	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"};
	
	void	(Harl::*methodes[])() = {      
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
		{
			(this->*methodes[i])();
			break ;
		}
		i++;
	}
}

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my "\
	"7XL-double-cheese-triple-pickle-special-ketchup "\
	"burger." << std::endl;
}

void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon "\
	"costs more money." << std::endl;
}

void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon"\
	" for free." << std::endl;
}

void	Harl::error()
{
	std::cout << "This is unacceptable! I want to speak"\
	" to the manager now." << std::endl;
}
