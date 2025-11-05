# ifndef ARRAY_HPP
# define ARRAY_HPP

// template <typename T>
// NOTE
// ------------- class template ----------------
// is the class template a genaric class that mean's that class works with any type?
// what is the explicite instantiation mean's ?
// overloading function template
// Array(const T &copy); // why not like this?
// T &operator=(const T &copy); // why not like this?
// if function class done by overwrrinding a fucniotn with correct type  under the hold what about the templete class ????

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
        T &operator=(const Array<T> &copy);
        T &operator[](int index);
        ~Array();

        T size();
};

# endif
