#include <iostream>
#include <ctime>

#include "../include/vector.hpp"
#include "../include/shellsort.hpp"
#include "../include/heapsort.hpp"

using namespace std;

// Gerador de números aleatórios
Vector<int> arrayAleatorio(int size)
{
  Vector<int> arr;
  srand(static_cast<unsigned int>(time(0)));
  for (int i = 0; i < size; i++)
  {
    arr.push_back(rand() % 100); // Números aleatórios entre 0 e 99
  }
  return arr;
}

int main()
{
  const int numVectors = 15;
  const int maxSize = 100000;

  for (int i = 0; i < numVectors; i++)
  {
    int size = (i + 1) * maxSize;

    cout << "Tamanho do vetor: " << size << endl;

    double shellMedia = 0, heapMedia = 0;

    for (int j = 0; j < 10; j++)
    {

      Vector<int> arr = arrayAleatorio(size);

      cout << j + 1 << "a iteração:" << endl;

      // Medição do tempo de execução para o Shellsort

      clock_t shellStart = clock();
      shellSort(arr);
      clock_t shellEnd = clock();
      double shellSortTime = (shellEnd - shellStart) / (CLOCKS_PER_SEC / 1000.0);
      cout << "  Tempo de execução (Shellsort): " << shellSortTime << " ms" << endl;

      shellMedia += shellSortTime;

      clock_t heapStart = clock();
      heapSort(arr);
      clock_t heapEnd = clock();
      double heapSortTime = (heapEnd - heapStart) / (CLOCKS_PER_SEC / 1000.0);
      cout << "  Tempo de execução (Heapsort): " << heapSortTime << " ms" << endl;

      heapMedia += heapSortTime;

      cout << endl;
    }

    shellMedia /= 10;
    heapMedia /= 10;

    cout << "Para m = " << size << ", a média de execução para ShellSort é " << shellMedia << " ms e para HeapSort é " << heapMedia << " ms." << endl;
  }

  return 0;
}