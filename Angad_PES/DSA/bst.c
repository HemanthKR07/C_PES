//program to implement a binary search tree
#include<stdio.h>
#include<stdlib.h>
struct tnode
{
  int data;
  struct tnode *left;
  struct tnode *right;
};
typedef struct tnode tnode_t;

struct tree
{
	tnode_t *root;
};
typedef struct tree tree_t;

void init(tree_t*);
void inorder_t(tree_t*);
void inorder(tnode_t*);
void preorder(tnode_t*);
void preorder_t(tree_t *);
void postorder(tnode_t*);
void postorder_t(tree_t*);
void insert( tree_t *,int);
int count_t(tree_t *);
int count(tnode_t*);
int leafcount_t(tree_t *);
int leafcount(tnode_t*);
int height(tnode_t*);
int height_t(tree_t*);
void rinsert_t(tree_t*, int);
tnode_t *rinsert(tnode_t *, int);
void tdelete_t(tree_t*,int );

int search(tree_t *, int );
int rsearch_t(tree_t*, int );
int rsearch(tnode_t *, int);
int minimum(tree_t*);
int maximum(tree_t*);

void main()
{
	tree_t t;
	int ch,num,k,n;
	init(&t);
 
	while(1)
	{
		printf("\n1.Insert");
		printf("\n2.Preorder");   
		printf("\n3.Postorder");
		printf("\n4.Inorder");
		printf("\n5.No. of nodes");
		printf("\n6.No. of Leaf nodes");
		printf("\n7.Height of a tree");
		printf("\n8.delete a node");
		printf("\n9..recursively insert..");
		printf("\n10..search..");
		printf("\n11..search using recursion..");
		printf("\n13.find smallest");
		printf("\n14.find largest");
		printf("\n15..exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("Enter the element");
					scanf("%d",&num);
					insert(&t,num);
					break;
			case 2:	preorder_t(&t);
		            break; 
			case 3: postorder_t(&t);
					break;
			case 4:	inorder_t(&t);
					break;
			case 5: k=count_t(&t);
					printf("\nthe number of nodes=%d",k);
					break; 
			case 6: k=leafcount_t(&t);
					printf("\nthe number of nodes=%d",k);
					break;
			case 7: k=height_t(&t);
					printf("\nthe height of tree=%d",k);
					break;
			case 8:	printf("Enter the node to be deleted\n");
					scanf("%d",&num);
					tdelete_t(&t,num);
					break; 
			case 9:	printf("Enter the element");
					scanf("%d",&num);
					rinsert_t(&t,num);
					break;
			case 10:printf("Enter the element");
					scanf("%d",&num);
					int k=search(&t,num);
					if(k)
						printf("Key found\n");
					else
						printf("Not found..\n");
					break;
			case 11:printf("Enter the element");
					scanf("%d",&num);
					int m=rsearch_t(&t,num);
					if(m)
						printf("Key found\n");
					else
						printf("Not found..\n");
					break; 
			case 13:n=minimum(&t);
					printf("\nThe smallest element = %d\n",n);
					break;
			case 14:n=maximum(&t);
					printf("\nthe largest element = %d\n",n);
					break; 
			case 15:exit(0);
       }
    }
}    
  
  
void init(tree_t *t)
{
	t->root=NULL;
}
  
void insert(tree_t *t, int x)
{
	tnode_t *temp = (tnode_t*)malloc(sizeof(tnode_t));
	tnode_t *current, *parent;
	temp->data = x;
	temp->left = temp->right = NULL;

	if (t->root == NULL) {
		t->root = temp;
	} else {
		current = t->root;
		parent = NULL;
		while (1) {
			parent = current;
			if (x < parent->data) {
				current = current->left;
				if (current == NULL) {
					parent->left = temp;
					return;
				}
			} else {
				current = current->right;
				if (current == NULL) {
					parent->right = temp;
					return;
				}
			}
		}
	}
}

void preorder_t(tree_t *t)
{
	preorder(t->root);
}

void preorder(tnode_t *root)
{
	if (root != NULL) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder_t(tree_t *t)
{
	inorder(t->root);
}

void inorder(tnode_t *root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void postorder_t(tree_t *t)
{
	postorder(t->root);
}

void postorder(tnode_t *root)
{
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

int minimum(tree_t *t)
{
	tnode_t *current = t->root;
	while (current->left != NULL) {
		current = current->left;
	}
	return current->data;
}

int maximum(tree_t *t)
{
	tnode_t *current = t->root;
	while (current->right != NULL) {
		current = current->right;
	}
	return current->data;
}

int height_t(tree_t *t)
{
	return height(t->root);
}

int height(tnode_t *root)
{
	if (root == NULL) {
		return 0;
	} else {
		int leftHeight = height(root->left);
		int rightHeight = height(root->right);
		return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
	}
}

int leafcount_t(tree_t *t)
{
	return leafcount(t->root);
}

int leafcount(tnode_t *root)
{
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	} else {
		return leafcount(root->left) + leafcount(root->right);
	}
}

int count_t(tree_t* t)
{
	return count(t->root);
}

int count(tnode_t* root)
{
	if (root == NULL) {
		return 0;
	} else {
		return 1 + count(root->left) + count(root->right);
	}
}

void rinsert_t(tree_t *t, int key)
{
	t->root = rinsert(t->root, key);
}

tnode_t* rinsert(tnode_t *root, int key)
{
	if (root == NULL) {
		tnode_t *temp = (tnode_t*)malloc(sizeof(tnode_t));
		temp->data = key;
		temp->left = temp->right = NULL;
		return temp;
	}
	if (key < root->data) {
		root->left = rinsert(root->left, key);
	} else if (key > root->data) {
		root->right = rinsert(root->right, key);
	}
	return root;
}

int search(tree_t *t, int key)
{
	tnode_t *current = t->root;
	while (current != NULL) {
		if (key == current->data) {
			return 1;
		} else if (key < current->data) {
			current = current->left;
		} else {
			current = current->right;
		}
	}
	return 0;
}

int rsearch_t(tree_t *t, int key)
{
	return rsearch(t->root, key);
}

int rsearch(tnode_t *root, int key)
{
	if (root == NULL) {
		return 0;
	}
	if (key == root->data) {
		return 1;
	} else if (key < root->data) {
		return rsearch(root->left, key);
	} else {
		return rsearch(root->right, key);
	}
}

void tdelete_t(tree_t *t, int key)
{
	t->root = tdelete(t->root, key);
}

tnode_t* tdelete(tnode_t *root, int key)
{
	if (root == NULL) {
		return root;
	}
	if (key < root->data) {
		root->left = tdelete(root->left, key);
	} else if (key > root->data) {
		root->right = tdelete(root->right, key);
	} else {
		if (root->left == NULL) {
			tnode_t *temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			tnode_t *temp = root->left;
			free(root);
			return temp;
		}
		tnode_t *temp = minValueNode(root->right);
		root->data = temp->data;
		root->right = tdelete(root->right, temp->data);
	}
	return root;
}

tnode_t* minValueNode(tnode_t* node)
{
	tnode_t* current = node;
	while (current && current->left != NULL) {
		current = current->left;
	}
	return current;
}
