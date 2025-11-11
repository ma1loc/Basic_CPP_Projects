# include <iostream>
# include "Span.hpp"

int main()
{
    Span sp = Span(5);

    std::cout << "============= normal test =============" << std::endl;
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "shortestSpan -> " << sp.shortestSpan() << std::endl;
    std::cout << "longestSpan -> " << sp.longestSpan() << std::endl;

    try
    {
        sp.addNumber(100);
    }    
    catch (const char *e)
    {
        std::cout << "exception: " << e << std::endl;
    }

    std::cout << "\n============= add 100 number =============" << std::endl;
    Span one_sp = Span(100);
    for (int i = 1; i < 100; i++)
        one_sp.addNumber(i);

    std::cout << "one_sp shortestSpan -> " << one_sp.shortestSpan() << std::endl;
    std::cout << "one_sp longestSpan -> " << one_sp.longestSpan() << std::endl;



    return 0;
}
