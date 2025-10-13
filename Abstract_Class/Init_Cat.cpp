/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init_Cat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:28:26 by yanflous          #+#    #+#             */
/*   Updated: 2025/10/06 11:49:51 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"
# include "Brain.hpp"

Cat::Cat() : AAnimal("Cat"), attribute(new Brain) {}

Cat::Cat(const Cat &copy) : AAnimal(copy), attribute(new Brain(*copy.attribute)) {}

Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
	{
        AAnimal::operator=(copy);

		delete this->attribute;

		this->attribute = new Brain(*copy.attribute);
	}
    return (*this);
}

Cat::~Cat()
{
	delete this->attribute;
}

void Cat::makeSound() const
{
	std::cout << "Meow"
			<< std::endl;
}
