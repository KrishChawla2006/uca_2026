/*
Question:
Generic heap sort in C
Implement heap sort in C. It has to be implemented such that it can sort any type of data.

Key highlights:

use of function pointer
use of void pointer
memcpy function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *a, void *b, size_t size)
{
    void *temp = malloc(size);

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);

    free(temp);
}

void heapify(
    void *arr,
    size_t n,
    size_t i,
    size_t size,
    int (*compare)(const void *, const void *)
)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    char *array = (char *)arr;

    if (left < n &&
        compare(array + left * size,
                array + largest * size) > 0)
    {
        largest = left;
    }

    if (right < n &&
        compare(array + right * size,
                array + largest * size) > 0)
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(
            array + i * size,
            array + largest * size,
            size
        );

        heapify(arr, n, largest, size, compare);
    }
}

void heap_sort(
    void *arr,
    size_t n,
    size_t size,
    int (*compare)(const void *, const void *)
)
{
    char *array = (char *)arr;

    for (int i = (int)n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i, size, compare);
    }

    for (size_t i = n - 1; i > 0; i--)
    {
        swap(
            array,
            array + i * size,
            size
        );

        heapify(arr, i, 0, size, compare);
    }
}


int compare_int(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x > y)
        return 1;

    if (x < y)
        return -1;

    return 0;
}


int compare_double(const void *a, const void *b)
{
    double x = *(const double *)a;
    double y = *(const double *)b;

    if (x > y)
        return 1;

    if (x < y)
        return -1;

    return 0;
}


int main()
{
    int arr[] = {10, 3, 5, 1, 8, 2, 7};

    size_t n = sizeof(arr) / sizeof(arr[0]);

    heap_sort(
        arr,
        n,
        sizeof(int),
        compare_int
    );

    printf("Sorted integers:\n");

    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");


    double numbers[] = {
        4.5, 1.2, 9.8, 2.3, 7.1
    };

    size_t m = sizeof(numbers) / sizeof(numbers[0]);

    heap_sort(
        numbers,
        m,
        sizeof(double),
        compare_double
    );

    printf("\nSorted doubles:\n");

    for (size_t i = 0; i < m; i++)
    {
        printf("%.1f ", numbers[i]);
    }

    printf("\n");

    return 0;
}
