/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:44:52 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/10 13:30:18 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
    public:
        Weapon(std::string type);
        const std::string &getType() const;
        void setType(const std::string &type);
    private:
	    std::string type;
      
};

# endif
