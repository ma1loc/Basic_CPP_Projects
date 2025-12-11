# include "PmergeMe.hpp"
# include <stdexcept>
# include <iostream>
# include <cmath>

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
void	set_pairs(T &d, T &a, T &b, int n)
{
	for (int i = 0; i < n - 1; i += 2)
    {
        if (d.at(i) < d.at(i + 1))
        {
            d.at(i + 1).push(a.size());

			a.push_back(d.at(i + 1));
            b.push_back(d.at(i));
        }
        else
        {
			d.at(i).push(a.size());

			a.push_back(d.at(i));
            b.push_back(d.at(i + 1));
        }
	}
	if (n % 2)
		b.push_back(d.at(n - 1));
}

template <typename T>
T	set_rB(T &a, T &b)
{
	T rB;
	int loser_index;
	int a_size = a.size();

    for(int i = 0; i < a_size; i++)
    {
        loser_index = a.at(i).pop();
        rB.push_back(b.at(loser_index));
    }

	if (b.size() > a.size())
		rB.push_back(b.back());
	return (rB);
}

template <typename T>
void	number_insertion(T &d, T &a, T&rB)
{
	int a_idx = 0;
	int rB_size = rB.size();
	int k = 2;
	int tk_ = 0;

	while (a_idx < (int)a.size())
	{
		int tk = ((pow(2, k + 1) + pow(-1, k)) / 3) - 1;
		int m = std::min(tk, rB_size - 1);

		for ( ; a_idx <= m && a_idx < (int)a.size(); a_idx++)
			d.push_back(a.at(a_idx));

		for (int i = m; i > tk_; i--)
		{
			typename T::iterator it = std::lower_bound(d.begin(), d.end(), rB.at(i));
			d.insert(it, rB.at(i));
		}
		tk_ = tk;
		k++;

		if (tk_ >= rB_size && a_idx >= (int)a.size())
			break ;
	}

	while (tk_ + 1 < rB_size)
	{
		tk_++;
		typename T::iterator it = std::lower_bound(d.begin(), d.end(), rB[tk_]);
		d.insert(it, rB[tk_]);
	}
}

template <typename T>
void    MI_sort(T &d)
{    
	int n = d.size();
	if (n <= 1)
		return ;
	
	T a, b;
	set_pairs(d, a, b, n);

	MI_sort(a);

	T rB = set_rB(a, b);

	d.clear();
	d.push_back(rB.at(0));

	number_insertion(d, a, rB);
}


template <typename T>
void after_sort(const T& container)
{
	typename T::const_iterator it = container.begin();
    typename T::const_iterator ite = container.end();
	
    std::cout << "After: ";
    for (; it != ite; ++it)
    {
        std::cout << it->value;
        if ((it + 1) != ite) 
            std::cout << " ";
        else
            std::cout << "\n";
    }
}
