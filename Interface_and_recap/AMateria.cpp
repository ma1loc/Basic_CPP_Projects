/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:39:29 by yanflous          #+#    #+#             */
/*   Updated: 2025/10/10 13:39:31 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(const AMateria &copy): type(copy.type) {}

AMateria &AMateria::operator=(const AMateria &copy)
{
	(void)copy;
	return (*this);
}

AMateria::~AMateria() {}

AMateria::AMateria(std::string const &_type): type(_type) {}

std::string const &AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
