#include <stdio.h>
#include <stdlib.h>

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

void buildMaxHeap(int heap[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(heap, n, i);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, z;
    scanf("%d", &n);
    scanf("%d", &z);

    int heap[z];
    int heapSize = 0;
    int element;

    for (int i = 0; i < n; i++) {
        scanf("%d", &element);

        if (heapSize < z) {
            heap[heapSize] = element;
            heapSize++;
            buildMaxHeap(heap, heapSize);
        } else if (element < heap[0]) {
            heap[0] = element;
            heapify(heap, z, 0);
        }

        printArray(heap, heapSize);
    }
    return 0;
}