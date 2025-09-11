/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:44:55 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/10 13:31:38 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
	this->type = str;
}

const std::string &Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(const std::string &type)
{
	this->type = type;
}