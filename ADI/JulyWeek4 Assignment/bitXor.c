/*
Question:bitXor
Write the following function with given constraints

/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1

int bitXor(int x, int y) {
  return 0;
}
*/
#include<stdio.h>

int bitXor(int x, int y) {
  return ~(~(x&~y)&(~(~x&y)));
}

int main(){
  int x;
  int y;
  printf("Enter the value of x:");
  scanf("%d",&x);
  printf("Enter the value of y:");
  scanf("%d",&y);
  printf("%d ^ %d = %d",x,y,bitXor(x,y));
  return 0;
}
