#ifndef LIST_H
#define LIST_H

typedef struct Node {
    struct Node* prev;
    struct Node* next;
    void* value;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int length;
} List;

List* createList();
void insertStart(List* list, void* value);
void* removeStart(List* list);
void insertLast(List* list, void* value);
void* removeLast(List* list);
void print(char *msg);

typedef void (*listFunc)(void* value);
void printList(List* list, listFunc func);
void printListReverse(List* list, listFunc func);
void freeList(List* list, listFunc func);

#endif