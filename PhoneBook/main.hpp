/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:36:31 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/06 16:19:22 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MAIN_HPP
# define MAIN_HPP

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
# include "Contact.hpp"
# include "PhoneBook.hpp"

int			is_digit(std::string str);
int			overflow_check(std::string index);
std::string	input(std::string output, bool info);

# endif