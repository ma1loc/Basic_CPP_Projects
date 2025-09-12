/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:11:53 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/12 10:44:22 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

class Zombie
{
    public:
        void announce( void );
        void set_name(std::string name);
    private:
        std::string name;
};

Zombie* zombieHorde( int N, std::string name );
