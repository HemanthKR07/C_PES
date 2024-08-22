#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct hotel {
    char name[50];
    int price;
    int squarefeet;
    double ratio;
} HOTEL;

void Ratio_Order(HOTEL *h, int n);

int main() {
    int n;
    scanf("%d", &n);
    HOTEL h[n];

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", h[i].name, &h[i].price, &h[i].squarefeet);
    }

    Ratio_Order(h, n);

    for (int i = 0; i < n; i++) {
        printf("%s %d %d %.2lf\n", h[i].name, h[i].price, h[i].squarefeet, h[i].ratio);
    }

    return 0;
}

void Ratio_Order(HOTEL *h, int n) {
    for (int i = 0; i < n; i++) {
        h[i].ratio = (double) h[i].squarefeet / h[i].price;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (h[j].ratio < h[j + 1].ratio) {
                HOTEL temp = h[j];
                h[j] = h[j + 1];
                h[j + 1] = temp;
            }
        }
    }
}