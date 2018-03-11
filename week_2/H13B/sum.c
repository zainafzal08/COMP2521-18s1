#include <stdio.h>
#include <stdlib.h>


typedef struct _Node {
	int value;
	struct _Node *next;
} Node;

typedef Node *List;  // pointer to first Node

int sum(List head);
int sumRec(List head);

int main(int argc, char* argv[]) {
  List head = malloc(sizeof(struct _Node));
  head->value = 1;
  head->next = malloc(sizeof(struct _Node));
  head->next->value = 2;
  head->next->next = malloc(sizeof(struct _Node));
  head->next->next->value = 3;
	head->next->next->next = NULL;

  int result = sum(head);
  int resultRec = sumRec(head);
  printf("sum of 1->2->3 is %d\n",result);
  printf("recSum of 1->2->3 is %d\n",resultRec);
  return EXIT_SUCCESS;
}

int sum(List head) {
	int acc = 0;

	for(Node * n = head; n != NULL; n = n->next) {
		acc += n->value;
	}
	return acc;
}

int sumRec(List head){
  if(head == NULL) {
		return 0;
	}
	return head->value + sumRec(head->next);
}
