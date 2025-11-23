# ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>
# include <vector>

class RPN
{
    private:
        std::vector<char> v_input;
        std::stack<int> stackA;
    public:
        RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &copy);
        ~RPN();

        void    input_parsing(std::string &input);
        void    exec_operation(std::string argv);
        long     get_stackA();
};

std::string trim(const std::string &s);
bool        isoperator(char &c);
int         operation_between_two(int f_nbr, int s_nbr, char operation);

# endif

