/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init_Dog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:28:24 by yanflous          #+#    #+#             */
/*   Updated: 2025/10/06 11:50:04 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"
# include "Brain.hpp"

Dog::Dog() : AAnimal("Dog"), attribute(new Brain) {}

Dog::Dog(const Dog &copy) : AAnimal::AAnimal(copy), attribute(new Brain(*copy.attribute)) {}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
	{
        AAnimal::operator=(copy);

		delete this->attribute;

		this->attribute = new Brain(*copy.attribute);
	}
    return (*this);
}

Dog::~Dog()
{	
	delete this->attribute;
}

void	Dog::makeSound() const
{
	std::cout << "Bark"
			<< std::endl;
}
