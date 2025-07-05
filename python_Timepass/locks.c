#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    pthread_mutex_t lock;
} LinkedList;

void init_list(LinkedList *list) {
    list->head = NULL;
    pthread_mutex_init(&list->lock, NULL);
    printf("List initialized.\n");
}

void insert(LinkedList *list, int value) {
    pthread_mutex_lock(&list->lock);
    printf("Inserting value %d into the list.\n", value);

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = list->head;
    list->head = new_node;

    printf("Value %d inserted. Current head: %d\n", value, list->head->data);
    pthread_mutex_unlock(&list->lock);
}

void recursive_free(Node *node) {
    if (node == NULL) return;
    recursive_free(node->next);  // Recursively free the next node
    free(node);  // Free the current node
    printf("Node freed.\n");
}

void delete_all(LinkedList *list) {
    pthread_mutex_lock(&list->lock);
    printf("Deleting all nodes from the list.\n");

    recursive_free(list->head);  // No need to pass the lock here
    list->head = NULL;

    printf("All nodes deleted. List is now empty.\n");
    pthread_mutex_unlock(&list->lock);
}

void *thread_func(void *arg) {
    LinkedList *list = (LinkedList *)arg;
    printf("Thread started.\n");

    for (int i = 0; i < 100; i++) {
        insert(list, i);
    }

    delete_all(list);
    printf("Thread finished.\n");
    return NULL;
}

int main() {
    LinkedList list;
    init_list(&list);

    pthread_t t1, t2;
    printf("Creating thread 1.\n");
    pthread_create(&t1, NULL, thread_func, &list);
    printf("Creating thread 2.\n");
    pthread_create(&t2, NULL, thread_func, &list);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads finished.\n");
    pthread_mutex_destroy(&list.lock);
    printf("Mutex destroyed and program terminated.\n");

    return 0;
}
