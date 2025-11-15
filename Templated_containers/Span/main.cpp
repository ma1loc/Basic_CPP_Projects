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
    
    Span thread_span(12);
    int number_list[] = {0, 11, 22, 33, 44, 55, 66, 77, 88, 1};
    int sec_number_list[] = {999};
    std::vector<int> new_list(number_list, number_list + 10);
    std::vector<int> newone_list(sec_number_list, sec_number_list + 1);
    
    try
    {
        thread_span.addMultipleNumbers(new_list.begin(), new_list.end());
        thread_span.addMultipleNumbers(newone_list.begin(), newone_list.end());

        std::cout << "one_sp shortestSpan -> " << thread_span.shortestSpan() << std::endl;
        std::cout << "one_sp longestSpan -> " << thread_span.longestSpan() << std::endl;
    }
    catch (const char *e)
    {
        std::cout << "exception: " << e << std::endl;
    }
    
    std::cout << "\n============= test copy const && error's =============" << std::endl;
    try
    {
        Span copy_of_thread_span(thread_span);
        std::cout << "copy_of_thread_span shortestSpan -> " << copy_of_thread_span.shortestSpan() << std::endl;
        std::cout << "copy_of_thread_span longestSpan -> " << copy_of_thread_span.longestSpan() << std::endl;

        copy_of_thread_span.addNumber(99999);

        std::cout << "\nnew copy_of_thread_span shortestSpan -> " << copy_of_thread_span.shortestSpan() << std::endl;
        std::cout << "new copy_of_thread_span longestSpan -> " << copy_of_thread_span.longestSpan() << std::endl;

        copy_of_thread_span.addNumber(99999);
    }
    catch (const char *e)
    {
        std::cout << "exception: " << e << std::endl;
    }

    return 0;
}
