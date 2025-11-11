# include "Span.hpp"
# include <iostream>
# include <algorithm>

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

Span::~Span() {delete this->span_data;}

void Span::addNumber(int number)
{
    if (size == capacity)
        throw ("capacity is full of numebrs no palces to hold the new one :(");
    this->span_data->at(this->size) = number;
    this->size++;
}

int Span::shortestSpan() const
{
    if (size <= 1)
        throw ("no span can be found");
    
    std::vector<int> tmp = *this->span_data;
    std::sort(tmp.begin(), tmp.end(), std::greater<int>());
    
    int shortestSpan = __INT_MAX__;
    int diffrence;
    
    for (u_int i = 0; i < this->size; i++)
    {
        if ((i + 1) == size)
            break;
        diffrence = tmp.at(i) - tmp.at(i + 1);
        if (shortestSpan > diffrence)
            shortestSpan = diffrence;
    }
    return (shortestSpan);
}

int Span::longestSpan() const
{
    if (size <= 1)
        throw ("no span can be found");
    
    std::vector<int> tmp = *this->span_data;
    std::sort(tmp.begin(), tmp.end());
    return (tmp.at(size - 1) - tmp.at(0));
}