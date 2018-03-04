#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int isSorted(int* a, int size);

int main(int argc, char* argv[]) {

  // test one
  int test[] = {1,2,3,4,5};
  if (isSorted(test,5))
    printf("[1,2,3,4,5] is sorted\n");
  else
    printf("[1,2,3,4,5] is not sorted\n");

  // test two
  int test2[] = {1,2,3,5,4};
  if (isSorted(test2,5))
    printf("[1,2,3,4,5] is sorted\n");
  else
    printf("[1,2,3,4,5] is not sorted\n");

  return EXIT_SUCCESS;
}

int isSorted(int* a, int size) {
  return FALSE;
}
