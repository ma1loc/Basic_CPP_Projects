# include <iostream>
# include "PmergeMe.hpp"
# include "PmergeMe.tpp"
# include "_Int_.hpp"

int main(int argc, char *argv[])
{
    try
    {
        if (argc == 1)
            throw std::runtime_error("No provided args there!!!");
        
        std::vector<int> input = parsing_input(argc, argv);
        
        std::vector<_Int_> MI_vector;
        set_input(input, MI_vector);
        std::deque<_Int_> MI_deque;
        set_input(input, MI_deque);
        before_cout(input); // print_before

        // >>> start sorting
        MI_sort(MI_vector);
    
        
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
        return (1);
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
    }
    return (0);
}
