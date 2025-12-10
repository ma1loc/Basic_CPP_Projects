
// this is the PmergeMe.cpp file

# include "PmergeMe.hpp"
# include <sstream>
# include <iostream>
# include <algorithm>

int PmergeMe::_Int_::comparisons = 0;

// why not like this?
// PmergeMe::_Int_::_Int_(int val): value(val), idx_p(0) {};

PmergeMe::_Int_::_Int_(int val): value(val)
{
	pair_index = 0;
}

void PmergeMe::_Int_::push(int i)
{
	index[pair_index] = i;
	pair_index++;
}

int PmergeMe::_Int_::pop() {
	pair_index--;
	return (index[pair_index]);
}

bool PmergeMe::_Int_::operator<(const _Int_ &obj) const
{
	comparisons++;
	return (this->value < obj.value);
}

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &copy){(void)copy;}
PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {(void)copy; return (*this); }
PmergeMe::~PmergeMe() {}

std::string trim(const std::string &s)
{
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end   = s.find_last_not_of(" \t\n\r");
    if (start == std::string::npos)
        return "";
    return s.substr(start, end - start + 1);
}

bool    there_is_duplicate(std::vector<int> temp_main)
{
    std::vector<int>::iterator it = temp_main.begin();
    std::vector<int>::iterator ite = temp_main.end();

    std::sort(it, ite);

    for (; it != ite; it++)
    {
        if ((it + 1) != ite)
        {
            if (*it == *(it+1))
                return (true);
        }
        else
            break;
    }
    return (false);
}

bool    is_valid_number(std::string token)
{
    int number = 0;
    std::istringstream sst(token);
    sst >> number;

    if (sst.fail() || !sst.eof() || number < 0)
        return (false);
    return (true);
}

std::vector<int> parsing_input(int argc, char *argv[])
{
    std::string token;
    std::vector<int> temp_main;

    for (int i = 1; i < argc; i++)
    {
        std::string token = trim(argv[i]).c_str();
        if (token.empty())
            throw std::runtime_error("Provided args is empty!!!");
        if (is_valid_number(token))
        {
            int nbr = std::atoi(token.c_str());
            temp_main.push_back(nbr);
        }
        else
            throw std::runtime_error("Provided args is not valid!!!");
    }

    if (there_is_duplicate(temp_main))
        throw std::runtime_error("Provided args has duplicated numbers");
    return (temp_main);
}

void before_sort(std::vector<int> &input)
{
    std::vector<int>::iterator it = input.begin();
    std::vector<int>::iterator ite = input.end();

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

// end of PmergeMe.cpp
