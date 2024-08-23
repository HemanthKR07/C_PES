#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int info;
struct node* next;
}NODE;

NODE *createList(NODE *head,int ele);
NODE *getNode(int ele);
void display(NODE *head);
NODE *concat(NODE *head1,NODE *head2);
NODE *freeList(NODE *head);

int main()
{
NODE *head1=NULL;
NODE *head2=NULL;
int ele,n;
scanf("%d",&n);
for(int i=0;i<n;i++)
{
scanf("%d",&ele);
head1=createList(head1,ele);
}
scanf("%d",&n);
for(int i=0;i<n;i++)
{
scanf("%d",&ele);
head2=createList(head2,ele);
}
NODE *head3=concat(head1,head2);
display(head3);
freeList(head1);
// freeList(head2);
// freeList(head3);
return 0;

}


NODE *concat(NODE *head1, NODE *head2)
{
    if (head1 == NULL && head2 == NULL) {
        return NULL;
    }
    
    NODE *newHead = NULL;
    NODE *current = NULL;
    
    while (head1 != NULL || head2 != NULL) {
        if (head1 != NULL) {
            if (newHead == NULL) {
                newHead = head1;
                current = newHead;
            } else {
                current->next = head1;
                current = current->next;
            }
            head1 = head1->next;
        }
        
        if (head2 != NULL) {
            if (newHead == NULL) {
                newHead = head2;
                current = newHead;
            } else {
                current->next = head2;
                current = current->next;
            }
            head2 = head2->next;
        }
    }
    
    current->next = NULL;
    
    return newHead;
}


NODE *getNode(int ele)
{
NODE *temp=malloc(sizeof(NODE));
temp->info=ele;
temp->next=NULL;
return temp;
}

NODE *createList(NODE *head,int ele)
{
NODE *temp=getNode(ele);
if(head==NULL)
head=temp;
else{
NODE *p=head;
while(p->next!=NULL)
p=p->next;
p->next=temp;}
return head;
}

void display(NODE *head)
{
NODE *p=head;
if(p==NULL)
{
printf("empty list\n");
}
else
{
while(p!=NULL)
{
printf("%d ",p->info);
p=p->next;
}
printf("\n");
}
}



NODE *freeList(NODE *head)
{
NODE *p=head;
NODE *q=NULL;
while(p!=NULL)
{
q=p;
p=p->next;
free(q);
}
head=NULL;
return head;
}