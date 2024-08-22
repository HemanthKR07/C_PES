#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int findSmallest(int arr[], int n) {
    if (n == 0) {
        return 0;
    }
    
    if (n == 1) {
        return arr[0];
    }
    
    int smallest = findSmallest(arr + 1, n - 1);
    
    if (arr[0] < smallest) {
        return arr[0];
    } else {
        return smallest;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int req = findSmallest(arr, n);
    if (req>0){
    printf("%d", req);
    }else{printf("NULL");}
    return 0;
}