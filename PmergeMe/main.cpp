# include <iostream>
# include <sys/time.h>
# include "PmergeMe.hpp"
# include "PmergeMe.tpp"

int main(int argc, char *argv[])
{
    try
    {
        if (argc == 1)
            throw std::runtime_error("No provided args there!!!");
		
        std::vector<int> input = parsing_input(argc, argv);
        
        std::vector<PmergeMe::_Int_> MI_vector;
        set_input(input, MI_vector);
       
		std::deque<PmergeMe::_Int_> MI_deque;
        set_input(input, MI_deque);

        before_sort(input);

        struct timeval tv, tv2;
        gettimeofday(&tv, NULL);
        MI_sort(MI_vector);
        gettimeofday(&tv2, NULL);
        long time_us = ((long)tv2.tv_sec * 1000000 + tv2.tv_usec) - ((long)tv.tv_sec * 1000000 + tv.tv_usec);
        after_sort(MI_vector);
        std::cout << "Time to process a range of " << input.size() << " elements with std::vector : " << time_us << " us." << std::endl;

        gettimeofday(&tv, NULL);
        MI_sort(MI_deque);
        gettimeofday(&tv2, NULL);
        time_us = ((long)tv2.tv_sec * 1000000 + tv2.tv_usec) - ((long)tv.tv_sec * 1000000 + tv.tv_usec);
        std::cout << "Time to process a range of " << input.size() << " elements with std::deque : " << time_us << " us." << std::endl;
        
        
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
