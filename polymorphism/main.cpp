#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

	std::cout << "------------------ type ---------------------"
			<< std::endl;

    std::cout << "type -> "
			<< j->getType() << " " << std::endl;
    std::cout << "type -> "
			<< i->getType() << " " << std::endl;

	std::cout << "----------------- makeSound --------------------" << std::endl;
    
	i->makeSound();
    j->makeSound();
    meta->makeSound();
	
	std::cout << "-----------------------------------------------"
		<< std::endl;
	
	// here will based on the type of the pointer without the virtual word
	//		and that is done in the compilation time.
	WrongAnimal *Wrong_Animal = new WrongAnimal;
	Wrong_Animal->makeSound();
	
	WrongCat *Wrong_cat = new WrongCat;
	Wrong_cat->makeSound(); 

	std::cout << "-----------------------------------------------"
		<< std::endl;
	
	// an error of animal is not a WrongAnimal
	// Animal *Wrong_Animal_is_a_Animal = new WrongAnimal;
	// Wrong_Animal_is_a_Animal->makeSound();
	

	delete meta;
	delete j;
	delete i;
	delete Wrong_Animal;
	delete Wrong_cat;

    return 0;
}