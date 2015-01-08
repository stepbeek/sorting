#include <stdio.h>
#include <stdlib.h>
#include "treesort.h"

struct node {
  struct node* left;
  struct node* right;
  int val;
};

static node nullnode = {NULL, NULL, 0};

void swap(int* arr, int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

node* newnode(int val)
{
  node* nd = malloc(sizeof(node));

  if (nd == NULL) {
    printf("Cannot create new tree node...\n");
    exit(1);
  }

  nd->val = val;
  nd->left = &nullnode;
  nd->right = &nullnode;

  return nd;
}

void insert(node* nd, int val)
{
  if (nd == &nullnode) {
    nd = newnode(val);
  } else {
    if (val <= nd->val) {
      if (nd->left == &nullnode) {
	nd->left = newnode(val);
      } else {
	insert(nd->left, val);
      }
    } else {
      if (nd->right == &nullnode) {
	nd->right = newnode(val);
      } else {
	insert(nd->right, val);
      }
    }
  }
}

int printnode(node* nd, int* arr, int i)
{
  int x = i;
  if (nd != &nullnode) {
    x = printnode(nd->left, arr, x);
    arr[x++] = nd->val;
    x = printnode(nd->right, arr, x);
  }
  return x;
}

void freetree(node* nd)
{
  if (nd != &nullnode) {
    freetree(nd->left);
    freetree(nd->right);
    free(nd);
  }
}

void treesort(int* arr, int low, int high)
{
  node* nd = newnode(arr[low]);
  
  int i;
  for (i = low+1; i <= high; i++) {
    insert(nd, arr[i]);
  }
  
  printnode(nd, arr, 0);
}
