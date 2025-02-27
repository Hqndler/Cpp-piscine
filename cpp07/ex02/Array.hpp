#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array{

    private:
        size_t s;
        T *array;

        class IndexOutOfRangeException: public std::exception{
            public:
                virtual const char *what() const throw(){
                    return "Array exception : Array index out of range.";
                }
        };

    public:
        Array(void);
        Array(size_t size);
        Array(const Array<T> &a);
        ~Array(void);

        Array<T> &operator=(const Array<T> &a);
        T & operator[](size_t index) const;

        size_t size(void) const;
};

template<typename T>
Array<T>::Array(void) : s(0){
    array = new T[0];
}

template<typename T>
Array<T>::Array(size_t size) : s(size){
    array = new T[size];
    for(size_t i = 0; i < size; ++i)
        array[i] = T();
}

template<typename T>
size_t Array<T>::size(void) const{
    return this->s;
}

template<typename T>
Array<T>::~Array(void){
    delete [] array;
}

template<typename T>
T &Array<T>::operator[](size_t index) const{
    if (index >= s)
        throw(IndexOutOfRangeException());
    return array[index];
}

template<typename T>
Array<T>::Array(const Array<T> &a) : s(a.size()) {
    array = new T[s];
    for (size_t i = 0; i < s; ++i)
        array[i] = a.array[i];
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &a){
    if (array)
        delete [] array;
    array = new T[a.size()];
    for (size_t i = 0; i < a.size(); ++i)
        array[i] = a[i];
}

template<typename T>
std::ostream &operator<<(std::ostream &o, const Array<T> &a){
    o << "[";
    for(size_t i = 0; i < a.size(); ++i){
        o << a[i];
        if (i < (a.size() - 1))
            o << ", ";
    }
    o << "]";
    return o;
}

#endif