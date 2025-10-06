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

Cat::Cat() : Animal("Cat")
{
    std::cout << "Defualt constractor called for Cat"
            << std::endl;
	
	attribute = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Cat constractor assignment called"
        << std::endl;

	attribute = new Brain(*copy.attribute);
}

Cat &Cat::operator=(const Cat &copy)
{
	
    std::cout << "Cat assignment operator called"
            << std::endl;
    if (this != &copy)
	{
        Animal::operator=(copy);

		delete attribute;

		attribute = new Brain(*copy.attribute);
	}
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Destructor called for Cat"
            << std::endl;

	delete attribute;
}

void Cat::makeSound() const
{
	std::cout << "Meow"
			<< std::endl;
}
