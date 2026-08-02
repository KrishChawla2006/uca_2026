/*
Question:
bitAnd
Implement following function with the given constraints:

/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 
int bitAnd(int x, int y) {
  return 0;
}
*/
#include<stdio.h>

int bitAnd(int x, int y) {
  return ~(~ x | ~ y);
}

int main(){
  int x;
  int y;
  printf("Enter the value of x:");
  scanf("%d",&x);
  printf("Enter the value of y:");
  scanf("%d",&y);
  printf("%d & %d = %d",x,y,bitAnd(x,y));
  return 0;
}
