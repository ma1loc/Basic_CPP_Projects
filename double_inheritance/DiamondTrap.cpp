/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:53:45 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/30 11:08:25 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Default_clap_name"), FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap Default constructor called" << std::endl;
	name = "Default";
	hit_points = 100;
	energy_points = 50;
	attack_damage = 30;
}

DiamondTrap::DiamondTrap(const std::string &n) : ClapTrap(n + "_clap_name"), FragTrap(n), ScavTrap(n)
{
    this->name = n;
    hit_points = 100;
    energy_points = 50;
    attack_damage = 30;
    std::cout << "DiamondTrap constructor called for " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        FragTrap::operator=(copy);
        ScavTrap::operator=(copy);
        this->name = copy.name;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called for " << this->name << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->name
              << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
