#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Node;

void merge(Node arr[], int left, int mid, int right, int count[]) {
    int n = right - left + 1;
    Node *temp = (Node *)malloc(n * sizeof(Node));

    int i = left;
    int j = mid + 1;
    int k = 0;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].value < arr[i].value) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }

    free(temp);
}

void mergeSort(Node arr[], int left, int right, int count[]) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);
    merge(arr, left, mid, right, count);
}

int main() {
    int nums[100000];
    int n = 0;

    while (scanf("%d", &nums[n]) == 1)
        n++;

    Node *arr = (Node *)malloc(n * sizeof(Node));
    int *count = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
    }

    mergeSort(arr, 0, n - 1, count);

    for (int i = 0; i < n; i++) {
        printf("%d", count[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n");

    free(arr);
    free(count);

    return 0;
}
