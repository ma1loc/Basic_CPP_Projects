# include "PhoneBook.hpp"

// 3
// add ->  first name, last name, nickname, phone number, and
// darkest secret. A saved contact can’t have empty fields.
// next_index = (next_index + 1) % 8

int	ft_atoi(std::string index)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (index[i] && ((index[i] == ' ') || (index[i] >= 9 && index[i] <= 13)))
		i++;
	if (index[i] == '+' || index[i] == '-')
		return (ERROR);
	while (index[i] && index[i] >= '0' && index[i] <= '9')
	{
		result = result * 10 + (index[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && -result < INT_MIN))
			return (ERROR);
		i++;
	}
	return (result * sign);
}

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
		void set_phone_number(std::string phone_number) {
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
		counter = 0;
		index = 0;
	}
};

int	is_digit(std::string phone_number)
{
	int i;

	i = 0;
	while (phone_number[i])
	{
		if (isdigit(phone_number[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

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

	if (index > CONTACTS_LIMIT - 1)
		index = index % CONTACTS_LIMIT;

	std::cout << "first name: ";
	std::getline(std::cin, first_name);
	if (first_name.empty())
		return (std::cout << "error: first name is not optional to be empty" << std::endl, (void)0);
	contacts[index].set_first_name(first_name);

	std::cout << "last name: ";
	std::getline(std::cin, last_name);
	if (last_name.empty())
		return (std::cout << "error: last name is not optional to be empty" << std::endl, (void)0);
	contacts[index].set_last_name(last_name);

	std::cout << "nickname: ";
	std::getline(std::cin, nickname);
	if (nickname.empty())
		return (std::cout << "error: nickname is not optional to be empty" << std::endl, (void)0);
	contacts[index].set_nickname(nickname);

	
	std::cout << "phone number: ";
	std::getline(std::cin, phone_number);
	if (phone_number.empty())
		return (std::cout << "error: phone number is not optional to be empty" << std::endl, (void)0);
	if (is_digit(phone_number))
		return (std::cout << "error: phone number most be `all` digits" << std::endl, (void)0);
	contacts[index].set_phone_number(phone_number);
	
	std::cout << "darkest secret: ";
	std::getline(std::cin, darkest_secret);
	contacts[index].set_darkest_secret(darkest_secret);

	counter++;
	index++;
}

void PhoneBook::search()
{
	// >>> the counter in the phonebook is to know how many contacts is there
	if (counter != 0)
	{
		int 		i;
		std::string in_index;
		int			contact;

		i = 0;
		std::cout << "     index|first name| last name|  nickname" << std::endl;
		while (i < counter)	// >>> shows all the contacts is there
		{
			std::cout << std::setw(10) << i << "|";
			if (contacts[i].get_first_name().length() > WIDE)
				std::cout << contacts[i].get_first_name().substr(0, 9) << '.' << "|";
			else
				std::cout << std::setw(10) << contacts[i].get_first_name() << "|";
			
			if (contacts[i].get_first_name().length() > WIDE)
				std::cout << contacts[i].get_last_name().substr(0, 9) << '.' << "|";
			else
				std::cout << std::setw(10) << contacts[i].get_last_name() << "|";
		
			if (contacts[i].get_nickname().length() > WIDE)
				std::cout << contacts[i].get_nickname().substr(0, 9) << '.' << std::endl;
			else
				std::cout << std::setw(10) << contacts[i].get_nickname() << std::endl;
			i++;
		}

		// >>> shows spicefic contact with more info by index of it

		std::cout << "> Inter contact index: ";
		std::getline(std::cin, in_index);
		if (in_index.empty())
			return (std::cout << "NOTE: most provide an index to see more info." << std::endl, (void)0);
		
		if (is_digit(in_index))
			return (std::cout << "error: index must be all digits." << std::endl, (void)0);
		
		contact = ft_atoi(in_index);
		if (contact == ERROR || contact > INDEX_MAX || contact < INDEX_MINI)
			return (std::cout << "error: invalid index out or range." << std::endl, (void)0);
		
		if (contact <= counter - 1) {
			std::cout << "- first name: " << contacts[contact].get_first_name() << std::endl;
			std::cout << "- last name: " << contacts[contact].get_last_name() << std::endl;
			std::cout << "- nickname: " << contacts[contact].get_nickname() << std::endl;
			std::cout << "- phone number: " << contacts[contact].get_phone_number() << std::endl;
			std::cout << "- darkest secret: " << contacts[contact].get_darkest_secret() << std::endl;
		} else
			std::cout << "NOTE: index your looking for is not exist or not set yet." << std::endl;
	}
	else
		std::cout << "NOTE: Phone book is empty for now." << std::endl;
}

int	main()
{
	std::string command;
	PhoneBook	contact_book;

	while (true)
	{
		std::cout << "> Inter the command: ";
		std::getline(std::cin, command);
		if (command == "ADD")
			contact_book.add_contact();
		else if (command == "SEARCH")
			contact_book.search();
		else if (command == "EXIT")
			break ;
	}
	return (0);
}
