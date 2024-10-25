#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file{
    char name[255];     // name of file
    struct file* next;
};

struct dir{
    char name[255];             // name of the directory
    struct dir* subdirectories; // child directories
    struct file* files;         // head pointer to a linked list of files
    struct dir* next;           // sibling directory
    struct dir* parent;         // parent directory
};

struct dirPtr{
    struct dir* activeDirectory; // pointer to the root directory
};

struct dirPtr* filePointer;

int makeDirectory(char dirName[]){
    struct dir* currentDir = filePointer->activeDirectory->subdirectories;
    while (currentDir != NULL) {
        if (strcmp(currentDir->name, dirName) == 0) {
            return -1;
        }
        currentDir = currentDir->next;
    }
    struct dir* newDir = (struct dir*)malloc(sizeof(struct dir));
    strcpy(newDir->name, dirName);
    newDir->subdirectories = NULL;
    newDir->files = NULL;
    newDir->next = NULL;
    newDir->parent = filePointer->activeDirectory;
    if (filePointer->activeDirectory->subdirectories == NULL) {
        filePointer->activeDirectory->subdirectories = newDir;
    } else {
        currentDir = filePointer->activeDirectory->subdirectories;
        while (currentDir->next != NULL) {
            currentDir = currentDir->next;
        }
        currentDir->next = newDir;
    }
    return 0;
}; // mkdir

int createFile(char fileName[255]){
    struct file* temp = filePointer->activeDirectory->files;
    while (temp != NULL) {
        if (strcmp(temp->name, fileName) == 0) {
            return -1;
        }
        temp = temp->next;
    }
    struct file* newFile = (struct file*)malloc(sizeof(struct file));
    strcpy(newFile->name, fileName);
    newFile->next = NULL;
    if (filePointer->activeDirectory->files == NULL) {
        filePointer->activeDirectory->files = newFile;
    } else {
        temp = filePointer->activeDirectory->files;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newFile;
    }
    return 0;
}; // touch

int printList(){
    struct file* tempFile = filePointer->activeDirectory->files;
    while (tempFile != NULL) {
        printf("%s\n", tempFile->name);
        tempFile = tempFile->next;
    }

    struct dir* tempDir = filePointer->activeDirectory->subdirectories;
    while (tempDir != NULL) {
        printf("%s/\n", tempDir->name);
        tempDir = tempDir->next;
    }
    return 0;
}; // ls

int changeDirectory(char dirName[255]){
    if (strcmp(dirName, "..") == 0) {
        if (filePointer->activeDirectory->parent == NULL) {
            return -1;
        }
        filePointer->activeDirectory = filePointer->activeDirectory->parent;
        return 0;
    }
    struct dir* temp = filePointer->activeDirectory->subdirectories;
    while (temp != NULL) {
        if (strcmp(temp->name, dirName) == 0) {
            filePointer->activeDirectory = temp;
            return 0;
        }
        temp = temp->next;
    }
    return -1;
}; // cd

void printDirectoryContentsRecursively(struct dir* directory, int depth) {
    struct file* tempFile = directory->files;
    while (tempFile != NULL) {
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("%s\n", tempFile->name);
        tempFile = tempFile->next;
    }

    struct dir* tempDir = directory->subdirectories;
    while (tempDir != NULL) {
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("%s/\n", tempDir->name);
        printDirectoryContentsRecursively(tempDir, depth + 1);
        tempDir = tempDir->next;
    }
}

int recursivePrint() {
    printDirectoryContentsRecursively(filePointer->activeDirectory, 0);
    return 0;
}

int runCommand(char command[300]){
    char cmd[10];
    char arg[255];
    int numArgs = sscanf(command, "%s %s", cmd, arg);

    if (numArgs < 1) {
        return -1;
    }

    if (strcmp(cmd, "mkdir") == 0) {
        if (numArgs == 2) {
            return makeDirectory(arg);
        } else {
            return -1;
        }
    } else if (strcmp(cmd, "touch") == 0) {
        if (numArgs == 2) {
            return createFile(arg);
        } else {
            return -1;
        }
    } else if (strcmp(cmd, "ls") == 0) {
        return printList();
    } else if (strcmp(cmd, "cd") == 0) {
        if (numArgs == 2) {
            return changeDirectory(arg);
        } else {
            return -1;
        }
    } else if (strcmp(cmd, "print")==0){
        return recursivePrint();
    } else {
        return -1;
    }
};

int main(){
    struct dirPtr* root = (struct dirPtr*)malloc(sizeof(struct dirPtr));
    root->activeDirectory = (struct dir*)malloc(sizeof(struct dir));
    strcpy(root->activeDirectory->name, "");
    filePointer = root;

    FILE *pastFile = fopen("past.txt", "r");
    if (pastFile != NULL) {
        char pastCommand[300];
        while (fgets(pastCommand, sizeof(pastCommand), pastFile)) {
            pastCommand[strcspn(pastCommand, "\n")] = 0;
            runCommand(pastCommand);
        }
        fclose(pastFile);
    }

    filePointer = root;

    while (true) {
        char command[300];
        printf(">> ");
        fgets(command, 300, stdin);
        command[strcspn(command, "\n")] = 0;
        if (strcmp(command, "exit") == 0) {
            break;
        }
        if (runCommand(command) != 0) {
            printf("Invalid command\n");
        } else {
            pastFile = fopen("past.txt", "a");
            if (pastFile != NULL) {
                fprintf(pastFile, "%s\n", command);
                fclose(pastFile);
            }
        }
    }
    return 0;
}