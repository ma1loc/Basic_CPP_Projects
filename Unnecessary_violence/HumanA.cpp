/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:44:47 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/13 15:07:07 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
: name(name), weapon(weapon) {}

void HumanA::attack()
{
	std::cout << name
			<< " attacks with their "
			<< weapon.getType()
			<< std::endl;
}
