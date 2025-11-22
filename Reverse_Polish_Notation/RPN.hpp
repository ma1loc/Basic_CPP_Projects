# ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>

class RPN
{
    private:
        std::string new_input;
        std::stack<char> stackA;
        std::stack<int> stackB;

    public:
        RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &copy);
        ~RPN();

        void    input_parsing(std::string input);
        void    set_stackA();
        void    push_stackB();
        void    operation_exec();
		int		get_stackB();

        // void    push_to_stackA(std::string new_item);
        // void    pop_from_stack();

};

std::string trim(const std::string &s);
bool isoperator(char &c);
int operation_between_two(int f_nbr, int s_nbr, char operation);


# endif