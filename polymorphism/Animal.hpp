# ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &copy);
        Animal &operator=(const Animal &copy);
        ~Animal();
        
        Animal(const std::string &_type_);
        void    setType(const std::string &_type_);
        const std::string &getType() const;

        void makeSound() const; // is that the virtual function?
};

# endif
