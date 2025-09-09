/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:11:50 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/09 17:11:52 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

void Zombie::announce()
{
	std::cout << this->name
			<< ':' << " BraiiiiiiinnnzzzZ..."
			<< std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}
