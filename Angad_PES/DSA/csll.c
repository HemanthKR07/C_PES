#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

void deleteAtPos(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* curr = *head;
    struct Node* prev = NULL;
    int count = 1;
    while (count != pos) {
        if (curr->next == *head) {
            printf("Position out of range!\n");
            return;
        }
        prev = curr;
        curr = curr->next;
        count++;
    }
    if (curr == *head && curr->next == *head) {
        *head = NULL;
        free(curr);
        return;
    }
    if (curr == *head) {
        prev = *head;
        while (prev->next != *head) {
            prev = prev->next;
        }
        *head = (*head)->next;
        prev->next = *head;
        free(curr);
    } else if (curr->next == *head) {
        prev->next = *head;
        free(curr);
    } else {
        prev->next = curr->next;
        free(curr);
    }
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* curr = *head;
    struct Node* prev = NULL;
    while (curr->next != *head) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == *head) {
        *head = NULL;
        free(curr);
    } else {
        prev->next = *head;
        free(curr);
    }
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* curr = *head;
    struct Node* prev = NULL;
    while (curr->data != key) {
        if (curr->next == *head) {
            printf("Node with key %d not found!\n", key);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    if (curr == *head && curr->next == *head) {
        *head = NULL;
        free(curr);
        return;
    }
    if (curr == *head) {
        prev = *head;
        while (prev->next != *head) {
            prev = prev->next;
        }
        *head = (*head)->next;
        prev->next = *head;
        free(curr);
    } else if (curr->next == *head) {
        prev->next = *head;
        free(curr);
    } else {
        prev->next = curr->next;
        free(curr);
    }
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void freeMemory(struct Node** head) {
    if (*head == NULL) {
        return;
    }
    struct Node* curr = *head;
    struct Node* next;
    while (curr->next != *head) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    free(curr);
    *head = NULL;
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);
    display(head);

    deleteNode(&head, 20);
    display(head);

    freeMemory(&head);

    return 0;
}
