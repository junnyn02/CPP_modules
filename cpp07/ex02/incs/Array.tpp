#include "Array.hpp"

// template class Array<typename T>

template<typename T>
Array<T>::Array(void)
{
    _array = NULL;
    _size = 0;
}

template<typename T>
Array<T>::Array(unsigned int const &n)
{
    if (n == 0)
        _array = NULL;
    else
        _array = new T[n];
    _size = n;
}

template<typename T>
Array<T>::~Array(void)
{
    if (_array != NULL)
        delete [] _array;
}

template<typename T>
Array<T>::Array(Array const &cpy)
{
    *this = cpy;
}

template<typename T>
Array<T>    &Array<T>::operator=(Array const &assign)
{
    if (this != &assign)
    {
        if (_array)
            delete [] _array;
        _size = assign.size();
        if (_size == 0)
            _array = NULL;
        else
            _array = new T[_size];
        for (unsigned int i = 0; i < size; i++)
            this->_array[i] = assign->_array[i];
    }
    return *this;
}

template<typename T>
T   &Array<T>::operator[](unsigned int const &index)
{
    if (index >= _size)
        throw ("Index is out of bounds");
    return (this->_array[index]);
}

template<typename T>
unsigned int const  &Array<T>::size(void) const
{
    return (this->_size);
}