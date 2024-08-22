#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
}

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return;
}

void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

struct Node* newNode(int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void deleteAtEnd(struct Node** head_ref) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void insertAtPosition(struct Node** head_ref, int new_data, int position) {
    struct Node* new_node = newNode(new_data);
    if (position == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    struct Node* temp = *head_ref;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void deleteAtGivenPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        return;
    }
    struct Node* temp = *head_ref;
    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void deleteAtBeginning(struct Node** head_ref) {
    struct Node* temp = *head_ref;
    *head_ref = temp->next;
    free(temp);
}

int main(){
    struct Node* head = NULL;
    insertAtEnd(&head, 6);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 4);
    insertAtPosition(&head, 8, 2);
    insertAtEnd(&head, 2);
    insertAtBeginning(&head, 9); // Add a new node at the beginning
    insertAtPosition(&head, 5, 3); // Add a new node at a specific position
    printf("Created Linked list is: ");
    printList(head);
    deleteAtGivenPosition(&head, 2);
    printf("\nLinked list after deletion at position 2: ");
    printList(head);
    deleteAtEnd(&head);
    printf("\nLinked list after deletion at end: ");
    printList(head);
    deleteAtBeginning(&head);
    printf("\nLinked list after deletion at beginning: ");
    printList(head);
    head = reverseList(head);
    printf("\nReversed Linked list is: ");
    printList(head);
    return 0;
}