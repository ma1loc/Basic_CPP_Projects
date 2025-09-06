/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:36:23 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/06 16:44:13 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main()
{
	PhoneBook	contact_book;
	std::string	command;

	while (true)
	{
		command = input("> Inter the command", false);
		if (command == "ADD")
			contact_book.set_contact();
		else if (command == "SEARCH")
			contact_book.get_contact();
		else if (command == "EXIT")
			break;
	}
	return (0);
}
