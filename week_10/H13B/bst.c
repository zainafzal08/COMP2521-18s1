#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct BSTNode *Link;
typedef struct BSTNode *BSTree;

typedef struct BSTNode {
   int  value;
   Link left, right;
} BSTNode;

Link newNode(int v) {
  Link n = malloc(sizeof(BSTNode));
  n->value = v;
  n->left = NULL;
  n->right = NULL;
  return n;
}


int BSTWidth(BSTree t) {
  return t == NULL ? 0 : BSTWidth(t->left) + 3 + BSTWidth(t->right);
}


int main(int argc, char* argv[]) {
  Link t = newNode(4);
  t->left = newNode(2);
  t->left->right = newNode(3);
  t->right = newNode(5);
  t->right->right = newNode(6);
  assert(BSTWidth(t) == 15);
}
