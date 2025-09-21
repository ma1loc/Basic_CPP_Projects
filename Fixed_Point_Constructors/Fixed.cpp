/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:23:07 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/21 13:38:34 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <cmath>

const int Fixed::fractional_bit = 8;

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->fixed_point = copy.fixed_point;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixed_point = 0;
}

Fixed::Fixed(const int int_nbr)
{
    std::cout << "Int constructor called" << std::endl;
    fixed_point = int_nbr << fractional_bit;
}

Fixed::Fixed(const float float_nbr)
{
    std::cout << "Float constructor called" << std::endl;
    fixed_point = roundf(float_nbr * (1 << fractional_bit));
}

int Fixed::toInt( void ) const
{
	return (fixed_point >> fractional_bit);
}

float Fixed::toFloat( void ) const
{
    return ((float)fixed_point / (1 << fractional_bit));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	fixed_point = copy.fixed_point;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	fixed_point = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
