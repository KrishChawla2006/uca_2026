/*
Question:
1. Sum of even numbers in Fibonacci series
Given a number n find the sum of all the even valued terms in the Fibonacci sequence less than or equal to n.
The first few terms of Fibonacci Numbers are, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233 ,… (Even numbers are highlighted).
ex: n = 10
1,1,2,3,5,8,13 skip 13 as it is greater than 10. 
output = 2+8 = 10

ex: n = 50
1,1,2,3,5,8,13,21,34
output = 2+8+34 = 44
Solve the problems using two approaches

Brute Force : O(n) Time and O(1) Space
Optimized Approach : O(log n) Time and O(1) Space
*/

#include <stdio.h>

// Brute Force Approach: O(n) Time, O(1) Space
long long sumEvenFibonacciBrute(int n) {
    if (n < 2)
        return 0;

    long long a = 1, b = 1, c;
    long long sum = 0;

    while (1) {
        c = a + b;

        if (c > n)
            break;

        if (c % 2 == 0)
            sum += c;

        a = b;
        b = c;
    }

    return sum;
}

// Optimized Approach: O(log n) Time, O(1) Space
long long sumEvenFibonacciOptimized(int n) {
    if (n < 2)
        return 0;

    long long even1 = 2;
    long long even2 = 8;
    long long sum = 0;

    while (even1 <= n) {
        sum += even1;

        long long next = 4 * even2 + even1;

        even1 = even2;
        even2 = next;
    }

    return sum;
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Brute Force Sum = %lld\n", sumEvenFibonacciBrute(n));
    printf("Optimized Sum = %lld\n", sumEvenFibonacciOptimized(n));

    return 0;
}
