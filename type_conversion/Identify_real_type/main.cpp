# include <iostream>
# include <cstdlib>
# include "Base.hpp"
# include "Class_a.hpp"
# include "Class_b.hpp"
# include "Class_c.hpp"

enum
{
    _A,
    _B,
    _C
};

Base * generate(void)
{
    int random_i = rand() % 3;
    // std::cout << "i ----------> " << random_i << std::endl; 

    switch (random_i)
    {
        case _A:
            std::cout << "catch the _A\n"; 
            return (new A);
            break;
        case _B:
            std::cout << "catch the _B\n"; 
            return (new B);
            break;
        case _C:
            std::cout << "catch the _C\n"; 
            return (new C);
            break;
        default: return (NULL);
    }
    return (NULL);
}

void identify(Base *p)
{
    // >>> down_casting
    std::cout << "type of the object pointed to by p: ";
    if (dynamic_cast<A *>(p))
        std::cout << "\"A\"" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "\"B\"" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "\"C\"" << std::endl;
}

void identify(Base &p)
{
    std::cout << "type of the object referenced by p: ";
    try {
        Base &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "\"A\"" << std::endl;
    }
    catch (std::exception &e){}

    try 
    {
        Base &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "\"B\"" << std::endl;
    }
    catch (std::exception &e){}

    try 
    {
        Base &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "\"C\"" << std::endl;
    }
    catch (std::exception &e){}
}

int main()
{
    srand(time(NULL));

    Base *random_object;

    random_object = generate();
    identify(random_object);
    identify(*random_object);

    
    delete random_object;

    return (0);
}