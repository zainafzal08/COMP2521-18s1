typedef struct _BSTNode *Link;
typedef struct _BSTree *BSTree;

typedef struct _BSTNode {
   int  value;
   Link left, right;
} BSTNode;

typedef struct _BSTree {
   Link root;
} BSTNode;

BSTree newBST();
int BSTWidth(BSTree t);
void printTree(BSTree t);
