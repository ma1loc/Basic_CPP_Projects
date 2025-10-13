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

void    Animal::setType(const std::string &type)
{
    this->type = type;
}

const std::string &Animal::getType() const
{
    return (type);
}

void	Animal::makeSound() const
{
	std::cout << "No Sound Set yet to unKnown Animal" << std::endl;
}
