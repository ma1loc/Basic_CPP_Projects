# include "Animal.hpp"
# include "WrongAnimal.hpp"

Animal::Animal()
{
    std::cout << "Defualt constractor called for Animal"
            << std::endl;
}

Animal::Animal(const Animal &copy) : type (copy.type)
{
    std::cout << "Animal constractor assignment called"
            << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
    std::cout << "Animal assignment operator called"
        << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Destructor called for animal"
            << std::endl;
}

Animal::Animal(const std::string &_type_) : type (_type_)
{
    std::cout << "Animal Param Constractor Called"
            << std::endl;
}

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
