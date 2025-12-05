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
    bool odd_list = false;
    unsigned int odd_num = 0;
    std::deque<int>main;
    std::deque<int>pend;

    if (size_of_elements > 1)
    {
        if (size_of_elements % 2 != 0)
        {
            odd_list = true;
            odd_num = deq_list.at(size_of_elements - 1);
            deq_list.erase(deq_list.begin() + (size_of_elements - 1));
        }
        set_main_and_pend_pairs(tokens, main, pend);
        if (odd_list)
            pend.push_back(odd_num);
        sort_main_pair(main);
        
        // rm_me
        for (size_t i = 0; i < main.size(); i++)
            std::cout << main.at(i) << " ";
        //
    }
    else
        throw ("Your providing just one number that's alrady sorted");
}

template <typename T1, typename T2>
void    set_main_and_pend_pairs(T1 tokens, T2 &main, T2 &pend)
{
    typename T1::iterator it = tokens.begin();
    typename T1::iterator ite = tokens.end();
    if (it != ite && tokens.size() > 1)
    {
        main.push_back(std::max(*it, *(it + 1)));
        pend.push_back(std::min(*it, *(it + 1)));
    }
    else
        return ;
    tokens.erase(it, it + 2);
    set_main_and_pend_pairs(tokens, main, pend);
}

template <typename T>
T PmergeMe<T>::MergeInsertion(T d)
{
    std::vector<int> min = sort_main_pair(d);
    for (size_t i = 0; i < min.size(); i++)
        std::cout << min.at(i) << " ";
    
    return (d);
}

template <typename T>
bool    there_is_duplicate(T tokens)
{
    typename T::iterator it = tokens.begin();
    typename T::iterator ite = tokens.end();

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
