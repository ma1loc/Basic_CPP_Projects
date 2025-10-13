/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init_Animal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:50:46 by yanflous          #+#    #+#             */
/*   Updated: 2025/10/06 11:50:48 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "WrongAnimal.hpp"

Animal::Animal() {}

Animal::Animal(const Animal &copy) : type (copy.type) {}

Animal &Animal::operator=(const Animal &copy)
{
    if (this != &copy)
        this->type = copy.type;
    return (*this);
}

Animal::~Animal() {}

Animal::Animal(const std::string &_type_) : type (_type_) {}

void    Animal::setType(const std::string &_type_)
{
    this->type = _type_;
}

const std::string &Animal::getType() const
{
    return (type);
}

void	Animal::makeSound() const
{
	std::cout << "No Sound Set yet to unKnown Animal" << std::endl;
}
