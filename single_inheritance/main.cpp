/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:21:39 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/30 13:04:27 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"


void ClapTrap_test()
{
    ClapTrap alice("Alice");
    ClapTrap bob("Bob");

    std::cout << "\n-- Basic Attacks --\n";
    alice.attack("Bob");
    bob.takeDamage(0);

    std::cout << "\n-- Damage & Repair --\n";
    alice.takeDamage(3);
    alice.beRepaired(2);

    std::cout << "\n-- Multiple Attacks --\n";
    for (int i = 1; i <= 5; i++)
        alice.attack("Unknown");

    ClapTrap charlie = alice;
    ClapTrap dave("Dave");
    dave = bob;

    dave.attack("Unknown");
}

void ScavTrap_test()
{
    ScavTrap alice("Alice");
    ScavTrap bob("Bob");

    alice.attack("Bob");
    bob.takeDamage(10);
    alice.beRepaired(5);

    std::cout << "\n-- Guard Gate Test --\n";
    alice.guardGate();
}

int main()
{
    // std::cout << "=== ClapTrap Test ===\n";
    // ClapTrap_test();

    std::cout << "\n=== ScavTrap Test ===\n";
    ScavTrap_test();

    return 0;
}
