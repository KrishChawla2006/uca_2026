#include <stdio.h>
#include <stdlib.h>

int merge(int nums[], int low, int mid, int high) {
    int count = 0;

    int j = mid + 1;
    for (int i = low; i <= mid; i++) {
        while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }

    int *temp = (int *)malloc((high - low + 1) * sizeof(int));

    int left = low, right = mid + 1, k = 0;

    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right])
            temp[k++] = nums[left++];
        else
            temp[k++] = nums[right++];
    }

    while (left <= mid)
        temp[k++] = nums[left++];

    while (right <= high)
        temp[k++] = nums[right++];

    for (int i = 0; i < k; i++)
        nums[low + i] = temp[i];

    free(temp);

    return count;
}

int mergeSort(int nums[], int low, int high) {
    if (low >= high)
        return 0;

    int mid = low + (high - low) / 2;

    int count = 0;
    count += mergeSort(nums, low, mid);
    count += mergeSort(nums, mid + 1, high);
    count += merge(nums, low, mid, high);

    return count;
}

int reversePairs(int nums[], int n) {
    return mergeSort(nums, 0, n - 1);
}

int main() {
    int nums[100000];
    int n = 0;

    while (scanf("%d", &nums[n]) == 1)
        n++;

    printf("%d\n", reversePairs(nums, n));

    return 0;
}
