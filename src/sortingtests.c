#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include "sortingtests.h"

int TEST_SIZE = 10000;


int sorttest(void foo(int*, int, int), char* name, int debug)
{
  int testarr[] = {5, 3, 1, 4, 2, 11, 9, 10, 8, 6, 7};

  foo(testarr, 0, 10);

  int i;
  int result = 1;
  for (i = 0; i < 11; i++) {
    if (debug) {
      printf("%d\n", testarr[i]);
    }
    if (testarr[i] != i + 1) {
      result = 0;
    }
  }

  if (result) {
    printf("%s test has passed.\n", name);
  } else {
    printf("%s test has failed.\n", name);
  }
  return result;
}

void gentest(int* arr, int size)
{
  int i;
  int rand = 31;
  
  for (i = 0; i < size; i++) {
    rand = (rand*rand) % size;
    arr[i] = rand;
  }
}


void perftest(void foo(int*, int, int), char* name)
{
  int arr[TEST_SIZE];
  gentest(arr, TEST_SIZE);
  
  struct timeval st , et;
  gettimeofday(&st , NULL);
  foo(arr, 0, TEST_SIZE - 1);
  gettimeofday(&et , NULL);
  ulong timetaken = (et.tv_usec + et.tv_sec*1000000 -
		     st.tv_usec - st.tv_sec*1000000)/1000;
    
  printf("Total time taken for %s is  %lu ms\n",
	 name, timetaken);
}

void alltests(void foo(int*, int, int), char* name, int debug)
{
  if (sorttest(foo, name, debug)) {
    perftest(foo, name);
  } else {
    puts("Not running accompanying performance test.");
  }
  printf("\n");
}
