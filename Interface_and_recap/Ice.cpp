/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:39:11 by yanflous          #+#    #+#             */
/*   Updated: 2025/10/11 11:45:45 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"
# include <iostream>

Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice &copy): AMateria(copy) {}

Ice &Ice::operator=(const Ice &copy)
{
	if (this != &copy)
		AMateria::operator=(copy);
	return (*this);
}

Ice::~Ice() {}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName()
			<< " *" << std::endl;
}
