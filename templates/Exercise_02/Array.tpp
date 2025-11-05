# include "Array.hpp"
# define MAX_VAL 750
# include <iostream>

template <typename T>
Array<T>::Array(): array_size(1)
{
    this->data = new T[array_size];
}

template <typename T>
Array<T>::Array(unsigned int n): array_size(n)
{
    std::cout << "param constractor -> " << array_size << std::endl;
    this->data = new T[array_size];
}

template <typename T>
Array<T>::Array(const Array<T> &copy)
{
    this->array_size = copy.array_size;
    this->data = new T[this->array_size];
    for (int i = 0; i < this->array_size; i++)
        this->data[i] = copy.data[i];
}

template <typename T>
T &Array<T>::operator=(const Array<T> &copy)
{
    std::cout << "enter operator=" << std::endl;
    if (this != &copy)
    {
        std::cout << "inter this != &copy" << std::endl;
        if (this->data)
        {
            for (int i = 0; i < copy.array_size; i++)
                delete this->data[i];
        }
        for (int i = 0; i < this->array_size; i++)
            this->data[i] = copy.data[i];
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](int index)
{
    if (index < 0 || index > MAX_VAL)
        throw ("index provided is out of range");
    return (this->data[index]);
}

template <typename T>
Array<T>::~Array()
{
    delete[] data;  
}

template <typename T>
T Array<T>::size()
{
    return (this->array_size);
}
