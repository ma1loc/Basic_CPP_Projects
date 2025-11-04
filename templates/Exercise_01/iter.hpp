# ifndef ITER_HPP
# define ITER_HPP

// NOTE
// that array here pased by value (*array_length)

// question about the pasing to template function(pointer to funciton) template function too?
// template <typename T1, typename T2, typename T3>
// void iter(T1 array_add, T2 array_length, T3 function)

// template <typename T1>
// void print(T1 value)

// iter(d_array, len, print<int>);

template <typename T1, typename T2, typename T3>
void iter(T1 array_add, T2 array_length, T3 function)
{
    for (int i = 0; i < array_length; i++)
    {
        function(array_add[i]);
    }
}

# endif
