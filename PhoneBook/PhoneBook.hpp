/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 09:42:25 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/07 09:53:11 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define CONTACTS_LIMIT 8
# include "Contact.hpp"

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