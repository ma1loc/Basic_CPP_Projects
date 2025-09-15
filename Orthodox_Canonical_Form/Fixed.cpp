# include "Fixed.hpp"

const int Fixed::fractional_bit = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixed_point = 0;
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
        this->fixed_point = copy.fixed_point; // copy the actual data
    return *this;                  // return the left-hand object
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
