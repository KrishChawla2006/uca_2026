/*
Question:
isPower2
Complete the following function with the given constraints

/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
int isPower2(int x) {
  return 0;
}
*/
#include <stdio.h>
int isPower2(int x) {
    return !(x & (x + ~0)) & !(x >> 31) & !!x;
}

int main() {
    int x;
    printf("Enter the value of x:");
    scanf("%d",&x);
    printf("isPower2(%d) = %d\n", x, isPower2(x));
    return 0;
}
