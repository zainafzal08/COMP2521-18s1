List getEven(List L) {

  List evenList = newList();
  Node curr = L->head;
  Node prev = NULL;
  while(curr != NULL) {
    // if even
    if(curr->value % 2 == 0) {
      // disconnect from the list (and update head if need be)
      if(prev == NULL)
        L->head = curr->next;
      else
        prev->next = curr->next;
      // do i need to update tail?
      if(curr->next == NULL)
        L->tail = prev;

      Node tmp = curr->next;
      curr->next = NULL;

      // add it to the even list
      addNode(evenList,curr);

      // update curr (prev is still correct)
      curr = tmp;
    } else {
      // else progress
      prev = curr;
      curr = curr->next;
    }
  }
  return evenList;
}