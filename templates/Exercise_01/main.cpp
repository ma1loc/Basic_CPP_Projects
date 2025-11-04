# include <iostream>
# include "iter.hpp"

template <typename T1>
void print(T1 value)
{
    std::cout << std::fixed << value << std::endl;
}

template <typename T1>
void set_array(T1 &array, int len)
{
    
    int value = 40;
    for (int i = 0; i < len; i++)
    {
        array[i] = value;
        value += 10;
    }
}

int main()
{
    int *i_array = new int[5];
    std::string *s_array = new std::string[5];
    double *d_array = new double[5];
    float *f_array = new float[5];

    const int len = 5;

    set_array(i_array, len);
    set_array(s_array, len);
    set_array(d_array, len);
    set_array(f_array, len);

    std::cout << "iter to an int type:" << std::endl;
    iter(i_array, len, print<int>);

    std::cout << "\niter to an string type:" << std::endl;
    iter(s_array, len, print<std::string>);
    
    std::cout << "\niter to an double type:" << std::endl;
    iter(d_array, len, print<double>);

    std::cout << "\niter to an float type:" << std::endl;
    iter(f_array, len, print<float>);

    delete[] i_array;
    delete[] s_array;
    delete[] d_array;
    delete[] f_array;
}