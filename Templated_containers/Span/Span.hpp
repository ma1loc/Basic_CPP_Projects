# ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>

typedef std::vector<int>::iterator int_it;

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

        u_int shortestSpan() const;
        u_int longestSpan() const;

        void addMultipleNumbers(int_it start, int_it end);
};

# endif
