#ifndef SRT_TESTS
#define SRTTESTS

void alltests(void foo(int*, int, int), char* name, int debug);
void perftest(void foo(int*, int, int), char* name);
void gentest(int* arr, int size);
int sorttest(void foo(int*, int, int), char* name, int debug);

#endif
