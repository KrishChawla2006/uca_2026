/*
Question:
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2

int sign(int x) {
  return 0;
}
*/

#include<stdio.h>
int sign(int x) {
    if(!x)return 0;
    int ans=x>>31;
    if(!ans)return 1;
    else return ans;
}

int main(){
  int n;
  printf("Enter the number: ");
  scanf("%d",&n);
  printf("sign of %d is %d",n,sign(n));
  return 0;
}
