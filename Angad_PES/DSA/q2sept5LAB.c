    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include <stdlib.h>

    int equalStacks(int h1_count, int* h1, int h2_count, int* h2, int h3_count, int* h3) {
        int sum1 = 0, sum2 = 0, sum3 = 0;
        int top1 = 0, top2 = 0, top3 = 0;

        for (int i = 0; i < h1_count; i++) {
            sum1 += h1[i];
        }
        for (int i = 0; i < h2_count; i++) {
            sum2 += h2[i];
        }
        for (int i = 0; i < h3_count; i++) {
            sum3 += h3[i];
        }

        while (sum1 != sum2 || sum2 != sum3 || sum1 != sum3) {
            int maxSum = sum3;
            if (sum2 > maxSum) {
                maxSum = sum2;
            }
            if (sum1 > maxSum) {
                maxSum = sum1;
            }

            if (sum1 == maxSum) {
                sum1 -= h1[top1++];
            }
            if (sum2 == maxSum) {
                sum2 -= h2[top2++];
            }
            if (sum3 == maxSum) {
                sum3 -= h3[top3++];
            }
        }

        return sum1; 
    }

    int main() {
        int n1, n2, n3;
        scanf("%d %d %d", &n1, &n2, &n3);

        int h1[n1], h2[n2], h3[n3];
        for (int i = 0; i < n1; i++) {
            scanf("%d", &h1[i]);
        }
        for (int i = 0; i < n2; i++) {
            scanf("%d", &h2[i]);
        }
        for (int i = 0; i < n3; i++) {
            scanf("%d", &h3[i]);
        }

        int result = equalStacks(n1, h1, n2, h2, n3, h3);
        printf("%d\n", result);

        return 0;
    }