#include "BST.h"


BSTree newBST() {
  Link n = malloc(sizeof(struct _BSTree));
  n->root = NULL
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
  if(v >= l->value && l->right == NULL) l->right = newNode(v);
  if(v < l->value && l->left == NULL) l->left = newNode(v);
  if(v >= l->value) appendNode(l->right);
  if(v < l->value) appendNode(l->left);
}

void addBST(BSTree t, int v) {
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

int BSTWidth(BSTree t) {
  Link n = t->root;
  int nodeWidth = 2+digits(n->value);
  return !t ? 0: BSTWidth(n->left)+(nodeWidth)+BSTWidth(n->right);
}

// adds a node to a tree in the right place

// Prints out a tree like this
//      [5]
//     /   \
//   [1]   [2]
void printTree(BSTree t) {

}
