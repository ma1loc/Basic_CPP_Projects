# ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>


class Span
{
    private:
        u_int size;
        u_int capacity;
        std::vector<int> *span_data;
    public:
        Span();
        Span(u_int N);
        Span(const Span &copy);
        Span &operator=(const Span &copy);
        ~Span();

        void addNumber(int number);
        
        int shortestSpan() const;
        int longestSpan() const;

        
};

# endif