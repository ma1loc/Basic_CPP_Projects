#include "phone_book.hpp"

// 3
// add ->  first name, last name, nickname, phone number, and
// darkest secret. A saved contact can’t have empty fields.
// next_index = (next_index + 1) % 8

int main()
{
	PhoneBook	contact_book;
	std::string	command;

	while (true)
	{
		std::cout << "> Inter the command: ";
		std::getline(std::cin, command);
		if (command == "ADD")
			contact_book.add_contact();
		else if (command == "SEARCH")
			contact_book.search();
		else if (command == "EXIT")
			break;
	}
	return (0);
}
