#include "insertion.h"

void insertionsort(int* arr, int low, int high)
{
  int i, j;

  for(i = low + 1; i <= high; i++) {
    for(j = i; j > 0; --j) {
      if (arr[j-1] > arr[j]) {
	swap(arr, j, j-1);
      } else {
	break;
      }
    }
  }
}
