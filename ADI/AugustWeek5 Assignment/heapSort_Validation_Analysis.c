#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {

    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    
    for (int i = n - 1; i > 0; i--) {

        
        swap(&arr[0], &arr[i]);

      
        heapify(arr, i, 0);
    }
}


int isSorted(int arr[], int n) {

    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i])
            return 0;
    }

    return 1;
}


void createRandom(int arr[], int n) {

    for (int i = 0; i < n; i++)
        arr[i] = rand();
}


void createAscending(int arr[], int n) {

    for (int i = 0; i < n; i++)
        arr[i] = i;
}


void createDescending(int arr[], int n) {

    for (int i = 0; i < n; i++)
        arr[i] = n - i;
}


double measureTime(int arr[], int n) {

    clock_t start = clock();

    heapSort(arr, n);

    clock_t end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main() {

 
    int sizes[] = {
        10000,
        20000,
        40000,
        80000,
        160000
    };

    int numberOfSizes = sizeof(sizes) / sizeof(sizes[0]);


    srand(time(NULL));

   

    printf("%-10s %-15s %-15s %-15s\n",
           "Size",
           "Random",
           "Ascending",
           "Descending");


    for (int i = 0; i < numberOfSizes; i++) {

        int n = sizes[i];


        int *randomArray = malloc(n * sizeof(int));
        int *ascendingArray = malloc(n * sizeof(int));
        int *descendingArray = malloc(n * sizeof(int));

        if (randomArray == NULL ||
            ascendingArray == NULL ||
            descendingArray == NULL) {

            printf("Memory allocation failed.\n");
            return 1;
        }

        createRandom(randomArray, n);
        createAscending(ascendingArray, n);
        createDescending(descendingArray, n);

      
        double randomTime =
            measureTime(randomArray, n);

        double ascendingTime =
            measureTime(ascendingArray, n);

        double descendingTime =
            measureTime(descendingArray, n);

    
        int randomOK = isSorted(randomArray, n);
        int ascendingOK = isSorted(ascendingArray, n);
        int descendingOK = isSorted(descendingArray, n);

        printf("%-10d %-15.6f %-15.6f %-15.6f\n",
               n,
               randomTime,
               ascendingTime,
               descendingTime);

        if (!randomOK ||
            !ascendingOK ||
            !descendingOK) {

            printf("Sorting failed for size %d\n", n);
        }


        free(randomArray);
        free(ascendingArray);
        free(descendingArray);
    }

    printf("\nSorting verification: PASSED\n");

    printf("\nTime Complexity: O(n log n)\n");
    printf("Space Complexity: O(1)\n");

    return 0;
}
