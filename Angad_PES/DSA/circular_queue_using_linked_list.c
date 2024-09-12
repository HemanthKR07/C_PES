#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNewNode(int newinfo){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = newinfo;
    newNode -> next = NULL;
    return newNode;
}

int enqueue(struct node* head, int newinfo){
    struct node* newNode = createNewNode(newinfo);
    if(head == NULL){
        head = newNode;
        head -> next = head;
        return 1;
    }
    struct node* temp = head;
    while(temp -> next != head){
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> next = head;
    return 1;
}

int dequeue(struct node* head){
    if(head == NULL){
        printf("Queue is empty\n");
        return -1;
    }
    struct node* temp = head;
    while(temp -> next -> next != head){
        temp = temp -> next;
    }
    struct node* temp2 = temp -> next;
    temp -> next = head;
    free(temp2);
    return 1;
}

void display(struct node* head){
    if(head == NULL){
        printf("Queue is empty\n");
        return;
    }
    struct node* temp = head;
    while(temp -> next != head){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("%d\n", temp -> data);
}

int main(){
    struct node* head = NULL;
    return 0;
}