
# include "Array.hpp"
# include "Array.tpp"
# include <iostream>
# include <cstdlib>


int main()
{
    srand(time(NULL));

    Array<int> number(5);
    
    int i = 0;
    for (; i < 5; i++)
    {
        const int value = rand();
        number[i] = value;
    }
    std::cout << "size -> " << number.size() << std::endl;
    i = 0;
    for (; i < 5; i++)
        std::cout << "number " << i << "-> " << number[i] << std::endl;


    Array<int> tmp = number;
    
    return (0);
}