#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    if (this != &copy)
        WrongAnimal::operator=(copy);
    return (*this);
}

WrongCat::~WrongCat() {}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound"
            << std::endl;
}