#ifndef LinkedList_H
#define LinkedList_H

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct LinkedList {
    int size;
    Node* head;
} LinkedList;

LinkedList* LinkedList_create();

Node* search(LinkedList* L, int key);
void add(LinkedList* L, int key, int value);
void delete_key(LinkedList* L, int key);
void delete_table(LinkedList* L);

void print_list(LinkedList* L);
#endif
