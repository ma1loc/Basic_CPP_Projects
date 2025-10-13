# include "Cat.hpp"
# include "WrongCat.hpp"

Cat::Cat() : Animal("Cat") {}

Cat::Cat(const Cat &copy) : Animal(copy) {}

Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
        Animal::operator=(copy);
    return (*this);
}

Cat::~Cat() {}

void Cat::makeSound() const
{
	std::cout << "Meow"
			<< std::endl;
}
