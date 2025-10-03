# include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Defualt constractor called for Cat"
            << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Cat constractor assignment called"
        << std::endl;
}

const Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat assignment operator called"
            << std::endl;
    if (this != &copy)
        Animal::operator=(copy);
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Destructor called for Cat"
            << std::endl;
}
