#import <stdlib.h>
#import <stdio.h>

/*
 * Demo
 *
 * This is a really simple array sum rec function
 * but with some prints that should help you understand
 * how it's working
 */

int sum(int* array, int i, int size) {
  printf("I'm starting sum with i=%d!\n",i);
  if (i >= size) {
    printf("Whoops i went off the end, i'll stop recurrsing now!\n");
    return 0;
  }
  int result = array[i]+sum(array,i+1,size);
  printf("I'm finishing sum with i=%d!\n",i);
  return result;
}


int main(int argc, char* argv[]) {
  int x[5] = {1,2,3,4,5};
  printf("Sum: %d\n",sum(x,0,5));
}
