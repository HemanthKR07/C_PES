#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>

typedef struct node
{
    struct node* prev;
    int info;
    struct node* next;
} NODE;

typedef struct dlist
{
    NODE *head;
} DLIST;

void initList(DLIST *pdl);
void insertLast(DLIST *pdl, int ele);
void display(DLIST *pdl);
void freeList(DLIST *pdl);
void deleteAtPos(DLIST *pdl, int *pe, int pos);
int countNodes(DLIST *pdl);
NODE* getNode(int ele);
void edits(DLIST *pdl);

int main()
{
    DLIST lobj;
    initList(&lobj);
    int n, ele;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ele);
        insertLast(&lobj, ele);
    }
  // Apply edits function
    edits(&lobj);

    display(&lobj);
     freeList(&lobj);
    return 0;
}

// Edits function that modifies the list based on multiples of 10
void edits(DLIST *pdl)
{
    bool reachedEnd=false;
    NODE* currentNode = pdl->head;
    while (!reachedEnd){
        if(currentNode->info%10==0){
            if(currentNode!=pdl->head){
                currentNode->prev->info++;
            }
            if(currentNode->next!=NULL){
                currentNode->next = currentNode->next->next;
                if (currentNode->next != NULL){
                    free(currentNode->next->prev);
                    currentNode->next->prev = currentNode;
                }
            }
        }
        if(currentNode->next==NULL){
            reachedEnd=true;
        }else{
            currentNode=currentNode->next;
        }
    }
}

void initList(DLIST *pdl)
{
    pdl->head = NULL;
}

NODE *getNode(int ele)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->prev = NULL;
    temp->info = ele;
    temp->next = NULL;
    return temp;
}

void insertLast(DLIST *pdl, int ele)
{
    NODE *temp = getNode(ele);
    if (pdl->head == NULL)
    {
        pdl->head = temp;
    }
    else
    {
        NODE *p = pdl->head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
}

void display(DLIST *pdl)
{
    NODE *p = pdl->head;
    if (p == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        while (p != NULL)
        {
            printf("%d ", p->info);
            p = p->next;
        }
        printf("\n");
    }
}
void freeList(DLIST *pdl)
{
    NODE *p = pdl->head;
    NODE *q = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    pdl->head = NULL;
}