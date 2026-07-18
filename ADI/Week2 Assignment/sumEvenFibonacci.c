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
