#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "Default constructor called for WrongCat"
            << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    std::cout << "WrongCat constructor assignment called"
            << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    std::cout << "WrongCat assignment operator called"
            << std::endl;
    if (this != &copy)
        WrongAnimal::operator=(copy);
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "Destructor called for WrongCat"
            << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound"
            << std::endl;
}