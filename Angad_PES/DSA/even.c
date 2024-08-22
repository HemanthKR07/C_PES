#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int frequency[1000] = {0}; 

    int mostFrequentEven = -1;
    int smallestEven = -1;
    int maxFrequency = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] % 2 == 0) { 
            frequency[nums[i]]++; 
            
            if (frequency[nums[i]] > maxFrequency) {
                maxFrequency = frequency[nums[i]];
                mostFrequentEven = nums[i];
            } else if (frequency[nums[i]] == maxFrequency && (smallestEven == -1 || nums[i] < smallestEven)) {
                smallestEven = nums[i];
            }
        }
    }

    if (mostFrequentEven == -1) {
        printf("%d\n", smallestEven);
    } else {
        printf("%d\n", mostFrequentEven);
    }

    return 0;
}
