/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:45:31 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/12 10:26:47 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

void Zombie::announce()
{
    std::cout << name
            << ':' << " BraiiiiiiinnnzzzZ..."
            << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name
            <<  " is destroyed"
            << std::endl;
}
