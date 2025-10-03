
# ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{
    public:
        Cat();
        Cat(const Cat &copy);
        const Cat &operator=(const Cat &copy);
        ~Cat();
};

# endif
