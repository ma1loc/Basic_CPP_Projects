/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:34:36 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/29 10:25:52 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Constructor called" << std::endl;
	name = "Unknown";
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(const std::string &name)
{
	std::cout << "ScavTrap " << name << " Constructor called" << std::endl;
	this->name = name;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (hit_points == 0 || energy_points == 0)
	{
		if (hit_points == 0)
			std::cout << "ScavTrap " << name
					<< " cannot attack"
					<< " No 'hit points'"
					<< std::endl;
		else
			std::cout << "ScavTrap " << name
					<< " cannot attack"
					<< " No 'energy points'"
					<< std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name 
			<< " attacks " << target 
			<< ", causing " << attack_damage 
			<< " points of damage"
			<< std::endl;
	energy_points--;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode"
			<< std::endl;
}