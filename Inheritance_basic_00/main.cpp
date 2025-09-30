/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:21:39 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/30 12:56:14 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

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

int main()
{
    std::cout << "=== ClapTrap Test ===\n";
    ClapTrap_test();

    return 0;
}
