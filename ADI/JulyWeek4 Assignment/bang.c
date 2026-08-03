/*
Question:
bang
Complete the following function with given constraints

/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 
int bang(int x) {
  return 0;
}
*/
#include<stdio.h>

int bang(int x) {
    return ((x | (~x + 1)) >> 31) + 1;
}

int main(){
  int n;
  printf("Enter the number: ");
  scanf("%d",&n);
  printf("bang of %d is %d",n,bang(n));
  return 0;
}
