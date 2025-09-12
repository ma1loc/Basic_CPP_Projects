/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:11:45 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/12 10:48:44 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main()
{
    int     N;
    Zombie  *horde;
    
    N = 10;
    horde = zombieHorde(N, "Youness");
    for (int i = 0; i < N; i++)
        horde[i].announce();
    
    delete[] horde;

    return (0);
}
