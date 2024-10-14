#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct node
{
    int info;
    struct node* left;
    struct node* right;
}NODE;

typedef struct tree
{
	NODE *root;
}TREE;

//Initializes the Binary Search Tree to be empty
void initTree(TREE *pt){
    pt->root = NULL;
}

//Creates Binary Search Tree
void constructTree(TREE *pt, int ele) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->info = ele;
    newNode->left = newNode->right = NULL;

    if (pt->root == NULL) {
        pt->root = newNode;
        return;
    }

    NODE *cur = pt->root;
    NODE *parent = NULL;

    while (cur != NULL) {
        parent = cur;
        if (ele < cur->info) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    if (ele < parent->info) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

//Prints the Binary Search tree in level order
void levelOrder(TREE *pt){
    NODE* queue[MAX];
    int front = -1, rear = -1;
    NODE *temp = pt->root;
    if (temp == NULL) {
        return;
    }
    queue[++rear] = temp;
    while (front != rear) {
        temp = queue[++front];
        printf("%d ", temp->info);
        if (temp->left != NULL) {
            queue[++rear] = temp->left;
        }
        if (temp->right != NULL) {
            queue[++rear] = temp->right;
        }
    }
}
// Destroys all nodes in a Binary search tree and sets root = NULL
void destroyTree(TREE *pt){
    NODE* queue[MAX];
    int front = -1, rear = -1;
    NODE *temp = pt->root;
    if (temp == NULL) {
        return;
    }
    queue[++rear] = temp;
    while (front != rear) {
        temp = queue[++front];
        if (temp->left != NULL) {
            queue[++rear] = temp->left;
        }
        if (temp->right != NULL) {
            queue[++rear] = temp->right;
        }
        free(temp);
    }
}

int main()
{
    TREE tobj;
    initTree(&tobj);
	
    int n;
    int ele;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ele);
        constructTree(&tobj,ele);
    }
	
    levelOrder(&tobj);
	
    destroyTree(&tobj);
    
    return 0;
}