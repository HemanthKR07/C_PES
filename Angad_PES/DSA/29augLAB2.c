#include <stdio.h>
#include <stdlib.h>

// Structure definition

typedef struct node {
    int val;
    struct node* next;
    struct node* prev;
} NODE;

NODE* InsertEnd(NODE* tail, int value) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->val = value;
    newNode->next = NULL;
    newNode->prev = tail;
    if (tail != NULL) {
        tail->next = newNode;
    }
    return newNode;
}

NODE* MergeTrains(NODE* list1, NODE* list2) {
    NODE* mergedList = NULL;
    NODE* tail = NULL;
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail = InsertEnd(tail, list1->val);
            list1 = list1->next;
        } else {
            tail = InsertEnd(tail, list2->val);
            list2 = list2->next;
        }
        if (mergedList == NULL) {
            mergedList = tail;
        }
    }
    while (list1 != NULL) {
        tail = InsertEnd(tail, list1->val);
        list1 = list1->next;
        if (mergedList == NULL) {
            mergedList = tail;
        }
    }
    while (list2 != NULL) {
        tail = InsertEnd(tail, list2->val);
        list2 = list2->next;
        if (mergedList == NULL) {
            mergedList = tail;
        }
    }
    return mergedList;
}

void PrintList(NODE* head) {
    NODE* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

NODE* FreeList(NODE* head) {
    NODE* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

int main() {
    NODE* list1 = NULL;
    NODE* tail1 = NULL;
    NODE* list2 = NULL;
    NODE* tail2 = NULL;
    int n1, n2, value;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        if (list1 == NULL) {
            list1 = tail1 = InsertEnd(NULL, value);
        } else {
            tail1 = InsertEnd(tail1, value);
        }
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        if (list2 == NULL) {
            list2 = tail2 = InsertEnd(NULL, value);
        } else {
            tail2 = InsertEnd(tail2, value);
        }
    }
    NODE* mergedtrain = MergeTrains(list1, list2);
  PrintList(mergedtrain);
   mergedtrain = FreeList(mergedtrain);

 return 0;
}