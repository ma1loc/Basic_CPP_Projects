# ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <vector>
# include <string>
# include <algorithm>

class PmergeMe
{
	public:
		class _Int_
		{
			private:
				int index[64];
				int pair_index;

			public:
				static int comparisons;
				int value;

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
