#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10

typedef struct {
    char title[100];
    char author[50];
    float price;
} Book;

void AddBook(Book** inventory, int* capacity, int* count) {
    if (*count == *capacity) {
        *capacity *= 2;
        *inventory = realloc(*inventory, *capacity * sizeof(Book));
    }

    Book newBook;
    printf("Enter the title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0';

    printf("Enter the author: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';

    printf("Enter the price: ");
    scanf("%f", &newBook.price);
    getchar(); // consume the newline character

    (*inventory)[*count] = newBook;
    (*count)++;
}

void DisplayInventory(Book* inventory, int count) {
    if (count == 0) {
        printf("-1\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%s %s %.2f\n", inventory[i].title, inventory[i].author, inventory[i].price);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // consume the newline character

    Book* inventory = malloc(INITIAL_CAPACITY * sizeof(Book));
    int capacity = INITIAL_CAPACITY;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int operation;
        scanf("%d", &operation);
        getchar(); // consume the newline character

        if (operation == 1) {
            AddBook(&inventory, &capacity, &count);
        } else if (operation == 2) {
            DisplayInventory(inventory, count);
        }
    }

    free(inventory);

    return 0;
}