/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:11:45 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/09 17:11:47 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main()
{
    int     N;
    Zombie  *horde;
    
    N = 1;
    horde = zombieHorde(N, "Zombie");
    for (int i = 0; i < N; i++)
        horde[i].announce();
    
    delete[] horde;

    return (0);
}