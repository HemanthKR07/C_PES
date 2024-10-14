#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node* left;
    struct node* right;
}NODE;

NODE* constructTree(NODE *root,int ele);
NODE* findLCA(NODE* root, int n1, int n2,NODE* prev);
NODE* destroyTree(NODE* root);

int main()
{
NODE *root=NULL;
	
    int n;
    scanf("%d",&n);
    	
    for(int i=0;i<n;i++)
    {
        int ele;
        scanf("%d",&ele);
		root=constructTree(root,ele);
    }
	
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    NODE* lca=findLCA(root,n1,n2,root);
    printf("%d",lca->info);
    destroyTree(root);
    return 0;
}

NODE* constructTree(NODE *root,int ele)
{
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->info = ele;
    node->left = NULL;
    node->right = NULL;
	
    if(root == NULL)
    {
        root = node;
    }
    else
    {
        NODE* p = root;
        NODE* q= NULL;
        while(p!=NULL)
        {
            if(node->info < p->info)
            {
                q=p;
                p = p->left;
            }
            else
            {
                q=p;
                p = p->right;
            }
        }
        if(node->info < q->info)
        {
            q->left = node;
        }
        else
        {
            q->right = node;
        }
    }
	return root;
}

NODE* destroyTree(NODE* root) 
{
    if (root != NULL) 
    {
        root->left=destroyTree(root->left);
        root->right=destroyTree(root->right);
//		printf("Freed %d\n",root->info);
        free(root);
    }
	return NULL;
}

NODE* findLCA(NODE* root, int n1, int n2, NODE* prev) 
{
    if (root == NULL) 
        return NULL;

    if (root->info == n1 || root->info == n2)
        return root;

    if (root->info > n1 && root->info > n2)
        return findLCA(root->left, n1, n2, root);

    if (root->info < n1 && root->info < n2)
        return findLCA(root->right, n1, n2, root);

    return root;
}