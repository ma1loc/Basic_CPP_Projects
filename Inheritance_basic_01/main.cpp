/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:21:39 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/29 09:37:43 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

int main()
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

	std::cout << "===================================================" << std::endl;
	
	ScavTrap b1;
	ScavTrap b2;

	b1.attack("b2");
	b2.takeDamage(10);
	b1.beRepaired(5);
	
	for (int i = 1; i <= 50; i++)
	{
		std::cout << "attack number -> " << i << ": ";
		b1.attack("unkown");
	}


	b1.guardGate();
	
	std::cout << "===================================================" << std::endl;
    
    return 0;
}
