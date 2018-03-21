#import <stdlib.h>
#import <stdio.h>

/*
 * Question 2
 *
 * finish the factorial function
 * below! remember fac(3) = fac(2)*3 = fac(1)*2*3 = 1*2*3
 */

int fac(int n) {
  if (n == 0 || n == 1)
    return 1;
  else
    return fac(n-1)*n;
}

int main(int argc, char* argv[]) {
 int x = 3;
 printf("fac(%d) is %d\n",x,fac(x));
}
