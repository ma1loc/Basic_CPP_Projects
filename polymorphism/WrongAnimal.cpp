#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : type(copy.type) {}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    if (this != &copy)
        this->type = copy.type;
    return (*this);
}

WrongAnimal::~WrongAnimal() {}

void WrongAnimal::makeSound() const {}

const std::string &WrongAnimal::getType() const
{
    return (type);
}