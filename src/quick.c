#include "quick.h"

void quicksort(int* arr, int low, int high)
{
  
  int idx = low + (high - low)/2;
  int piv = arr[idx];

  int i = low;
  int j = high;

  while (i <= j) {
    while (arr[i] < piv && i <= high) {
      i++;
    }

    while (arr[j] > piv && j >= low) {
      j--;
    }

    if (i <= j) {
      swap(arr, i, j);
      i++;
      j--;
    }
  }

  if (j > low) {
    quicksort(arr, low, j);
  }

  if (i < high) {
    quicksort(arr, i, high);
  }
}
