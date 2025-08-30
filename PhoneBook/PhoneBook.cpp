# include "PhoneBook.hpp"

// 2
// add ->  first name, last name, nickname, phone number, and
// darkest secret. A saved contact can’t have empty fields.
// next_index = (next_index + 1) % 8

class Contact
{
	// >>> attributes
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	
	public:
		// >>> methods
		std::string get_first_name() {
			return (first_name);
		}
		std::string get_last_name() {
			return (last_name);
		}
		std::string get_nickname() {
			return (nickname);
		}
		std::string get_phone_number() {
			return (phone_number);
		}
		std::string get_darkest_secret() {
			return (darkest_secret);
		}
		
		void set_first_name(std::string first_name) {
			this->first_name = first_name;
		}
		void set_last_name(std::string last_name) {
			this->last_name = last_name;
		}
		void set_nickname(std::string nickname) {
			this->nickname = nickname;
		}
		void set_phone_number(int phone_number) {
			this->phone_number = phone_number;
		}
		void set_darkest_secret(std::string darkest_secret) {
			this->darkest_secret = darkest_secret;
		}
};

class PhoneBook	// >>> collection of info.
{
	private:
		Contact contacts[CONTACTS_LIMIT];
		int	counter;
		int index;
	public:
		// add a contact
		void	add_contact();	// for ADD Command
		void	search();	// for SEARCH Command
		// TODO: contacts[] -> why i can't access to the contacts[MAX_CONTACTS] ???
	PhoneBook() {	// >>> this is the defult constractor to init the counter to 0
		std::cout << "--------------> set the index to 0" << std::endl;	
		counter = 0;
		index = 0;
	}
};


// >>> is not a global function
//		way to define the methode outside the class
//		set first the class name to define is not a global function
//		define methode outside the class be like "PhoneBook::add_contact()"
void PhoneBook::add_contact()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	int 		phone_number;
	std::string darkest_secret;

    std::cout << "----------------- ADD -----------------" << std::endl;
	std::cout << "index -> " << index << std::endl;

	std::cout << "first name: ";
	std::cin >> first_name;
	contacts[index].set_first_name(first_name);

	std::cout << "last name: ";
	std::cin >> last_name;
	contacts[index].set_last_name(last_name);

	std::cout << "nickname: ";
	std::cin >> nickname;
	contacts[index].set_nickname(nickname);
	
	std::cout << "phone number: ";
	std::cin >>  phone_number;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();
		std::cout << "error: invalid phone number" << std::endl;
		return ;
	}
	contacts[index].set_phone_number(phone_number);
	
	std::cout << "darkest secret: ";
	std::cin >> darkest_secret;
	contacts[index].set_darkest_secret(darkest_secret);

	counter++;
	index++;
}

void PhoneBook::search()
{
    std::cout << "----------------- SEARCH -----------------" << std::endl;
	
	// >>> the counter in the phonebook is to know how many contacts is there
	if (counter != 0)
	{
		std::cout << "     index|first name| last name|  nickname" << std::endl;
		
		int i = 0;
		std::cout << i << "< " << index << std::endl;
		while (i < index)	// >>> shows all the contacts is there
		{
			std::cout << i << " | " << contacts[i].get_first_name()
			<< " | " << contacts[i].get_last_name() << " | "
			<< contacts[i].get_nickname() << std::endl;
			i++;
		}
		
		// >>> shows spicefic contact with more info by index of it
		std::cout << "> Inter contact index: ";
		std::cin >> index;	// TODO: overflow to check
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
			std::cout << "error: invalid index range" << std::endl;
			return ;
		} 
		else if (index > INDEX_MAX || index < INDEX_MINI)
			std::cout << "error: input index is out of range limit" << std::endl;
		else {
			if (index <= counter - 1) {
				std::cout << "first name: " << contacts[index].get_first_name() << std::endl;
				std::cout << "last name: " << contacts[index].get_last_name() << std::endl;
				std::cout << "nickname: " << contacts[index].get_nickname() << std::endl;
				std::cout << "phone number: " << contacts[index].get_phone_number() << std::endl;
				std::cout << "darkest secret: " << contacts[index].get_darkest_secret() << std::endl;
			} else
				std::cout << "NOTE: index your looking for is not exist or not set yet" << std::endl;
		}
	}
}


int	main()
{
	std::string command;
	PhoneBook	contact_book;

	while (true)
	{
		std::cout << "> Inter the command: ";
		std::cin >> command;
		if (command == "ADD")
		{
			// TODO: Replace the new one with the old one
			contact_book.add_contact();
		}
		else if (command == "SEARCH")
			contact_book.search();
		else if (command == "EXIT")
			break ;
	}
	return (0);
}
