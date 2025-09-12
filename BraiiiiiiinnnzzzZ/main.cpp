/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:45:42 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/12 10:25:30 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main()
{    
    Zombie *new_zombie;
    
    new_zombie = newZombie("Bob");
    new_zombie->announce();
    delete new_zombie;

    randomChump("john");

    return (0);
}
