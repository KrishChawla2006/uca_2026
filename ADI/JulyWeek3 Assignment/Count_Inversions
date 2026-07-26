#include <stdio.h>
#include <stdlib.h>

long long merge(int arr[], int low, int mid, int high) {
    long long invCount = 0;

    int n1 = mid - low + 1;
    int n2 = high - mid;

    int *left = (int *)malloc(n1 * sizeof(int));
    int *right = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];

    for (int i = 0; i < n2; i++)
        right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            invCount += (n1 - i);   
        }
    }

    while (i < n1)
        arr[k++] = left[i++];

    while (j < n2)
        arr[k++] = right[j++];

    free(left);
    free(right);

    return invCount;
}

long long mergeSort(int arr[], int low, int high) {
    long long invCount = 0;

    if (low < high) {
        int mid = low + (high - low) / 2;

        invCount += mergeSort(arr, low, mid);
        invCount += mergeSort(arr, mid + 1, high);
        invCount += merge(arr, low, mid, high);
    }

    return invCount;
}

int main() {
    int arr[100000];
    int n = 0;

    while (scanf("%d", &arr[n]) == 1)
        n++;

    printf("%lld\n", mergeSort(arr, 0, n - 1));

    return 0;
}
