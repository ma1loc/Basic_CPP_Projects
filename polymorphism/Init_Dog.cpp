# include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Defualt constractor called for Dog"
            << std::endl;
}

Dog::Dog(const Dog &copy) : Animal::Animal(copy)
{
    std::cout << "Dog constractor assignment called"
        << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog assignment operator called"
            << std::endl;
    if (this != &copy)
        Animal::operator=(copy);
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Destructor called for Dog"
            << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Bark"
			<< std::endl;
}
