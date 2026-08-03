/*
Question:
getByte
Complete the following function

/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 
int getByte(int x, int n) {
  return 0;
}
*/
#include <stdio.h>
int getByte(int x, int n) {
    return (x >> (n << 3)) & 0xFF;
}

int main() {
    unsigned int x;
    int n;
    printf("Enter x (hex): ");
    scanf("%x", &x);
    printf("Enter n: ");
    scanf("%d", &n);
    printf("getByte(0x%X, %d) = 0x%X\n", x, n, getByte(x, n));
    return 0;
}
