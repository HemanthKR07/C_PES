#include <stdio.h>

void costcalc(int *queue, int *stack, int *top, int *f, int *r, int *sum, int n) {
    while (*f != *r) {
        if (*top < 0) break; // Stack is empty

        int served = 0;
        for (int i = 0; i < n; i++) {
            if (queue[*f] == stack[*top]) {
                // Customer buys the dish
                if (stack[*top] == 0) {
                    *sum += 50;
                } else {
                    *sum += 40;
                }
                (*top)--; // Remove the dish from the stack
                (*f)++; // Move to the next customer
                served = 1;
                break;
            } else {
                // Move customer to the end of the queue
                queue[*r] = queue[*f];
                (*f)++;
                (*r)++;
            }
        }
        if (!served) break; // No customer wants the dish on top of the stack
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int queue[n * 2]; // Double the size to handle circular queue
    int stack[n];
    int top = n - 1;
    int f = 0, r = n;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &stack[i]);
    }

    costcalc(queue, stack, &top, &f, &r, &sum, n);

    printf("%d\n", sum);

    return 0;
}