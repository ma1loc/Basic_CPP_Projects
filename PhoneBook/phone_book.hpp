# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define CONTACTS_LIMIT 8
# define WIDE 10
# define INDEX_MAX 7
# define INDEX_MINI 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define ERROR 404

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <cctype>
# include <limits>
# include <string>
# include <sstream>

int	is_digit(std::string str);
int	ft_atoi(std::string index);

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

class PhoneBook // >>> collection of info.
{
	private:
		Contact contacts[CONTACTS_LIMIT];
		int counter;
		int index;

	public:
		void add_contact(); // for ADD Command
		void search();		// for SEARCH Command
		// TODO: contacts[] -> why i can't access to the contacts[MAX_CONTACTS] ???
	PhoneBook()
	{ // >>> this is the defult constractor to init the counter to 0
		counter = 0;
		index = 0;
	}
};

# endif
