# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"

class PhoneBook
{
	private:
		Contact contacts[CONTACTS_LIMIT];
		int counter;
		int index;

	public:
		void set_contact();
		void get_contact();
	PhoneBook()
	{
		counter = 0;
		index = 0;
	}
};

# endif