# include "Span.hpp"
# include <iostream>
# include <climits>

# define DEFAULT_CAPACITY 10

Span::Span(): size(0), capacity(DEFAULT_CAPACITY), span_data(new std::vector<int>(capacity)) {}

Span::Span(u_int N):size(0), capacity(N), span_data(new std::vector<int>(capacity)) {}

Span::Span(const Span &copy)
{
    this->size = copy.size;
    this->capacity = copy.capacity;
    this->span_data = new std::vector<int>(capacity);
    for (u_int i = 0; i < this->size; i++)
        this->span_data->at(i) = copy.span_data->at(i);
}

Span &Span::operator=(const Span &copy)
{
    if (this->span_data)
        delete span_data;
    this->size = copy.size;
    this->capacity = copy.capacity;
    span_data = new std::vector<int>(capacity);
    for (u_int i = 0; i < this->size; i++)
        this->span_data->at(i) = copy.span_data->at(i);
    return (*this);
}

Span::~Span() {delete this->span_data; }

void Span::addNumber(int number)
{
    if (size == capacity)
        throw ("capacity is full of numebrs no palces to hold the new one :(");
    this->span_data->at(this->size) = number;
    this->size++;
}

void Span::addMultipleNumbers(int_it start, int_it end)
{
    u_int len = end - start;
    u_int new_size = this->size + len;
    if (new_size > capacity)
        throw ("no space for range");
    this->span_data->insert(span_data->begin() + size, start, end);
    this->size += len;
}

u_int Span::shortestSpan() const
{
    if (size <= 1)
        throw ("no span can be found");

    std::vector<int> tmp(span_data->begin(), span_data->begin() + size);
    std::sort(tmp.begin(), tmp.end());

    u_int shortestSpan = UINT_MAX;
    for (size_t i = 0; i < tmp.size() - 1; i++)
    {
        u_int diff = tmp[i+1] - tmp[i];
        if (diff < shortestSpan)
            shortestSpan = diff;
    }
    return shortestSpan;
}

u_int Span::longestSpan() const
{
    if (size <= 1)
        throw ("no span can be found");

    std::vector<int> tmp(span_data->begin(), span_data->begin() + size);
    std::sort(tmp.begin(), tmp.end());

    return tmp.back() - tmp.front();
}
