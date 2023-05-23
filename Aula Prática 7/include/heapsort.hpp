#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include "vector.hpp"

template <class T>
void swap(T &a, T &b);

template <typename T>
void heapify(Vector<T> &arr, int n, int i);

template <typename T>
void heapSort(Vector<T> &arr);

#endif // HEAPSORT_HPP