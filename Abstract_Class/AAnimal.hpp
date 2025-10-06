# ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
	protected:
        std::string type;
    public:
        AAnimal();
        AAnimal(const AAnimal &copy);
        AAnimal &operator=(const AAnimal &copy);
		virtual ~AAnimal();
        
        AAnimal(const std::string &_type_);
        void    setType(const std::string &_type_);
        const std::string &getType() const;

        virtual void makeSound() const = 0;
};

# endif
