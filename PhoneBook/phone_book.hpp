/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:36:31 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/05 13:36:36 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define CONTACTS_LIMIT 8
# define WIDE 10
# define INDEX_MAX 7
# define INDEX_MINI 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define ERROR -1

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <cctype>
# include <limits>
# include <string>
# include <sstream>

int			is_digit(std::string str);
int			overflow_check(std::string index);
std::string	input(std::string output, bool info);

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:
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
