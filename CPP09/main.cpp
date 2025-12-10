
// this is the main.cpp file

# include <iostream>
# include "PmergeMe.hpp"
# include "PmergeMe.tpp"

int main(int argc, char *argv[])
{
    try
    {
        if (argc == 1)
            throw std::runtime_error("No provided args there!!!");
        
		PmergeMe MI_sorting;
		
        std::vector<int> input = parsing_input(argc, argv);
        
        std::vector<PmergeMe::_Int_> MI_vector;
        set_input(input, MI_vector);
       
		// >>>> deque <<<< //
		std::deque<PmergeMe::_Int_> MI_deque;
        set_input(input, MI_deque);

        before_sort(input);

		// time count will start from here (will do it lattr on)

        // >>> start sorting vector
        MI_sort(MI_vector); // just call it to test

		// >>> start sorting deque
        // MI_sort(MI_deque); // just call it to test


		after_sort(MI_vector);
        
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

// end of the main file
