#include "../include/vector.hpp"

template <typename T>
Vector<T>::Vector() : size(0), capacity(1)
{
  data = new T[capacity];
}

template <typename T>
Vector<T>::~Vector()
{
  delete[] data;
}

template <typename T>
void Vector<T>::push_back(const T &value)
{
  if (size == capacity)
  {
    capacity *= 2;
    T *newData = new T[capacity];
    for (int i = 0; i < size; i++)
    {
      newData[i] = data[i];
    }
    delete[] data;
    data = newData;
  }
  data[size] = value;
  size++;
}

template <typename T>
int Vector<T>::getSize() const
{
  return size;
}

template <typename T>
T &Vector<T>::operator[](int index)
{
  return data[index];
}

// Explicit instantiation for int
template class Vector<int>;