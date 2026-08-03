/*
Question:
Select smallest K elements
Imagine you have an unordered, unindexed dataset stored in a file system or database.

Write an implementation of the Quickselect algorithm to retrieve the first K elements in any order with an average time complexity of O(n).
Additionally, demonstrate why its average runtime complexity is linear O(n) by plotting runtime against dataset size n to illustrate the straight-line relationship.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[right]);
    return i;
}


void quickSelect(int arr[], int left, int right, int k) {
    if (left >= right)
        return;

    int pivotIndex = left + rand() % (right - left + 1);

    swap(&arr[pivotIndex], &arr[right]);

    int p = partition(arr, left, right);

    if (p == k)
        return;
    else if (p > k)
        quickSelect(arr, left, p - 1, k);
    else
        quickSelect(arr, p + 1, right, k);
}

void smallestK(int arr[], int n, int k) {
    if (k <= 0 || k > n)
        return;

    quickSelect(arr, 0, n - 1, k - 1);

    printf("Smallest %d elements:\n", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int arr[] = {10, 4, 5, 8, 6, 11, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    smallestK(arr, n, k);

    return 0;
}
