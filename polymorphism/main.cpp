# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

// int main()
// {
//     Animal a;
//     Cat c;
//     Dog d;

//     std::cout << "type -> " << a.Get_type() << std::endl;
//     std::cout << "type -> " << c.Get_type() << std::endl;
//     std::cout << "type -> " << d.Get_type() << std::endl;

//     return (0);
// }

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    // ...
    return 0;
}
