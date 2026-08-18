/*
Question:
Finding numbers in Array
Given an Array of size n. It has integers where all the numbers are repeated 3 times but one number is repeated 4 times. Write a code to find the number repeating 4 times.

Constraints:

size of array: 0 > n > 10^5
Each element i : 0 < i < n
Expected Run time complexity: O(n)
Expected Space complexity: O(1)
Example:

input: [1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 3]
Expected output: 3
Explanation: 3 comes 4 times but others are 3 times in array.
*/

#include <stdio.h>

int findFourTimes(int arr[], int n) {
    int result = 0;

    for (int bit = 0; bit < 32; bit++) {
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] & (1 << bit)) {
                count++;
            }
        }
        if (count % 3 != 0) {
            result |= (1 << bit);
        }
    }

    return result;
}

int main() {
    int arr[] = {1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Number repeated 4 times: %d\n", findFourTimes(arr, n));
    return 0;
}
