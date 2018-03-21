#import <stdlib.h>
#import <stdio.h>

/*
 * Question 1
 *
 * Write a function to print out all the numbers from n to 0
 * i.e if i say printSeq(5) i would print out
 * 5
 * 4
 * 3
 * 2
 * 1
 * 0
 */

void printSeq(int n) {
  if(n < 0) return;
  printf("%d\n",n);
  printSeq(n-1);
}

void revSeq(int n) {
  if(n < 0) return;
  revSeq(n-1);
  printf("%d\n",n);
}

int main(int argc, char* argv[]) {
  int x = 3;
  printSeq(x);
  printf("======\n");
  revSeq(x);
}
