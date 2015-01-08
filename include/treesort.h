#ifndef TREE_SRT
#define TREE_SRT
struct node;
typedef struct node node;
void swap(int* arr, int i, int j);
node* newnode(int val);
void insert(node* nd, int val);
int printnode(node* nd, int* arr, int i);
void freetree(node* nd);
void treesort(int* arr, int low, int high);
#endif
