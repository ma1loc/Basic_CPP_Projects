# ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
private:
    T *data;
    int array_size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array<T> &copy);
    Array<T> &operator=(const Array<T> &copy);
    T &operator[](int index);
    ~Array();

    int size() const;
};

void    Array_with_string();
void    Array_with_numbers();

# endif
