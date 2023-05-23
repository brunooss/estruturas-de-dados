#include "../include/heapsort.hpp"

template <class T>
void swap(T &a, T &b)
{
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
void heapify(Vector<T> &arr, int n, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
  {
    largest = left;
  }

  if (right < n && arr[right] > arr[largest])
  {
    largest = right;
  }

  if (largest != i)
  {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

template <typename T>
void heapSort(Vector<T> &arr)
{
  int n = arr.getSize();

  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }

  for (int i = n - 1; i > 0; i--)
  {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }

  // int i = n / 2, pai, filho, t;
  // while (true)
  // {
  //   if (i > 0)
  //   {
  //     i--;
  //     t = arr[i];
  //   }
  //   else
  //   {
  //     n--;
  //     if (n <= 0)
  //       return;
  //     t = arr[n];
  //     arr[n] = arr[0];
  //   }
  //   pai = i;
  //   filho = i * 2 + 1;
  //   while (filho < n)
  //   {
  //     if ((filho + 1 < n) && (arr[filho + 1] > arr[filho]))
  //       filho++;
  //     if (arr[filho] > t)
  //     {
  //       arr[pai] = arr[filho];
  //       pai = filho;
  //       filho = pai * 2 + 1;
  //     }
  //     else
  //     {
  //       break;
  //     }
  //   }
  //   arr[pai] = t;
  // }
}

// Explicit instantiation for int
template void heapSort(Vector<int> &arr);