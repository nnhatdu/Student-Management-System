#ifndef _VECTOR_CPP_
#define _VECTOR_CPP_
#include "vector.h"

template<class T>
vector<T>::vector()
{
    Capacity = 0;
    Size = 0;
    arr = 0;
}
template<class T>
vector<T>::vector(const vector<T>& v)
{
    Size = v.Size;
    Capacity = v.Capacity;
    arr = new T[Size];
    for (unsigned int i = 0; i < Size; i++)
        arr[i] = v.arr[i];
}
template<class T>
vector<T>::vector(unsigned int size)
{
    Capacity = size;
    Size = size;
    arr = new T[size];
}
template<class T>
vector<T>::vector(unsigned int size, const T& initial)
{
    Size = size;
    Capacity = size;
    arr = new T[size];
    for (unsigned int i = 0; i < size; i++)
        arr[i] = initial;
}
template<class T>
vector<T>& vector<T>::operator = (const vector<T>& v)
{
    delete[] arr;
    Size = v.Size;
    Capacity = v.Capacity;
    arr = new T[Size];
    for (unsigned int i = 0; i < Size; i++)
        arr[i] = v.arr[i];
    return *this;
}
template<class T>
typename vector<T>::iterator vector<T>::begin()
{
    return arr;
}
template<class T>
typename vector<T>::iterator vector<T>::end()
{
    return arr + size();
}
template<class T>
T& vector<T>::front()
{
    return arr[0];
}
template<class T>
T& vector<T>::back()
{
    return arr[Size - 1];
}
template<class T>
void vector<T>::push_back(const T& v)
{
    if (Size >= Capacity)
        reserve(Capacity + 5);
    arr[Size++] = v;
}
template<class T>
void vector<T>::pop_back()
{
    Size--;
}
template<class T>
void vector<T>::reserve(unsigned int capacity)
{
    if (arr == 0)
    {
        Size = 0;
        Capacity = 0;
    }
    T* tempArr = new T[capacity];
    unsigned int l_Size = capacity < Size ? capacity : Size;
    for (unsigned int i = 0; i < l_Size; i++)
        tempArr[i] = arr[i];

    Capacity = capacity;
    delete[] arr;
    arr = tempArr;
}
template<class T>
unsigned int vector<T>::size()const
{
    return Size;
}
template<class T>
void vector<T>::resize(unsigned int size)
{
    reserve(size);
    Size = size;
}
template<class T>
T& vector<T>::operator[](unsigned int index)
{
    return arr[index];
}
template<class T>
unsigned int vector<T>::capacity()const
{
    return Capacity;
}
template<class T>
vector<T>::~vector()
{
    delete[] arr;
}
template <class T>
void vector<T>::clear()
{
    Capacity = 0;
    Size = 0;
    arr = 0;
}
template<class T>
T vector<T>::at(int index) {
    return arr[index];
}
template<class T>
void vector<T>::erase(int index) {
    for (int i = index; i < Size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    Size--;
}
template<class T>
bool vector<T>::empty() const {
    delete[] arr;
    Size = 0;
    Capacity = 0;
    arr = 0;
}
#endif