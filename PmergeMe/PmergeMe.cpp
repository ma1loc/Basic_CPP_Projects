# include "PmergeMe.hpp"
# include <iostream> // rm_me
# include <sstream>
# include <cstdlib>

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe &copy) {(void)copy; };

PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {(void)copy; return (*this);};

PmergeMe::~PmergeMe() {};

void PmergeMe::collect_args(int argc, char *argv[])
{
    std::string token;

    for (int i = 1; i < argc; i++)
    {
        token = trim(argv[i]);
        if (token.empty())
            throw std::runtime_error("Provided args is empty!!!");
        if (is_valid_number(token))
        {
            int nbr = std::atoi(token.c_str());
            tokens.push_back(nbr);
        }
        else
            throw std::runtime_error("Provided args is not valid!!!");
    }

    if (there_is_duplicate(tokens))
        throw std::runtime_error("Provided args has duplicated numbers");
}

void PmergeMe::set_lists()
{
    iter it = tokens.begin();
    iter ite = tokens.end();

    for (; it != ite; it++)
    {
        deq_list.push_back(*it);
        vec_list.push_back(*it);
    }
    this->size_of_elements = tokens.size();
}

void PmergeMe::print_list_before()
{
    iter it = tokens.begin();
    iter ite = tokens.end();

    std::cout << "Before: ";
    for (; it != ite; it++)
    {
        std::cout << *it;
        if ((it + 1) != ite)
            std::cout << " ";
        else
            std::cout << "\n";
    }
}

void PmergeMe::sort_deq_list()
{

}

void PmergeMe::sort_vec_list()
{

}