# include "PmergeMe.hpp"
# include <iostream>

int main(int argc, char *argv[])
{
    try
    {
        if (argc == 1)
            throw std::runtime_error("No provided args there!!!");
        
        PmergeMe sort;
        sort.collect_args(argc, argv);
        sort.set_lists();
        sort.print_list_before();


    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
        return (1);
    }

    return (0);
}
