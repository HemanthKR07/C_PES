#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
}NODE;

NODE* createNode(int data){
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    if (newNode == NULL) {
        printf("Memory allocation failed");
        return NULL;
    }
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(NODE* head, int data){
    NODE* newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }
    newNode->next = head->next;
    head->next = newNode;
    newNode->prev = head;
    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}

void insertAtEnd(NODE* head, int data){
    NODE* newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }
    NODE* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAtBeginning(NODE* head){
    if (head->next == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE* temp = head->next;
    head->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = head;
    }
    free(temp);
}

void deleteAtEnd(NODE* head){
    if (head->next == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    NODE* lastNode = temp->next;
    temp->next = NULL;
    free(lastNode);
}

void display(NODE* head){
    if (head->next == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE* temp = head->next;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    NODE* head = createNode(0);
    if (head == NULL) {
        return -1;
    }
    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    display(head);
    deleteAtBeginning(head);
    deleteAtEnd(head);
    display(head);
    return 0;
}