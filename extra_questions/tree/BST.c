#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

BST newBST() {
  BST n = malloc(sizeof(struct _BST));
  n->root = NULL;
  return n;
}

Link newNode(int v) {
  Link n = malloc(sizeof(struct _BSTNode));
  n->value = v;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void appendNode(Link l, int v) {
  if (v >= l->value && l->right == NULL) l->right = newNode(v);
  else if (v < l->value && l->left == NULL) l->left = newNode(v);
  else if (v >= l->value) appendNode(l->right,v);
  else if (v < l->value) appendNode(l->left,v);
}

void addBST(BST t, int v) {
  if(!t->root) t->root = newNode(v);
  else appendNode(t->root,v);
}

int digits(int n){
  int count = 0;
  while(n > 10) {
    count++;
    n = n/10;
  }
  return count;
}
int recBSTWidth(Link n){
  return !n ? 0: recBSTWidth(n->left)+(2+digits(n->value))+recBSTWidth(n->right);
}
int BSTWidth(BST t) {
  return recBSTWidth(t->root);
}

// adds a node to a tree in the right place

// Prints out a tree like this
//      [5]
//     /   \
//   [1]   [2]
void printTree(BST t) {
  while()
}
