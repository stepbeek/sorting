#include <stdio.h>
#include <stdlib.h>
#include "bubblesort.h"
#include "sortingtests.h"
#include "treesort.h"
#include "selection.h"
#include "insertion.h"
#include "quick.h"
#include "merge.h"

int main(int argc, char* argv[])
{
  alltests(&treesort, "Treesort", 0);
  alltests(&quicksort, "Quicksort", 0);
  alltests(&mergesort, "Merge sort", 0);
  alltests(&insertionsort, "Insertion sort", 0);
  alltests(&selectionsort, "Selection sort", 0);
  alltests(&bubblesort, "Bubble sort", 0);
  
  return 0;
}
