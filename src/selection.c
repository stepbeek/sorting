#include "selection.h"

void selectionsort(int* arr, int low, int high)
{
  int i, j, idx;
  
  for (i = low; i < high; i++) {
    idx = i;
    for (j = i; j<= high; j++) {
      if (arr[j] < arr[idx]) {
	idx = j;
      }
    }
    
    if (idx != i) {
      swap(arr, i, idx);
    }
  }
}
