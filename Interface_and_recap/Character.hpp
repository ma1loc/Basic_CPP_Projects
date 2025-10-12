/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:35:10 by yanflous          #+#    #+#             */
/*   Updated: 2025/10/10 13:35:13 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		std::string name;
		AMateria *inventory[4];
		AMateria *Backup[4];
		int Backup_idx;
	public:
		Character();
		Character(const std::string &name);
		Character(const Character &copy);
		Character &operator=(const Character &copy);
		~Character();
		
		std::string const &getName() const;
		void	equip(AMateria *m);
		void	unequip(int idx);
		void	use(int idx, ICharacter &target);
};

#endif

