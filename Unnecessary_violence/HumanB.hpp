/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:44:51 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/10 13:57:11 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string str);	// done
		void	attack();	// >>> done
		void	setWeapon(Weapon &weapon);
	private:
		std::string	name;		// >>> done
		Weapon		*weapon;		// why weapon not &weapon?
};

# endif