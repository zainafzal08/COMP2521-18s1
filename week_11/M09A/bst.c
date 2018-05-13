#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define FALSE 0
#define TRUE 0

typedef struct BSTNode *Link;
typedef struct BSTNode *BSTree;

typedef struct BSTNode {
   int  value;
   int deleted;
   Link left, right;
} BSTNode;

Link newNode(int v) {
  Link n = malloc(sizeof(BSTNode));
  n->value = v;
  n->deleted = FALSE:
  n->left = NULL;
  n->right = NULL;
  return n;
}

int BSTreeFind(BSTree t, int v)
{
   if (t == NULL)
      return 0;
   else if (v < t->value)
      return BSTreeFind(t->left, v);
   else if (v > t->value)
      return BSTreeFind(t->right, v);
   else if (t->deleted)
      return 0;
   else // (v == t->value && !t->deleted)
      return 1;
}

int BSTreeNumValues(BSTree t)
{
   if (t == NULL)
      return 0;
   else {
      int countForThisNode;
      if (t->deleted)
         countForThisNode = 0;
      else
         countForThisNode = 1;
      return countForThisNode
               + BSTreeNumValues(t->left)
               + BSTreeNumValues(t->right);
   }
}

BSTree BSTreeDelete(BSTree t, int v)
{
   if (t == NULL)
      /* do nothing */;
   else if (v < t->value)
      t->left = BSTreeDelete(t->left, v);
   else if (v > t->value)
      t->right = BSTreeDelete(t->right, v);
   else
      t->deleted = 1;
   return t;
}

// TODO: do dis x 2
// pls do not call on null thank
int max(BSTree t){
  if(t == NULL) abort();
  if(t->right != NULL) return max(t->right);
  else return t->value;
}

int min(BSTree t){
  if(t == NULL) abort();
  if(t->left != NULL) return min(t->left);
  else return t->value;
}

BSTree BSTreeInsert(BSTree t, int v) {
    // simp;e base
    if(t == NULL){
      return newNode(v);
    }
    // already exists but deleted
    if(t->value == v && t->deleted) {
      t->deleted = FALSE;
      return t;
    }
    if(v > max(t->left) && v < min(t->right) && t->deleted) {
      t->value = v;
      t->deleted = FALSE;
    }
    // recurrse case
    if(v < t->value) t->left = BSTreeInsert(t->left,v);
    if(v >= t->value) t->right = BSTreeInsert(t->right,v);
    return t;
}

void showBSTreeInfix(BSTree t)
{
  if(t == NULL) return;
  showBSTreeInfix(t->left);
  printf("%d ",t->value);
  showBSTreeInfix(t->right);
}

int main(int argc, char* argv[]) {
  Link t = newNode(4);
  BSTreeInsert(t,2);
  BSTreeInsert(t,3);
  BSTreeInsert(t,5);
  BSTreeInsert(t,6);
  showBSTreeInfix(t);
  return EXIT_SUCCESS;
}
