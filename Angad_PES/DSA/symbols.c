#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sym {
    char c;
    char name[50];
    int dot;
} SYMBOL;

SYMBOL *sort(SYMBOL *arr, int n);
void display(SYMBOL *arr, int n);
void swap(SYMBOL *a, SYMBOL *b);

int main() {
    int n;
    scanf("%d", &n);

    // Dynamically allocate the structure array
    SYMBOL *arr = (SYMBOL *)malloc(n * sizeof(SYMBOL));

    // Accept the structure fields from input
    for (int i = 0; i < n; i++) {
        scanf("%d %c %s", &arr[i].dot, &arr[i].c, arr[i].name);
    }

    // Call sort and display functions
    arr = sort(arr, n);
    display(arr, n);

    // Free the allotted memory
    free(arr);

    return 0;
}

SYMBOL *sort(SYMBOL *arr, int n) {
    // Sort alphabetically
    // You can use any sorting algorithm here, such as bubble sort or quicksort
    // I'll use bubble sort as an example
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }

    return arr;
}

void display(SYMBOL *arr, int n) {
    // Print each character of the sorted array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < arr[i].dot; j++) {
            printf(".");
        }
        printf("%c\n", arr[i].c);
    }
}

void swap(SYMBOL *a, SYMBOL *b) {
    SYMBOL temp = *a;
    *a = *b;
    *b = temp;
}