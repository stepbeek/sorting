#include "merge.h"

void mergesort(int* arr, int low, int high)
{
  int count = high - low + 1;
  if (count <= 2) {
    if (arr[low] > arr[high]) {
      swap(arr, low, high);
    }
  } else {
    int mid = low + (high - low)/2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    
    int tmparr[count];
    int i = 0, j = low, k = mid + 1;
    
    while (j <= mid && k <= high) {
      if (arr[j] < arr[k]) {
	tmparr[i++] = arr[j++];
      } else {
	tmparr[i++] = arr[k++];
      }		
    }
    
    if (j > mid) {
      while (k <= high) {
	tmparr[i++] = arr[k++];
      }
    } else if  (k > high) {
      while (j <= mid) {
	tmparr[i++] = arr[j++];
      }
    }
    
    i = 0;
    j = low;
    while (j <= high) {
      arr[j++] = tmparr[i++];
    }
  }
}
