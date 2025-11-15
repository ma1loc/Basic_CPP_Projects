# include "easyfind.hpp"
# include <iostream>
# include <vector>

int main()
{
    int array_of_nbr[] = {6, 20, 7, 48, 16, 37, 14, 38, 23, 43};
    std::vector<int> data(array_of_nbr, array_of_nbr + 10);

    std::cout << "\n=============== vector behaver in size ===============" << std::endl;

    std::cout << "the data.capacity before -> " << data.capacity() << std::endl;
    std::cout << "the data.size before -> " << data.size() << std::endl;
    
    data.push_back(50);
    
    std::cout << "the data.capacity after -> " << data.capacity() << std::endl;
    std::cout << "the data.size after -> " << data.size() << std::endl;

    std::cout << "\n=============== values are available ===============" << std::endl;
    for (size_t i = 0; i < data.size(); i++)
        std::cout << "value at index[" << i << "] -> " << data.at(i) << std::endl;

    
    try
    {
        std::cout << "\n================ first easyfind ===============" << std::endl;
        easyfind(data, 20);
        easyfind(data, 7);
        easyfind(data, 38);
        easyfind(data, 6);
        easyfind(data, 40);
    }
    catch (const char *e)
    {
        std::cout << "exception: " << e << std::endl;
    }

    try
    {
        std::cout << "\n================ seconsd easyfind ===============" << std::endl;
        easyfind(data, 6);
        easyfind(data, 7);
        easyfind(data, 20);
        easyfind(data, 38);
        data.push_back(40);
        easyfind(data, 40);
        data.pop_back();
    }
    catch(const char *e)
    {
        std::cout << "exception: " << e  << std::endl;
    }

    std::cout << "=============== values are available ===============" << std::endl;
    for (size_t i = 0; i < data.size(); i++)
        std::cout <<  "value at index[" << i << "] -> " << data.at(i) << std::endl;
    
    try
    {
        std::cout << "=============== remove last element and index to it ===============" << std::endl;
        std::cout <<  "data.front() -> " << data.front() << std::endl;
        std::cout <<  "data.back() -> " << data.back() << std::endl;
        data.erase(data.begin());
        std::cout  << "\nfront value -> " << data.front()  << std::endl;
        data.erase(--data.end());
        std::cout  << "back value -> " << data.back()  << std::endl;
        
        std::cout << data.at(9) << std::endl;
        // std::cout << "value -> " << data[55] << std::endl;
    }
    catch(std::out_of_range &e)
    {
        std::cerr << "exveption: " << e.what() << '\n';
    }
    data.clear();
    std::cout << "\nthe data.capacity after clear -> " << data.capacity() << std::endl;
    std::cout << "the data.size after clear -> " << data.size() << std::endl;
}
