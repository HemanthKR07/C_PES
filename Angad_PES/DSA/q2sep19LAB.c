void deleteNode(CircularLinkedList *list, Node *prev, Node *current) {
    if (list->head == NULL || current == NULL) {
        return;
    }

    if (current == list->head) {
        list->head = current->next;
    }
    if (current == list->tail) {
        list->tail = prev;
    }
    prev->next = current->next;
    free(current);
    list->size--;
}

void josephus(CircularLinkedList *list, int k) {
    if (list->head == NULL || k <= 0) {
        return;
    }

    Node *current = list->head;
    Node *prev = list->tail;

    while (list->size > 3) {
        for (int i = 1; i < k; i++) {
            prev = current;
            current = current->next;
        }
        Node *toDelete = current;
        current = current->next;
        deleteNode(list, prev, toDelete);
    }
}