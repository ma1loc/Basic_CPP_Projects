/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:35:14 by yanflous          #+#    #+#             */
/*   Updated: 2025/10/10 13:35:20 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"
# include <iostream>

Cure::Cure(): AMateria("cure") {}

Cure::Cure(const Cure &copy) : AMateria(copy) {}

Cure &Cure::operator=(const Cure &copy)
{
	if (this != &copy)
		AMateria::operator=(copy);
	return (*this);
}

Cure::~Cure() {}	

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName()
			<< "’s wounds *"
			<< std::endl;
}

