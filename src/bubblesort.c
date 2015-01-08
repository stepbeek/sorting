#include "bubblesort.h"

void bubblesort(int* arr, int low, int high)
{
  int didsort = 1;
  int count = 0;
  while (didsort) {
    didsort = 0;
    count++;
    int i;

    for (i = 0; i < high; i++) {
      if (arr[i] > arr[i+1]) {
	swap(arr, i, i+1);
	didsort = 1;
      }
    }
  }
}
