/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_definition.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:36:21 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/05 13:43:15 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

void PhoneBook::set_contact()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	first_name = input("first name", true);
	if (first_name.empty())
		return ;

	last_name = input("last name", true);
	if (last_name.empty())
		return ;

	nickname = input("nickname", true);
	if (nickname.empty())
		return ;

	phone_number = input("phone number", true);
	if (phone_number.empty())
		return ;
	if (is_digit(phone_number))
		return (std::cout << "error: phone number"\
			" most be `all` digits" << std::endl, (void)0);

	darkest_secret = input("darkest secret", true);
	if (darkest_secret.empty())
		return ;

	contacts[index].set_first_name(first_name);
	contacts[index].set_last_name(last_name);
	contacts[index].set_nickname(nickname);
	contacts[index].set_phone_number(phone_number);
	contacts[index].set_darkest_secret(darkest_secret);

	if (counter < CONTACTS_LIMIT)
		counter++;
	index = (index + 1) % CONTACTS_LIMIT;
}

void PhoneBook::get_contact()
{
	if (counter != 0)
	{
		int			i;
		std::string in_index;
		int 		contact_idx;

		i = 0;
		std::cout << std::setw(WIDE) << "index" << "|"
        	<< std::setw(WIDE) << "first name" << "|"
			<< std::setw(WIDE) << "last name" << "|"
        	<< std::setw(WIDE) << "nickname" << std::endl;
		while (i < counter)
		{
			std::cout << std::setw(WIDE) << i << "|";
			if (contacts[i].get_first_name().length() > WIDE)
				std::cout << contacts[i].get_first_name().substr(0, WIDE - 1) << '.' << "|";
			else
				std::cout << std::setw(WIDE) << contacts[i].get_first_name() << "|";

			if (contacts[i].get_last_name().length() > WIDE)
				std::cout << contacts[i].get_last_name().substr(0, WIDE - 1) << '.' << "|";
			else
				std::cout << std::setw(WIDE) << contacts[i].get_last_name() << "|";

			if (contacts[i].get_nickname().length() > WIDE)
				std::cout << contacts[i].get_nickname().substr(0, WIDE - 1) << '.' << std::endl;
			else
				std::cout << std::setw(WIDE) << contacts[i].get_nickname() << std::endl;
			i++;
		}


		std::cout << "> Inter contact index: ";
		std::getline(std::cin, in_index);
		if (in_index.empty())
			return (std::cout << "NOTE: most provide"\
				" an index to see more info." << std::endl, (void)0);

		if (is_digit(in_index))
			return (std::cout << "error: index must"\
				" be all digits." << std::endl, (void)0);

		contact_idx = overflow_check(in_index);
		if (contact_idx == ERROR || contact_idx < 0 || contact_idx >= counter)
			return (std::cout << "error: invalid index"\
				" out or range." << std::endl, (void)0);
		std::cout << "- first name: " << 
			contacts[contact_idx].get_first_name() << std::endl;
		std::cout << "- last name: "
			<< contacts[contact_idx].get_last_name() << std::endl;
		std::cout << "- nickname: "
			<< contacts[contact_idx].get_nickname() << std::endl;
		std::cout << "- phone number: "
			<< contacts[contact_idx].get_phone_number() << std::endl;
		std::cout << "- darkest secret: "
			<< contacts[contact_idx].get_darkest_secret() << std::endl;
	}
	else
		std::cout << "NOTE: Phone book is empty for now." << std::endl;
}
