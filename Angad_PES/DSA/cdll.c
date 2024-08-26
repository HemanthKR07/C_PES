#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        struct Node* last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        struct Node* last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
    }
}

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("CDLL is empty.\n");
        return;
    }
    struct Node* curr = *head;
    struct Node* prevNode, *nextNode;
    while (curr->data != key) {
        if (curr->next == *head) {
            printf("Node with key %d not found.\n", key);
            return;
        }
        curr = curr->next;
    }
    prevNode = curr->prev;
    nextNode = curr->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    if (curr == *head) {
        *head = nextNode;
    }
    free(curr);
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("CDLL is empty.\n");
        return;
    }
    struct Node* curr = head;
    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 4);

    printf("CDLL: ");
    display(head);

    deleteNode(&head, 2);

    printf("CDLL after deletion: ");
    display(head);

    return 0;
}
