#include "phone_book.hpp"


// >>> is not a global function
//		way to define the methode outside the class
//		set first the class name to define is not a global function
//		define methode outside the class be like "PhoneBook::add_contact()"
void PhoneBook::add_contact()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	// if (index > CONTACTS_LIMIT - 1)
	// 	index = index % CONTACTS_LIMIT;

	std::cout << "first name: ";
	std::getline(std::cin, first_name);
	if (first_name.empty())
		return (std::cout << "error: first name is not optional to be empty" << std::endl, (void)0);

	std::cout << "last name: ";
	std::getline(std::cin, last_name);
	if (last_name.empty())
		return (std::cout << "error: last name is not optional to be empty" << std::endl, (void)0);

	std::cout << "nickname: ";
	std::getline(std::cin, nickname);
	if (nickname.empty())
		return (std::cout << "error: nickname is not optional to be empty" << std::endl, (void)0);

	std::cout << "phone number: ";
	std::getline(std::cin, phone_number);
	if (phone_number.empty())
		return (std::cout << "error: phone number is not optional to be empty" << std::endl, (void)0);
	if (is_digit(phone_number))
		return (std::cout << "error: phone number most be `all` digits" << std::endl, (void)0);

	std::cout << "darkest secret: ";
	std::getline(std::cin, darkest_secret);
	if (darkest_secret.empty())
		return (std::cout << "error: darkest secret is not optional to be empty" << std::endl, (void)0);

	// >>> setting the info contact
	contacts[index].set_first_name(first_name);
	contacts[index].set_last_name(last_name);
	contacts[index].set_nickname(nickname);
	contacts[index].set_phone_number(phone_number);
	contacts[index].set_darkest_secret(darkest_secret);

	if (counter < CONTACTS_LIMIT)
		counter++;
	index = (index + 1) % CONTACTS_LIMIT;
}

void PhoneBook::search()
{
	// >>> the counter in the phonebook is to know how many contacts is there
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

			// First name
			if (contacts[i].get_first_name().length() > WIDE)
				std::cout << contacts[i].get_first_name().substr(0, WIDE - 1) << '.' << "|";
			else
				std::cout << std::setw(WIDE) << contacts[i].get_first_name() << "|";

			// Last name
			if (contacts[i].get_last_name().length() > WIDE)
				std::cout << contacts[i].get_last_name().substr(0, WIDE - 1) << '.' << "|";
			else
				std::cout << std::setw(WIDE) << contacts[i].get_last_name() << "|";

			// Nickname
			if (contacts[i].get_nickname().length() > WIDE)
				std::cout << contacts[i].get_nickname().substr(0, WIDE - 1) << '.' << std::endl;
			else
				std::cout << std::setw(WIDE) << contacts[i].get_nickname() << std::endl;

			i++;
		}


		// >>> shows spicefic contact with more info by index of it
		std::cout << "> Inter contact index: ";
		std::getline(std::cin, in_index);
		if (in_index.empty())
			return (std::cout << "NOTE: most provide an index to see more info." << std::endl, (void)0);

		if (is_digit(in_index))
			return (std::cout << "error: index must be all digits." << std::endl, (void)0);

		contact_idx = ft_atoi(in_index);
		if (contact_idx == ERROR || contact_idx < 0 || contact_idx >= counter)
			return (std::cout << "error: invalid index out or range." << std::endl, (void)0);
		std::cout << "- first name: " << contacts[contact_idx].get_first_name() << std::endl;
		std::cout << "- last name: " << contacts[contact_idx].get_last_name() << std::endl;
		std::cout << "- nickname: " << contacts[contact_idx].get_nickname() << std::endl;
		std::cout << "- phone number: " << contacts[contact_idx].get_phone_number() << std::endl;
		std::cout << "- darkest secret: " << contacts[contact_idx].get_darkest_secret() << std::endl;
	}
	else
		std::cout << "NOTE: Phone book is empty for now." << std::endl;
}
