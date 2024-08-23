#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
    int coeff;
    int pow;
    struct node* next;
} node;

void input(node** head, node** tail, int n) {
    for (int i = 0; i < n; i++) {
        int coeff, pow;
        scanf("%d %d", &coeff, &pow);

        if (coeff == 0) continue;  // Skip if coefficient is zero

        node* newNode = (node*)malloc(sizeof(node));
        newNode->coeff = coeff;
        newNode->pow = pow;
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
            *tail = newNode;
        } else {
            (*tail)->next = newNode;
            *tail = newNode;
        }
    }
}

node* sum(node* head1, node* head2) {
    node* headres = NULL;
    node* tailres = NULL;

    while (head1 != NULL || head2 != NULL) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->next = NULL;

        if (head1 != NULL && head2 != NULL && head1->pow == head2->pow) {
            newNode->coeff = head1->coeff + head2->coeff;
            newNode->pow = head1->pow;
            head1 = head1->next;
            head2 = head2->next;
        } else if (head2 == NULL || (head1 != NULL && head1->pow > head2->pow)) {
            newNode->coeff = head1->coeff;
            newNode->pow = head1->pow;
            head1 = head1->next;
        } else {
            newNode->coeff = head2->coeff;
            newNode->pow = head2->pow;
            head2 = head2->next;
        }

        if (newNode->coeff != 0) {  // Only add non-zero terms
            if (headres == NULL) {
                headres = newNode;
                tailres = newNode;
            } else {
                tailres->next = newNode;
                tailres = newNode;
            }
        } else {
            free(newNode);
        }
    }

    return headres;
}

int eval(node* head, int x) {
    int result = 0;
    while (head != NULL) {
        result += head->coeff * pow(x, head->pow);
        head = head->next;
    }
    return result;
}

void destroy(node **head) {
    node* current = *head;
    node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

int main() {
    int m = 0, n = 0;
    node* head1 = NULL;
    node* head2 = NULL;
    node* tail1 = NULL;
    node* tail2 = NULL;
    int x = 0;

    scanf("%d %d", &m, &n);
    scanf("%d", &x);
    input(&head1, &tail1, m);
    input(&head2, &tail2, n);

    node* headres = sum(head1, head2);
    if (headres == NULL) {
        printf("-1");
    } else {
        int res = eval(headres, x);
        printf("%d", res);
    }

    destroy(&head1);
    destroy(&head2);
    destroy(&headres);
    
    return 0;
}