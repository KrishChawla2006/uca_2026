#include <stdio.h>

#define MAX 100

int maxHeap[MAX], minHeap[MAX];
int maxSize = 0, minSize = 0;

// MAX HEAP

void maxPush(int x) {
    int i = maxSize++;
    
    while (i > 0 && maxHeap[(i - 1) / 2] < x) {
        maxHeap[i] = maxHeap[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    maxHeap[i] = x;
}

int maxPop() {
    int result = maxHeap[0];
    int x = maxHeap[--maxSize];

    int i = 0;

    while (2 * i + 1 < maxSize) {
        int child = 2 * i + 1;

        if (child + 1 < maxSize &&
            maxHeap[child + 1] > maxHeap[child])
            child++;

        if (maxHeap[child] <= x)
            break;

        maxHeap[i] = maxHeap[child];
        i = child;
    }

    maxHeap[i] = x;

    return result;
}

// MIN HEAP

void minPush(int x) {
    int i = minSize++;

    while (i > 0 && minHeap[(i - 1) / 2] > x) {
        minHeap[i] = minHeap[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap[i] = x;
}

int minPop() {
    int result = minHeap[0];
    int x = minHeap[--minSize];

    int i = 0;

    while (2 * i + 1 < minSize) {
        int child = 2 * i + 1;

        if (child + 1 < minSize &&
            minHeap[child + 1] < minHeap[child])
            child++;

        if (minHeap[child] >= x)
            break;

        minHeap[i] = minHeap[child];
        i = child;
    }

    minHeap[i] = x;

    return result;
}

// INSERT

void insert(int num) {

    if (maxSize == 0 || num <= maxHeap[0])
        maxPush(num);
    else
        minPush(num);

    
    if (maxSize > minSize + 1)
        minPush(maxPop());

    else if (minSize > maxSize + 1)
        maxPush(minPop());
}

// MEDIAN 

float getMedian() {

    if (maxSize > minSize)
        return maxHeap[0];

    if (minSize > maxSize)
        return minHeap[0];

    return (maxHeap[0] + minHeap[0]) / 2.0;
}

int main() {

    int stream[] = {5, 15, 1, 3};
    int n = 4;

    for (int i = 0; i < n; i++) {
        insert(stream[i]);

        printf("Inserted %d -> Median = %.2f\n",
               stream[i], getMedian());
    }

    return 0;
}
