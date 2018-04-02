/*
 * Question 1
 * ===============================================
 * Below is a simple linked list implementation
 * finish the "swap" function which takes in a
 * list L, a index i and a index j. It swaps the
 * nodes at index i and j in list L.
 *
 * 1->2->3->4 with i = 1 j = 3 becomes
 * 1->4->3->2
 * ================================================
 * > You can assume i and j will always be valid
 * > the list will have at minimum 2 nodes.
 * > you can assume i != j
 * > do not swap the _values_ in the nodes, swap the
 *   nodes themselves.
 */

#include <stdlib.h>
#include <stdio.h>

// Node
typedef struct _node {
  int value;
  struct _node *next;
} node;
typedef node *Node;

// List
typedef struct _list {
  Node head;
  Node tail;
} list;
typedef list *List;

// prototypes
List newList();
void freeNode(Node n);
Node makeNode(int num);
void addNode(List L, Node n);
void showList(List L);
void swap(List L);

// main function
int main(int argc, char* argv[]) {
  int num;
  int i;
  int j;
  int readIn;
  List L = newList();
  scanf("%d %d",&i, &j);
  readIn = scanf("%d",&num);
  while(readIn > 0) {
    addNode(L,makeNode(num));
    readIn = scanf("%d",&num);
  }
  swap(L,i,j);
  showList(L);
  // i'm a good boy and free my memory
  Node curr = L->head;
  while(curr != NULL){
    Node next = curr->next;
    freeNode(curr);
    curr = next;
  }
  free(L);
  return EXIT_SUCCESS;
}

void freeNode(Node n) {
  free(n);
}

List newList(){
  List L = malloc(sizeof(list));
  L->head = NULL;
  L->tail = NULL;
  return L;
}

Node makeNode(int num){
  Node new = malloc(sizeof(node));
  new->value = num;
  new->next = NULL;
  return new;
}

void addNode(List L, Node n){
  if (L->head == NULL) {
    L->head = n;
    L->tail = n;
  }else{
    L->tail->next = n;
    L->tail = n;
  }
}

void showList(List L){
  Node curr = L->head;
  if (L->head != NULL)
    printf("(H:%d|T:%d) ",L->head->value,L->tail->value);
  else
    printf("(H:%d|T:%d) ","NULL","NULL");

  while(curr != NULL){
    printf("[%d]->",curr->value);
    curr = curr->next;
  }
  printf("NULL");
}

// =============================
// TODO: Complete this function
// =============================
void swap(List L, int i, int j) {

}
