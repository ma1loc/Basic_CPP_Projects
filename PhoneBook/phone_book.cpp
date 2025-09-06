/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:36:23 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/05 13:36:26 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

int main()
{
	PhoneBook	contact_book;
	std::string	command;

	while (true)
	{
		command = input("> Inter the command", false);
		if (std::cin.eof())
		{
			std::cout << "\nEOF" << std::endl;
			break;
		}
		else if (command == "ADD")
			contact_book.set_contact();
		else if (command == "SEARCH")
			contact_book.get_contact();
		else if (command == "EXIT")
			break;
	}
	return (0);
}
