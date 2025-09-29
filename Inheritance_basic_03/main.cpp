/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:21:39 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/29 17:58:43 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "DiamondTrap.hpp"

void	ClapTrap_test()
{
	ClapTrap alice("Alice");
	ClapTrap bob("Bob");

	std::cout << "\n";
    
	alice.attack("Bob");
    bob.takeDamage(0);

	std::cout << "\n";
    
    alice.takeDamage(3);
    alice.beRepaired(2);

	std::cout << "\n";

	for (int i = 1; i <= 10; i++)
	{
		std::cout << "attack number -> " << i << ": ";
		alice.attack("unkown");
	}

	std::cout << "\n";
    
    for (int i = 1; i <= 10; i++)
	{
        std::cout << "attack number -> " << i << ": ";
        bob.attack("unknown");
    }

	std::cout << "\n";
    
    bob.attack("unkonwn");
    bob.beRepaired(5);

	std::cout << "\n";

    alice.takeDamage(15);
    alice.attack("unknown");
    alice.beRepaired(5);

	std::cout << "\n";
    
    ClapTrap charlie = alice;
    ClapTrap dave("Dave");
    dave = bob;

	std::cout << "\n";

	dave.attack("Unkonwn");	
}

void	ScavTrap_test()
{
	ScavTrap alice;
	ScavTrap bob;

	alice.attack("b2");
	bob.takeDamage(10);
	alice.beRepaired(5);
	
	for (int i = 1; i <= 50; i++)
	{
		std::cout << "attack number -> " << i << ": ";
		alice.attack("unkown");
	}

	alice.guardGate();
}

void	FragTrap_test()
{
	FragTrap alice;
	FragTrap bob;


	alice.attack("b2");
	bob.takeDamage(10);
	alice.beRepaired(5);
	
	for (int i = 1; i <= 100; i++)
	{
		std::cout << "attack number -> " << i << ": ";
		alice.attack("unkown");
	}

	alice.highFivesGuys();

	return ;
}


int main()
{
	// ClapTrap_test();
	// ScavTrap_test();
	// FragTrap_test();
	
	DiamondTrap test1;
	
	test1.whoAmI();
	test1.attack("Unknown");

	return (0);
}