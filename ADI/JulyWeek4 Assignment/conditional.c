/*
Question:
conditional
Complete the following function with the given constraints

/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3

int conditional(int x, int y, int z) {
  return 0;
}
*/
#include<stdio.h>

int conditional(int x, int y, int z) {
    int mask = ~(~(!x) + 1);
    return (mask & y) | (~mask & z);
}

int main(){
  int x;
  int y;
  int z;
  printf("Enter the value of x:");
  scanf("%d",&x);
  printf("Enter the value of y:");
  scanf("%d",&y);
  printf("Enter the value of z:");
  scanf("%d",&z);
  printf("%d ? %d : %d = %d",x,y,z,conditional(x,y,z));
  return 0;
}
