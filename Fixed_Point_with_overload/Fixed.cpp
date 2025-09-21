/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 09:33:07 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/22 09:37:27 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractional_bit = 8;

Fixed::Fixed()
{
	fixed_point = 0;
}

Fixed::Fixed(const int int_nbr)
{
	fixed_point = (int_nbr << fractional_bit);
}

Fixed::Fixed(const float float_nbr)
{
	fixed_point = (roundf(float_nbr * (1 << fractional_bit)));
}

Fixed::Fixed(const Fixed &copy) : fixed_point(copy.fixed_point)
{
}

Fixed::~Fixed() {}

float Fixed::toFloat(void) const
{
    return (float)fixed_point / (1 << fractional_bit);
}

int Fixed::toInt(void) const
{
    return fixed_point >> fractional_bit;
}

int Fixed::getRawBits(void) const
{
    return fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    fixed_point = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    if (this != &copy)
        this->fixed_point = copy.fixed_point;
    return *this;
}

bool Fixed::operator>(const Fixed &copy) const
{
    return (this->fixed_point > copy.fixed_point);
}

bool Fixed::operator<(const Fixed &copy) const
{
    return (this->fixed_point < copy.fixed_point);
}

bool Fixed::operator>=(const Fixed &copy) const
{
    return (this->fixed_point >= copy.fixed_point);
}

bool Fixed::operator<=(const Fixed &copy) const
{
    return (this->fixed_point <= copy.fixed_point);
}

bool Fixed::operator==(const Fixed &copy) const
{
    return (this->fixed_point == copy.fixed_point);
}

bool Fixed::operator!=(const Fixed &copy) const
{
    return (this->fixed_point != copy.fixed_point);
}

Fixed Fixed::operator+(const Fixed &copy) const
{
    Fixed result;
    result.fixed_point = this->fixed_point + copy.fixed_point;
    return (result);
}

Fixed Fixed::operator-(const Fixed &copy) const
{
    Fixed result;
    result.fixed_point = this->fixed_point - copy.fixed_point;
    return (result);
}

Fixed Fixed::operator*(const Fixed &copy) const
{
    Fixed result;
    int tmp;
    
    tmp = this->fixed_point * copy.fixed_point;
    result.fixed_point = tmp >> fractional_bit;
    return (result);
}

Fixed Fixed::operator/(const Fixed &copy) const
{
    Fixed result;
    int tmp;

    tmp = (this->fixed_point << fractional_bit) / copy.fixed_point;
    result.fixed_point = tmp;
    return (result);
}

// >>> pre-increment/decrement
Fixed &Fixed::operator++()
{
    ++fixed_point;
    return (*this);
}

Fixed &Fixed::operator--()
{
    --fixed_point;
    return (*this);
}

// >>> post-increment/decrement
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);

	fixed_point++;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    fixed_point--;
    return (tmp);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
    if (f1 < f2)
        return (f1);
    return (f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
    if (f1 < f2)
        return (f1);
    return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
    if (f1 > f2)
        return (f1);
    return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
    if (f1 > f2)
        return (f1);
    return (f2);
}