/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:38:47 by yanflous          #+#    #+#             */
/*   Updated: 2025/10/10 13:38:48 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <string>
class ICharacter;

class AMateria
{
	protected:
		 const std::string type;
	public:

		AMateria(std::string const &type);
		
		AMateria();
		AMateria(const AMateria &copy);
		AMateria &operator=(const AMateria &copy);
		virtual ~AMateria();
		
		std::string const &getType() const;

		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter& target);
};

# endif

