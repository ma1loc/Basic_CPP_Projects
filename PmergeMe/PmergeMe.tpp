# include "PmergeMe.hpp"
# include <stdexcept>
# include <iostream>

// template <typename T>
// PmergeMe<T>::PmergeMe() {};

// template <typename T>
// PmergeMe<T>::PmergeMe(const PmergeMe<T> &copy) {(void)copy; };

// template <typename T>
// PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe<T> &copy) {(void)copy; return (*this);};

// template <typename T>
// PmergeMe<T>::~PmergeMe() {};


// ----------------------------------------------------------

// template <typename T>
// void set_d(std::vector<int> &temp_main)  // this methode will set the 'd'
// {
//     typename T::iterator it = temp_main.begin();
//     typename T::iterator ite = temp_main.end();

//     for (; it != ite; it++)
//         T::d.push_back(*it);
//     // d.push_back(*it);
// }

// ------------------------ parsing ends here -----------------

template <typename T1, typename T2>
void set_input(T1 &input, T2 &container)
{
    typename T1::iterator it = input.begin();
    typename T1::iterator ite = input.end();

    for (size_t i = 0; it != ite; it++)
    {
        container.push_back(*it);
        i++;
    }
}

template <typename T>
void    MI_sort(T &d)
{
    int n = d.size();
    if (n <= 1)
        return ;

    T a, b;

    for (int i = 0; i < n - 1; i += 2)
    {
        if (d[i] < d[i + 1])
        {
            // here we save the index of the [i + 1] as it in the main chain befor move it
            d.[i + 1].push(a.);
            a.push_back(d.at(i + 1));
            b.push_back(d.at(i));
        }
        else
        {
            a.push_back(d.at(i));
            b.push_back(d.at(i + 1));
        }
    }
    if (n % 2)
        b.push_back(d.at(n - 1));
    MI_sort(a);
}