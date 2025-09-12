/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:46:15 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/12 10:31:10 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class   Zombie
{
    public:
        void announce( void );
        Zombie(std::string name);
        ~Zombie();
    private:
        std::string name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

# endif
