# include "MutantStack.hpp"
# include "MutantStack.tpp"
# include <iostream>
# include <vector>
# include <stack>
# include <list>

// >>> std::stack use LIFO
void MutantStack_test()
{
    MutantStack<int> mstack;

    mstack.push(1);
    mstack.push(2);

    std::cout << "top -> " << mstack.top() << std::endl;
    
    std::cout << "size before pop -> " <<mstack.size() << std::endl;

    mstack.pop();
    std::cout << "pop" << std::endl;
    
    std::cout << "size after pop -> " <<mstack.size() << std::endl;

    std::cout << "top -> " << mstack.top() << std::endl;
    
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);
    mstack.push(6);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;

    for (; it != ite; it++)
    {
        std::cout << "it -> " <<  *it << std::endl;
        *it = 0;
    }

    std::cout << "============== test cbegin and cend ============== " << std::endl;
    
    MutantStack<int>::const_iterator cit = mstack.cbegin();
    MutantStack<int>::const_iterator cite = mstack.cend();
    for (; cit != cite; cit++)
    {
        std::cout << "cit -> " <<  *cit << std::endl;
        // *cit = 1; 
    }

    // >>> set new value
    it = mstack.begin();
    for (int i = 1; it != ite; it++)
    {
        *it = i;
        i++;
    }

    std::cout << "============== test rbegin / rend ============== " << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    for ( ; rit != rite; rit++)
    {
        std::cout << "rit -> " <<  *rit << std::endl;
    }
}

void list_test()
{
    std::list<int> mstack;

    mstack.push_back(1);
    mstack.push_back(2);

    std::cout << "top -> " << mstack.back() << std::endl;
    
    mstack.pop_back();
    std::cout << "pop_bakc" << std::endl;

    
    std::cout << mstack.size() << std::endl;    
    
    mstack.push_back(3);
    mstack.push_back(4);
    mstack.push_back(5);
    mstack.push_back(6);

    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::list<int> s(mstack);
}

// >>> just more tests
void string_test()
{
    std::string name;
    typedef std::string::iterator iter;
    
    name = "youness";
    iter it = name.begin();
    iter ite = name.end();

    std::cout << "name -> " << *it << std::endl;
    ++it;
    std::cout << "name -> " << *it << std::endl;
    ++it;
    for (; it != ite; ++it)
    {
        std::cout << "name -> " << *it << std::endl;
    }
}

void stack_test_with_vector()
{
    std::stack<int, std::list<int> > mstack;

    mstack.push(1);
    mstack.push(2);

    std::cout << "top -> " << mstack.top() << std::endl;
    
    mstack.pop();
    std::cout << "pop" << std::endl;

    
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);
    mstack.push(6);

    for (; mstack.size() > 0;)
    {
        int top = mstack.top();
        std::cout << "top -> " << top << std::endl;
        mstack.pop();
    }
}



int main()
{
    std::cout << "================= call MutantStack_test =================" << std::endl;
    MutantStack_test();

    std::cout << "\n================= call list_test =================" << std::endl;
    list_test();

    std::cout << "\n================= call string_test =================" << std::endl;
    string_test();

    std::cout << "\n================= call stack_test_with_vector =================" << std::endl;
    stack_test_with_vector();
}