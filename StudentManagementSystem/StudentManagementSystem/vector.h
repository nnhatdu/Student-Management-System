#ifndef VECTOR_H
#define VECTOR_H
template <class T>
class vector
{
public:
    typedef T* iterator;
    vector();
    vector(unsigned int size);
    vector(unsigned int size, const T& initial);
    vector(const vector<T>& v);
    ~vector();
    void erase(int index);
    unsigned int capacity() const;
    unsigned int size() const;
    bool empty() const;
    iterator begin();
    iterator end();
    T& front();
    T& back();
    void push_back(const T& value);
    void pop_back();
    T at(int index);
    void reserve(unsigned int capacity);
    void resize(unsigned int size);
    T& operator[](unsigned int index);
    vector<T>& operator=(const vector<T>&);
    void clear();
private:
    unsigned int Size;
    unsigned int Capacity;
    T* arr;
};
#endif // !VECTOR_H
#include "vector.cpp"