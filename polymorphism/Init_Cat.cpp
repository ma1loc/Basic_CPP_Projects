# include "Cat.hpp"
# include "WrongCat.hpp"

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

Cat &Cat::operator=(const Cat &copy)
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

// >>> Meow
void Cat::makeSound() const
{
	std::cout << "Meow"
			<< std::endl;
}

// void WrongCat::makeSound()
// {
// 	std::cout << "WrongCat sound"
// 			<< std::endl;
// }