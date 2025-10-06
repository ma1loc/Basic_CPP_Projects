/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init_AAnimal.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:21:27 by yanflous          #+#    #+#             */
/*   Updated: 2025/10/06 16:47:05 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "Default constractor called for AAnimal"
            << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) : type (copy.type)
{
    std::cout << "AAnimal constractor assignment called"
            << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &copy)
{
    std::cout << "AAnimal assignment operator called"
        << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return (*this);
}

AAnimal::~AAnimal()
{
    std::cout << "Destructor called for AAnimal"
            << std::endl;
}

AAnimal::AAnimal(const std::string &_type_) : type (_type_)
{
    std::cout << "AAnimal Param Constractor Called"
            << std::endl;
}

void    AAnimal::setType(const std::string &type)
{
    this->type = type;
}

const std::string &AAnimal::getType() const
{
    return (type);
}
