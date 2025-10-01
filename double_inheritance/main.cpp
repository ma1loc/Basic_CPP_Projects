/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:21:39 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/30 11:28:43 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "DiamondTrap.hpp"

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

void FragTrap_test()
{
    FragTrap alice("Alice");
    FragTrap bob("Bob");

    alice.attack("Bob");
    bob.takeDamage(10);
    alice.beRepaired(5);

    std::cout << "\n-- High Fives Test --\n";
    alice.highFivesGuys();
}

void DiamondTrap_tests()
{
    std::cout << "=== DiamondTrap Virtual Inheritance Test ===" << std::endl;

    DiamondTrap d1("Diamond1");
    DiamondTrap d2("Diamond2");

    std::cout << "\n-- whoAmI Test --" << std::endl;
    d1.whoAmI();

    std::cout << "\n-- Attack Test --" << std::endl;
    d1.attack("Target");

    std::cout << "\n-- Copy Constructor Test --" << std::endl;
    DiamondTrap d3(d1);
    d3.whoAmI();

    std::cout << "\n-- Copy Assignment Test --" << std::endl;
    d2 = d1;
    d2.whoAmI();
}

int main()
{
    // std::cout << "=== ClapTrap Test ===\n";
    // ClapTrap_test();

    // std::cout << "\n=== ScavTrap Test ===\n";
    // ScavTrap_test();

    // std::cout << "\n=== FragTrap Test ===\n";
    // FragTrap_test();

    std::cout << "\n=== DiamondTrap Test ===\n";
    DiamondTrap_tests();

    return 0;
}
