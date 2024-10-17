#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX1 25
#define MAX2 100

typedef struct node
{
    char key[MAX1], value[MAX2];
    struct node *left, *right;
} NODE;

typedef struct tree
{
    NODE* root;
} TREE;

// Function to initialize the tree
void init(TREE* pt)
{
    pt->root = NULL;
}

// Function to create a new node
NODE* createNode(char word[MAX1], char meaning[MAX2])
{
    NODE* temp = malloc(sizeof(NODE));
    strcpy(temp->key, word);
    strcpy(temp->value, meaning);
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// BST: Recursive Insert
NODE* rinsert(NODE* r, NODE *temp)
{
    if (r == NULL)
        return temp;
    if (strcmp(temp->key, r->key) < 0)
        r->left = rinsert(r->left, temp);
    else if (strcmp(temp->key, r->key) > 0)
        r->right = rinsert(r->right, temp);
    return r;
}

void recInsert(TREE *pt, char word[MAX1], char meaning[MAX2])
{
    NODE *temp = createNode(word, meaning);
    pt->root = rinsert(pt->root, temp);
}

void inorder(NODE* r)
{
    if (r != NULL)
    {
        inorder(r->left);
        printf("%s,%s\n", r->key, r->value);
        inorder(r->right);
    }
}

NODE* findMin(NODE* r)
{
    while (r->left != NULL)
        r = r->left;
    return r;
}

NODE *delNode(NODE* r, char word[MAX1])
{
    if (r == NULL)
        return r;
    if (strcmp(word, r->key) < 0)
        r->left = delNode(r->left, word);
    else if (strcmp(word, r->key) > 0)
        r->right = delNode(r->right, word);
    else
    {
        if (r->left == NULL)
        {
            NODE* temp = r->right;
            free(r);
            return temp;
        }
        else if (r->right == NULL)
        {
            NODE* temp = r->left;
            free(r);
            return temp;
        }
        NODE* temp = findMin(r->right);
        strcpy(r->key, temp->key);
        strcpy(r->value, temp->value);
        r->right = delNode(r->right, temp->key);
    }
    return r;
}

// BST: Iterative search
int search(NODE* r, char word[MAX1])
{
    while (r != NULL)
    {
        int cmp = strcmp(word, r->key);
        if (cmp == 0)
            return 1;
        else if (cmp < 0)
            r = r->left;
        else
            r = r->right;
    }
    return 0;
}

void destroyNode(NODE *r)
{
    if (r != NULL)
    {
        destroyNode(r->left);
        destroyNode(r->right);
        free(r);
    }
}

void destroyTree(TREE *pt)
{
    if (pt->root != NULL)
    {
        destroyNode(pt->root);
        pt->root = NULL;
    }
}

int main()
{
    TREE tobj;
    init(&tobj);
    int num_operations;
    char word[MAX1], meaning[MAX2];
    int choice;
    
    scanf("%d", &num_operations);

    int search_results[num_operations];
    int search_index = 0;

    for (int i = 0; i < num_operations; i++)
    {
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                scanf("%s", word);
                fflush(stdin);
                scanf("%[^\n]", meaning);
                recInsert(&tobj, word, meaning);
                break;
            case 2:
                scanf("%s", word);
                tobj.root = delNode(tobj.root, word);
                break;
            case 3:
                scanf("%s", word);
                if (search(tobj.root, word))
                {
                    search_results[search_index++] = 1;
                }
                else
                {
                    search_results[search_index++] = 0;
                }
                break;
            default:
                printf("Invalid operation\n");
        }
    }

    printf("Inorder Traversal:\n");
    inorder(tobj.root);

    printf("\nSearch Results:\n");
    for (int i = 0; i < search_index; i++)
    {
        printf("%d ", search_results[i]);
    }
    printf("\n");

    destroyTree(&tobj);
    return 0;
}