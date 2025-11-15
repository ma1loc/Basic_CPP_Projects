# ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>

template <typename T>
void easyfind(T &data, int to_find)
{
    typename T::iterator it = std::find(data.begin(), data.end(), to_find);
    if (it == data.end())
        throw ("value you're looking for is not found :(");
    std::cout << *it << " exists" << std::endl;
}

# endif