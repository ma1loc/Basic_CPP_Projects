/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init_Animal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:50:46 by yanflous          #+#    #+#             */
/*   Updated: 2025/10/06 16:18:41 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "WrongAnimal.hpp"

Animal::Animal()
{
    std::cout << "Default constractor called for Animal"
            << std::endl;
}

Animal::Animal(const Animal &copy) : type (copy.type)
{
    std::cout << "Animal constractor assignment called"
            << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
    std::cout << "Animal assignment operator called"
        << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Destructor called for animal"
            << std::endl;
}

Animal::Animal(const std::string &_type_) : type (_type_)
{
    std::cout << "Animal Param Constractor Called"
            << std::endl;
}

void    Animal::setType(const std::string &type)
{
    this->type = type;
}

const std::string &Animal::getType() const
{
    return (type);
}

void	Animal::makeSound() const
{
	std::cout << "No Sound Set yet to unKnown Animal" << std::endl;
}
