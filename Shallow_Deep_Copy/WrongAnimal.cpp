#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "Default constructor called for WrongAnimal"
            << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : type(copy.type)
{
    std::cout << "WrongAnimal constructor assignment called"
            << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    std::cout << "WrongAnimal assignment operator called"
            << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor called for WrongAnimal"
            << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound"
            << std::endl;
}

const std::string &WrongAnimal::getType() const
{
    return (type);
}