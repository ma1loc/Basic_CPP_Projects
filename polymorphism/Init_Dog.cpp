# include "Dog.hpp"

Dog::Dog() : Animal("Dog") {}

Dog::Dog(const Dog &copy) : Animal::Animal(copy) {}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
        Animal::operator=(copy);
    return (*this);
}

Dog::~Dog() {}

void	Dog::makeSound() const
{
	std::cout << "Bark"
			<< std::endl;
}
