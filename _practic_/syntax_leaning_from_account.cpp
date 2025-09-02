# include <iostream>
#include <vector>
#include "Account_copy.hpp"
# include <utility>


//  ----------------- about the std::vector ------------------- //
// int main()
// {
//     int arry[] = {11, 22, 33, 44};  // arry

//     // create from the static arry to a dynamic using the vector
//     // TODO: the number know is an object of the vector class?
// 	// TODO: typedef std::vector<int> 

//     size_t  amount;
//     typedef std::vector<int> ints_t;
//     typedef std::vector<Account::t> accounts_t;

//     accounts_t account;
//     ints_t ints;

//     ints.push_back(100);
//     std::cout << "size -------> " << ints.size() << std::endl;
//     std::cout << "size -------> " << ints.at(0) << std::endl;


//     amount = (sizeof(arry) / sizeof(arry[0]));
//     std::vector<int> numbers;

//     numbers.push_back(10);
//     std::cout << "size -------> " << numbers.size() << std::endl;

//     std::vector<int> numbers(100, 1);
//     std::vector<int> numbers(arry, arry + amount);

//     std::cout << "size -------> " << numbers.size() << std::endl;
    
//     for (size_t i = 0; i < amount; i++)
//     {
//         std::cout << "number elemant -----------> " << numbers.at(i) << std::endl;
//     }
    
    
//     for (size_t i = 0; i < amount; i++)
//     {
//         std::cout << "arry elemant -----------> " << arry[i] << std::endl;
//     }

//     numbers.push_back(55);
//     std::cout << "size -------> " << numbers.size() << std::endl;
//     amount = (sizeof(numbers.size()) / sizeof(arry[0]));
    
//     for (size_t i = 0; i < numbers.size(); i++)
//     {
//         std::cout << "number elemant -----------> " << numbers.at(i) << std::endl;
//     }
    
    
//     for (size_t i = 0; i < amount; i++)
//     {
//         std::cout << "arry elemant -----------> " << arry[i] << std::endl;
//     }
// }

// ---------------- about the std::pair ------------------------
// int main()
// {
//     // the pair is template class that take two template argument (tow object)
//     // and pair return singal object that have two in one.
//     std::pair<std::string, int> student;

//     student.first = "youness";
//     student.second = 23;


//     std::cout << student.first << std::endl;
//     std::cout << student.second << std::endl;

// }

// int main()
// {
// 	typedef std::vector<Account::t>							  accounts_t;	// an alise
// 	typedef std::vector<int>								  ints_t;		// ints_t -> alise -> std::vertor<int>
	
	
// 	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;
	
// 	// ------------------------------------------------------------------------------
// 	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
// 	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
// 	accounts_t				accounts(amounts, amounts + amounts_size);

// 	// accounts_t::iterator	acc_begin	= accounts.begin();
// 	// accounts_t::iterator	acc_end		= accounts.end();
//     // accounts.push_back(10);
//     std::cout << accounts.at(1).getNbDeposits();
// }

// ---------------- about the iterator ------------------------

int main()
{
    
}