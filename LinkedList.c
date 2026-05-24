#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

LinkedList* LinkedList_create() {
    LinkedList* L = malloc(sizeof(LinkedList));
    if (!L) {
        return NULL;
    }

    L->size = 0;
    L->head = NULL;

    return L;
}

Node* search(LinkedList* L, int key) {
    if (!L) {
        return NULL;
    }

    Node* current = L->head;
    while(current != NULL) {
        if (current->key == key) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

void add(LinkedList* L, int key, int value) {
    if (!L) {
        return;
    }

    Node* n = malloc(sizeof(Node));
    if (!n) {
        return;
    }

    n->key = key;
    n->value = value;
    n->next = NULL;

    if (L->head == NULL) {
        L->head = n;
        L->size++;
        return;
    }

    Node* current = L->head;

    while(current->next != NULL) {
        current = current->next;
    }

    current->next = n;
    L->size++;
}

void delete_key(LinkedList* L, int key) {
    if (!L) {
        return;
    }

    Node* current = L->head;
    Node* prev = current;
    while(current != NULL) {
        if (current->key == key && current == prev) { // If the first node is the key that we're looking for
            L->head = current->next;
            L->size--;
            free(current);
            return;
        } 
        else if (current->key == key) {
            prev->next = current->next;
            L->size--;
            free(current);
            return;
        }

        if (current == prev) {
            current = current->next;
        } 
        else {
            prev = current;
            current = current->next;
        }
    }
}

void delete_table(LinkedList* L) {
    if (!L) {
        return;
    }

    Node* current = L->head;
    while(current != NULL) {
        Node* to_delete = current;
        current = current->next;
        free(to_delete);
    }

    free(L);
    L = NULL;
}

void print_list(LinkedList* L) {
    if (!L) {
        printf("List is NULL\n");
        return;
    }

    printf("List (size=%d): ", L->size);

    Node* current = L->head;

    while (current != NULL) {
        printf("(%d -> %d) ", current->key, current->value);
        current = current->next;
    }

    printf("\n");
}
