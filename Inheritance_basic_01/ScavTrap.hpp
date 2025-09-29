/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:34:32 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/29 09:00:22 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{		
	public:
		ScavTrap();
		ScavTrap(const std::string &name);
		~ScavTrap();

		void attack(const std::string& target);
		void guardGate();
};
