# include <iostream>
# include "Span.hpp"

int main()
{
    std::cout << "============= call addNumber five times =============" << std::endl;
    
    Span sp = Span(5);
    
    sp.addNumber(1);
    sp.addNumber(2);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(99);

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

    std::cout << "\n============= add 15000 number to second_sp =============" << std::endl;
    Span second_sp = Span(15000);
    for (int i = 1; i < 15000; i++)
        second_sp.addNumber(i);

    std::cout << "second_sp shortestSpan -> " << second_sp.shortestSpan() << std::endl;
    std::cout << "second_sp longestSpan -> " << second_sp.longestSpan() << std::endl;


    std::cout << "\n============= call addMultipleNumbers =============" << std::endl;
    
    int number_list[] = {11, 22, 33, 44, 55, 66, 77, 88, 9999};
    std::vector<int> new_list(number_list, number_list + 9); // why here +9 is not include the "9999"
    for (size_t i = 0; i < new_list.size(); i++)
    {
        std::cout << "new_list[" << i << "] -> " << new_list.at(i) << std::endl;
    }
    try
    {
        sp.addMultipleNumbers(new_list.begin(), new_list.end());
        std::cout << "one_sp shortestSpan -> " << sp.shortestSpan() << std::endl;
        std::cout << "one_sp longestSpan -> " << sp.longestSpan() << std::endl;
        // std::cout << "len -> " << sp.span_data->size() << std::endl;

        // sp.print_test();
    }
    catch (const char *e)
    {
        std::cout << "exception: " << e << std::endl;
    }

    try
    {
        std::vector<int> lol(number_list, number_list + 9);
        Span lo = Span(9);
        lo.addMultipleNumbers(lol.begin(), lol.end());
    }
    catch (const char *e)
    {
        std::cout << "exceprthtrhtion: " << e << std::endl;
    }
    

    return 0;
}
