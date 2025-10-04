# ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class 	Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &copy);
        Animal &operator=(const Animal &copy);
        // TODO: ~Animal() why not this, why we add the virtual function in the ~Animal too;
   		virtual ~Animal();
        
        Animal(const std::string &_type_);
        void    setType(const std::string &_type_);
        const std::string &getType() const;

		// TODO: this is the virtual function is done like
        virtual void makeSound() const;
};

# endif
