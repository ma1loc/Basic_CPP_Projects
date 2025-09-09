/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:46:03 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/09 14:46:05 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie *new_zombie = new Zombie(name);
    return (new_zombie);
}
