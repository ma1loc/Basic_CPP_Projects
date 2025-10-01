/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:21:42 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/30 13:01:58 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	name = "Default";
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap::ClapTrap(const std::string &n)
{
	
	this->name = n;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;

    std::cout << "ClapTrap constructor called for "  << name
			<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	this->name = copy.name;
	this->hit_points = copy.hit_points;
	this->energy_points = copy.energy_points;
	this->attack_damage = copy.attack_damage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "assignment operator called" << std::endl;

	if (this != &copy)
	{
		this->name = copy.name;
		this->hit_points = copy.hit_points;
		this->energy_points = copy.energy_points;
		this->attack_damage = copy.attack_damage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (hit_points == 0 || energy_points == 0)
	{
		if (hit_points == 0)
			std::cout << "ClapTrap " << name
					<< " cannot attack"
					<< " No 'hit points'"
					<< std::endl;
		else
			std::cout << "ClapTrap " << name
					<< " cannot attack"
					<< " No 'energy points'"
					<< std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name 
			<< " attacks " << target 
			<< ", causing " << attack_damage 
			<< " points of damage" << std::endl;
	energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << name
			<< " takes " << amount
			<< " points of damage"
			<< std::endl;
    
    if (amount >= hit_points)
        hit_points = 0;
    else
        hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points == 0 || energy_points == 0)
	{
		std::cout << "ClapTrap " << this->name
		<< " cannot repaired "
		<< std::endl;
		return ;
	}
	int tmp_hit_point;

	tmp_hit_point = hit_points;
	hit_points += amount;
	energy_points--;
	std::cout << "ClapTrap " << this->name
			<< " Repaired Done by adding "
			<< amount << " to " << tmp_hit_point
			<< " and current energy point: "
			<< energy_points << std::endl;

}

ClapTrap::~ClapTrap()
{
	std::cout << "Deconstructor is called for "
			<< this->name << std::endl;
}