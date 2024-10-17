    #include <stdio.h>
    #include <stdlib.h>
    #include <limits.h>

    typedef struct node {
        int info;
        struct node* left;
        struct node* right;
    } NODE;

    NODE* constructTree(NODE *root, int *arr, int n);
    void inorderTraversal(NODE* root);
    int isBST(NODE* root, int min, int max);
    NODE* destroyNode(NODE* root);

    NODE* createNode(int info) {
        NODE* newNode = (NODE*)malloc(sizeof(NODE));
        newNode->info = info;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    NODE* insertLevelOrder(int *arr, NODE* root, int i, int n) {
        if (i < n) {
            NODE* temp = createNode(arr[i]);
            root = temp;

            root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
            root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
        }
        return root;
    }

    NODE* constructTree(NODE *root, int *arr, int n) {
        return insertLevelOrder(arr, root, 0, n);
    }

    void inorderTraversal(NODE* root) {
        if (root != NULL) {
            inorderTraversal(root->left);
            printf("%d ", root->info);
            inorderTraversal(root->right);
        }
    }

    int isBST(NODE* root, int min, int max) {
        if (root == NULL) return 1;
        if (root->info < min || root->info > max) return 0;
        return isBST(root->left, min, root->info - 1) && isBST(root->right, root->info + 1, max);
    }

    NODE* destroyNode(NODE* root) {
        if (root != NULL) {
            destroyNode(root->left);
            destroyNode(root->right);
            free(root);
        }
        return NULL;
    }

    int main() {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        NODE* root = NULL;
        root = constructTree(root, arr, n);

        inorderTraversal(root);
        printf("\n");

        if (isBST(root, INT_MIN, INT_MAX)) {
            printf("True\n");
        } else {
            printf("False\n");
        }

        root = destroyNode(root);
        return 0;
    }