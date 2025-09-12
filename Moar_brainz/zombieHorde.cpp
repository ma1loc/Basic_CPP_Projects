/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:11:57 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/12 10:43:08 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *horde;
    
    horde = new Zombie[N];
    for (int i = 0; i < N; i++)
        horde[i].set_name(name);
    return (horde);
}
