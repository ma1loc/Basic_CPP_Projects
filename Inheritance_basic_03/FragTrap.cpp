/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:23:22 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/29 18:17:09 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap Default Constructor called" << std::endl;
	name = "Default";
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(const std::string &n)
{
	this->name = n;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap " << name << " Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	ClapTrap::operator=(copy);
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &copy)
        ClapTrap::operator=(copy);
    return (*this);
}

void FragTrap::highFivesGuys()
{
	std::cout << name << " request a high fives" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}