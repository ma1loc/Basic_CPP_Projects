
// this is PmergeMe.hpp file

# ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <vector>
# include <string>
# include <algorithm>

# include <iostream> // rm_me

class PmergeMe
{
	public:
		class _Int_
		{
			private:
				int index[64];
				int pair_index;	// will this is use for what ?

			public:
				static int comparisons;	// count the compartion
				int value;				// that number value

				_Int_(int val);
				void push(int i);
				int pop();
				bool operator<(const _Int_ &obj) const;
		};
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();
};

std::vector<int> parsing_input(int argc, char *argv[]);
void before_sort(std::vector<int> &input);

# endif

// end of PmergeMe.hpp