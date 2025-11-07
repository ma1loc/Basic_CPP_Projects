# ifndef ITER_HPP
# define ITER_HPP

template <typename T1, typename T2, typename T3>
void iter(T1 array_add, T2 array_length, T3 function)
{
    for (int i = 0; i < array_length; i++)
    {
        function(array_add[i]);
    }
}

# endif
