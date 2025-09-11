/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:44:47 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/10 14:03:50 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"

// HumanA(std::string str, Weapon weapon);	// done

// HumanA::HumanA(std::string name, Weapon &weapon)	// done
// {
// 	this->name = name;
// 	this->weapon = weapon;
// }

HumanA::HumanA(std::string name, Weapon &weapon)
: name(name), weapon(weapon) {}


void HumanA::attack()
{
	std::cout << name
			<< " attacks with their "
			<< weapon.getType()
			<< std::endl;
}
