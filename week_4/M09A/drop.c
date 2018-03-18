#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct ListNode *Link;

typedef struct ListNode {
    int value;
    Link next;
} ListNode;

typedef Link List;

#define head(L)  (empty(L) ? -1 : (L)->value)
#define tail(L)  (empty(L) ? NULL : (L)->next)
#define empty(L) ((L) == NULL)

// display the value contained in a ListNode
#define show(V) { printf("%d",(V)); }

// create a new ListNode containing supplied value
// prints error and exit()s if can't create a ListNode
Link newNode(int val) {
  Link n = malloc(sizeof(ListNode));
  n->next = NULL;
  n->value = val;
  return n;
}

int main(int argc, char* argv[]) {

  return EXIT_SUCCESS;
}


void drop(List L) {
  if (L == NULL) {
    return;
  }
  List tmp = L->next;
  free(L);
  return drop(tmp);
}


void magic(List L) {
  magic(L->next);
  print("%d\n",L->value);
  return;
}
