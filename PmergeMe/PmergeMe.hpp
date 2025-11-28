# ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <vector>
# include <string>

// >>>>>>>>> NOTE <<<<<<<<<<<
// --> ex00 std::map used <<<
// --> ex01 std::vector used <<<
// --> ex01 std::stack used <<<

// if there's just one number and if alrady sored just show them

// accepte just positive number
// will use [merge-insert sort algorithm]
// merge-insert sort algorithm
// merge sort, insertion sort, and binary search using the Jacobsthal sequence
// number duplication not valid

// Because the exercise is not only about sorting, but also about understanding:
// How different containers behave
// Their iterator types
// Their memory layout (contiguous vs. blocks)
// Their performance differences for insertions, random access, etc.

// Sequence Containers: vector, list, deque, array
// Associative Containers: set, map, multiset, multimap
// Container Adapters: stack, queue, priority_queue

typedef std::vector<int>::iterator iter;


class PmergeMe
{
    private:
        std::vector<int> tokens;
        std::deque<unsigned int> deq_list;
        std::vector<unsigned int> vec_list;
        int size_of_elements;
        
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);
        ~PmergeMe();

        void    collect_args(int argc, char *argv[]);
        void    set_lists();
        void    print_list_before();
        void    print_list_after();
        void    sort_deq_list();
        void    sort_vec_list();

};

std::string     trim(const std::string &s);
bool    is_valid_number(std::string token);
bool    there_is_duplicate(std::vector<int> vec_list);


# endif