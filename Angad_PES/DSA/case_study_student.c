#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char name[50];
    char text[50];
    struct node *prev;
    struct node *next;
}chat;

chat* addchat(chat* headp, chat* head, char *n, char *t) {
    chat* newChat = (chat*)malloc(sizeof(chat));
    strcpy(newChat->name, n);
    strcpy(newChat->text, t);
    newChat->prev = NULL;
    newChat->next = NULL;

    if (head == NULL) {
        head = newChat;
    } else {
        chat* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newChat;
        newChat->prev = current;
    }

    if (headp == NULL) {
        headp = newChat;
    }

    return head;
}

void pinchat(chat** headp, chat** head, chat* p) {
    if (*headp == NULL) {
        *headp = p;
        *head = p;
    } else {
        chat* current = *headp;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = p;
        p->prev = current;
        p->next = NULL;
        *head = p;
    }
}

void unpin(chat** headp, chat** head, chat* p) {
    if (p == *headp) {
        *headp = p->next;
        if (*headp != NULL) {
            (*headp)->prev = NULL;
        }
    } else {
        chat* prevChat = p->prev;
        chat* nextChat = p->next;
        prevChat->next = nextChat;
        if (nextChat != NULL) {
            nextChat->prev = prevChat;
        }
    }

    p->prev = NULL;
    p->next = *head;
    if (*head != NULL) {
        (*head)->prev = p;
    }
    *head = p;
}

int main()
{
    chat* head=NULL;
    chat* headp=NULL;
    int out=0;
    printf("***************************************************************\n");
    printf("YOUR CHAT MESSENGER\n");
    printf("***************************************************************\n");

    while(out==0)
    {
        printf("Pick your action:\n");
        printf("To DISPLAY all chats enter 0\n");
        printf("To ADD a chat enter 1\n");
        printf("To PIN a chat print 2\n");
        printf("To UNPIN a chat enter 3\n");
        int op=0; //takes an option
        printf("Enter option:");
        scanf("%d",&op);
        if(op==1)
        {
            char n[50]="";
            char t[50]="";
            printf("Enter name:");
            getchar();
            scanf("%[^\n]s",&n);
            getchar();
            printf("Enter text:");
            scanf("%[^\n]s",&t);
            head=addchat(headp,head,n,t);
        }
        else if(op==2)
        {
            printf("Enter name of contact from unpinned chats:\n");
            getchar();
            char cont[50]="";
            disp(headp,head);
            scanf("%[^\n]s",&cont);
            chat *p=head;
            while(strcmp(p->name,cont)!=0)
            {
                p=p->next;
            }

            pinchat(&headp,&head,p);
        }

        else if(op==3)
        {
            printf("From the pinned chats enter a chat that you want to unpin\n");
            disp(headp,head);
            char in[50]="";
            getchar();
            scanf("%[^\n]s",&in);
            chat* point2=headp;
            while(strcmp(point2->name,in)!=0)
            {
                point2=point2->next;
            }
            unpin(&headp,&head,point2);
        }
        else if(op==0)
        {
            disp(headp,head);
        }
        else
        {
            printf("Wrong Input\n");
        }
    }
}