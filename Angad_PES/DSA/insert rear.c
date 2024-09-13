#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void insertRear(Queue *queue, int element) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue is full. Insertion failed.\n");
        return;
    }

    queue->rear++;
    queue->data[queue->rear] = element;
    printf("Element %d inserted at the rear of the queue.\n", element);
}

void displayQueue(Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements in the queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int dequeueRear(Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty. Deletion failed.\n");
        return -1;
    }

    int element = queue->data[queue->rear];
    queue->rear--;

    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }

    printf("Element %d dequeued from the rear of the queue.\n", element);
    return element;
}

int dequeueFront(Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty. Deletion failed.\n");
        return -1;
    }

    int element = queue->data[queue->front];
    queue->front++;

    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }

    printf("Element %d dequeued from the front of the queue.\n", element);
    return element;
}

int main() {
    Queue queue;
    queue.front = -1;
    queue.rear = -1;

    insertRear(&queue, 10);
    insertRear(&queue, 20);
    insertRear(&queue, 30);
    insertRear(&queue, 40);
    insertRear(&queue, 50);

    displayQueue(&queue);

    dequeueFront(&queue);
    displayQueue(&queue);
    dequeueRear(&queue);
    displayQueue(&queue);

    return 0;
}