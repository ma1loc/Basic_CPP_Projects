/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:34:36 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/30 10:20:43 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	name = "Default";
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(const std::string &n)
{
	this->name = n;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &copy)
        ClapTrap::operator=(copy);
    return (*this);
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