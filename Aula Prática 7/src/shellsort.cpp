#include "../include/shellsort.hpp"

template <typename T>
void shellSort(Vector<T> &arr)
{
  int h = 1;
  int i, j;
  int rep = 0;
  int tamanho = arr.getSize();

  while (h < tamanho)
  {
    h = h * 2;
  }

  while (h > 1)
  {
    h /= 2;

    for (i = h; i < tamanho; i++)
    {
      T aux = arr[i];
      j = i;

      while (j >= h && aux < arr[j - h])
      {
        arr[j] = arr[j - h];
        j -= h;
        rep++;
      }

      arr[j] = aux;
    }
  }
}

// Explicit instantiation for int
template void shellSort(Vector<int> &arr);