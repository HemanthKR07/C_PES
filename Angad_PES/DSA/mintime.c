#include <stdio.h>

int canServeAllPastries(int trays[], int n, int k, int h) {
    int totalHours = 0;
    for (int i = 0; i < n; i++) {
        totalHours += (trays[i] + k - 1) / k;
    }
    return totalHours <= h;
}

int findMinimumSpeed(int trays[], int n, int h) {
    int left = 1, right = 1e9;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canServeAllPastries(trays, n, mid, h)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int n;
    scanf("%d", &n);
    int trays[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &trays[i]);
    }
    int h;
    scanf("%d", &h);
    int minimumSpeed = findMinimumSpeed(trays, n, h);
    printf("%d\n", minimumSpeed);
    return 0;
}