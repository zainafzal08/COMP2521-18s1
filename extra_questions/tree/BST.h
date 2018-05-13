typedef struct _BSTNode *Link;
typedef struct _BST *BST;

struct _BSTNode {
   int  value;
   Link left, right;
};

struct _BST {
   Link root;
};

BST newBST();
void addBST(BST t, int v);
int BSTWidth(BST t);
void printTree(BST t);
