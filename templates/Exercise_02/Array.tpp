# include "Array.hpp"
# include <iostream>

template <typename T>
Array<T>::Array(): array_size(1)
{
    this->data = new T[array_size];
}

template <typename T>
Array<T>::Array(unsigned int n): array_size(n)
{
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
Array<T> &Array<T>::operator=(const Array<T> &copy)
{
    if (this != &copy)
    {
        if (this->data)
            delete[] this->data;
        this->data = new T[copy.array_size];
        this->array_size = copy.array_size;
        for (int i = 0; i < this->array_size; i++)
            this->data[i] = copy.data[i];
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](int index)
{
    if (index < 0 || index >= this->array_size)
        throw std::out_of_range("index out of range");
    return this->data[index];
}


template <typename T>
Array<T>::~Array()
{
    delete[] data;  
}

template <typename T>
int Array<T>::size() const
{
    return (this->array_size);
}