# include "Fixed.hpp"
# include <cmath>

const int Fixed::fractional_bit = 8;

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
    return ( (float)fixed_point / (1 << fractional_bit));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	fixed_point = copy.fixed_point;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->fixed_point = copy.fixed_point;
    return *this;
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
