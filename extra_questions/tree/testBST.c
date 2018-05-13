#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  BST t = newBST();
  addBST(t,5);
  addBST(t,10);
  addBST(t,7);
  addBST(t,2);
  addBST(t,1);
  addBST(t,0);

  return EXIT_SUCCESS;
}
