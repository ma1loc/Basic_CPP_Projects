#include <iostream>
# include "PhoneBook.hpp"

// 1
// add ->  first name, last name, nickname, phone number, and
// darkest secret. A saved contact can’t have empty fields.
// next_index = (next_index + 1) % 8

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	
	public:
		std::string getFirstName() {
			return (first_name);
		}
		std::string getLastName() {
			return (last_name);
		}
		std::string getNickname() {
			return (nickname);
		}
		std::string getPhoneNumber() {
			return (phone_number);
		}
		std::string getDarkestSecret() {
			return (darkest_secret);
		}
		
		void setFirstName(std::string first_name) {
			this->first_name = first_name;
		}
		void setLastName(std::string last_name) {
			this->last_name = last_name;
		}
		void setNickname(std::string nickname) {
			this->nickname = nickname;
		}
		void setPhoneNumber(std::string phone_number) {
			this->phone_number = phone_number;
		}
		void setDarkestSecret(std::string darkest_secret) {
			this->darkest_secret = darkest_secret;
		}
};

class PhoneBook	// collection of info.
{
	private:
		Contact contacts[MAX_CONTACTS];
		int	counter;
	public:
		// add a contact
		void	add_contact();	// for ADD Command
		void	search();	// for SEARCH Command

};

// // the first one
// void	add_contact()
// {
// 	std::cout << "add_contact" << std::endl;
// }

// void	search()
// {
// 	std::cout << "search" << std::endl;
// }

// the last one
void PhoneBook::add_contact()
{
    std::cout << "add_contact" << std::endl;
}

void PhoneBook::search()
{
    std::cout << "search" << std::endl;
}


int	main()
{
	std::string command;
	PhoneBook	contact_book;
	
	while (true)
	{
		std::cout << ">>> Inter the command: ";
		std::cin >> command;
		if (command == "ADD")
			contact_book.add_contact();
		else if (command == "SEARCH")
			contact_book.search();
		else if (command == "EXIT")
			break ;
	}
	return (0);
}
