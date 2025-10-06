/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init_Dog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:28:24 by yanflous          #+#    #+#             */
/*   Updated: 2025/10/06 16:34:18 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"
# include "Brain.hpp"

Dog::Dog() : AAnimal("Dog")
{
    std::cout << "Defualt constractor called for Dog"
            << std::endl;
	
	attribute = new Brain();
}

Dog::Dog(const Dog &copy) : AAnimal::AAnimal(copy)
{
    std::cout << "Dog constractor assignment called"
        << std::endl;

	attribute = new Brain(*copy.attribute);
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog assignment operator called"
            << std::endl;
    if (this != &copy)
	{
        AAnimal::operator=(copy);

		delete attribute;

		attribute = new Brain(*copy.attribute);
	}
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Destructor called for Dog"
            << std::endl;
	
	delete attribute;
}

void	Dog::makeSound() const
{
	std::cout << "Bark"
			<< std::endl;
}
