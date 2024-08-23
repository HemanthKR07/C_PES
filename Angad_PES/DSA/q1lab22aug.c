#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct node
{
    int coeff;
    int pow;
    struct node* next;
}node;

void input(node** head,node** tail,int n);
node* sum(node* head1,node* head2);
int eval(node* head,int x);
void destroy(node **head);

int main()
{
    int m=0;
    int n=0;
    node* head1=NULL;
    node* head2=NULL;
    node* tail1=NULL;
    node* tail2=NULL;
    int x=0;
    scanf("%d %d",&m,&n);
    scanf("%d",&x);
    input(&head1,&tail1,m);
    input(&head2,&tail2,n);
    node *headres=sum(head1,head2);
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

void input(node** head,node** tail,int n)
{
    int coeff=0;
    int pow=0;
    int i=0;

    for(i=0;i<n;i++)
    {
        scanf("%d %d",&coeff,&pow);
        node* newnode=(node*)malloc(sizeof(node));
        newnode->coeff=coeff;
        newnode->pow=pow;
        newnode->next=NULL;
        if(*head==NULL)
        {
            *head=newnode;
            *tail=newnode;
        }
        else
        {
            (*tail)->next=newnode;
            *tail=newnode;
        }
    }    
}
node* sum(node* head1,node* head2)
{

    node* headres=NULL;
    node* tailres=NULL;
    node* temp1=head1;
    node* temp2=head2;
    while(temp1!=NULL && temp2!=NULL)
    {
        node* newnode=(node*)malloc(sizeof(node));
        newnode->next=NULL;
        if(temp1->pow==temp2->pow)
        {
            newnode->coeff=temp1->coeff+temp2->coeff;
            newnode->pow=temp1->pow;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->pow>temp2->pow)
        {
            newnode->coeff=temp1->coeff;
            newnode->pow=temp1->pow;
            temp1=temp1->next;
        }
        else
        {
            newnode->coeff=temp2->coeff;
            newnode->pow=temp2->pow;
            temp2=temp2->next;
        }
        if(headres==NULL)
        {
            headres=newnode;
            tailres=newnode;
        }
        else
        {
            tailres->next=newnode;
            tailres=newnode;
        }
    }
    while(temp1!=NULL)
    {
        node* newnode=(node*)malloc(sizeof(node));
        newnode->coeff=temp1->coeff;
        newnode->pow=temp1->pow;
        newnode->next=NULL;
        if(headres==NULL)
        {
            headres=newnode;
            tailres=newnode;
        }
        else
        {
            tailres->next=newnode;
            tailres=newnode;
        }
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        node* newnode=(node*)malloc(sizeof(node));
        newnode->coeff=temp2->coeff;
        newnode->pow=temp2->pow;
        newnode->next=NULL;
        if(headres==NULL)
        {
            headres=newnode;
            tailres=newnode;
        }
        else
        {
            tailres->next=newnode;
            tailres=newnode;
        }
        temp2=temp2->next;
    }
    return headres;

}

int eval(node* head,int x)
{
    int res=0;
    node* temp=head;
    while(temp!=NULL)
    {
        res+=temp->coeff*pow(x,temp->pow);
        temp=temp->next;
    }
    return res;
}
void destroy(node **head)
{
    node* temp=*head;
    while(temp!=NULL)
    {
        node* temp1=temp;
        temp=temp->next;
        free(temp1);
    }
    *head=NULL;
}