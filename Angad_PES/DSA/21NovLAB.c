#include <stdio.h>

#define EMPTY -1

int h1(int k, int m) {
    return (2 * k + 3) % m;
}

int h2(int k, int m) {
    return (3 * k + 1) % m;
}

void insert(int hashTable[], int m, int key) {
    int index = h1(key, m);
    int step = h2(key, m);
    int i = 0;

    while (hashTable[index] != EMPTY && i < m) {
        index = (index + step) % m;
        i++;
    }

    if (i < m) {
        hashTable[index] = key;
    }
}

void printHashTable(int hashTable[], int m) {
    for (int i = 0; i < m; i++) {
        if (hashTable[i] == EMPTY) {
            printf("-1\n");
        } else {
            printf("%d\n", hashTable[i]);
        }
    }
}

int main() {
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);

    int hashTable[m];
    for (int i = 0; i < m; i++) {
        hashTable[i] = EMPTY;
    }

    for (int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);
        insert(hashTable, m, key);
    }

    printHashTable(hashTable, m);

    return 0;
}