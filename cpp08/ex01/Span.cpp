#include "Span.hpp"

Span::Span(void) : size(0){
    return;
}

Span::Span(const size_t size) : size(size){
    return;
}

Span::~Span(void){
    return;
}

Span::Span(const Span &s) : size(s.size), vect(s.vect){
    return;
}

Span &Span::operator=(const Span &s){
    if (this->size < s.size)
        throw(SpanOutOfRangeException());
    this->vect = s.vect;
    return *this;
}

void Span::add_number(int nb){
    if (vect.size() > size)
        throw(SpanFullException());
    vect.push_back(nb);
}

void Span::add_range(std::vector<int> v){
    if (vect.size() + v.size() > size)
        throw(SpanOutOfRangeException());
    vect.insert(vect.end(), v.begin(), v.end());
}

size_t Span::shortest_span(void){
    if (vect.size() < 2){
        if (vect.size() == 0)
            throw(SpanEmptyException());
        throw(SpanNotEnoughValueException());
    }

    std::vector<int> tmp = vect;
    std::sort(tmp.begin(), tmp.end());

    size_t min = -1;
    for (size_t i = 0; i < tmp.size() - 1; ++i)
        min = std::min(min, static_cast<size_t>(tmp[i + 1] - tmp[i]));
    return min;
}

size_t Span::longest_span(void){
    if (vect.size() < 2){
        if (vect.size() == 0)
            throw(SpanEmptyException());
        throw(SpanNotEnoughValueException());
    }

    int min = *std::min_element(vect.begin(), vect.end());
    int max = *std::max_element(vect.begin(), vect.end());
    return (static_cast<size_t>(max - min));
}