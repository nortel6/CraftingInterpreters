#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List* createList() {
    List* list = (List*) malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

void insertStart(List* list, void* value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->prev = NULL;
    node->next = NULL;
    node->value = value;

    /*
    Head can only be null if there's no entry
    */
   if (list->head == NULL) {
        // If head is null, so is tail
        list->head = node;
        list->tail = node;
    } else {
        Node* head = list->head;

        // New node will be new head
        node->next = head;
        // Old head's prev is new node
        head->prev = node;
        // Update list's new head
        list->head = node;
    }
    list->length++;
}

void* removeStart(List* list) {
    Node* head = list->head;
    Node* next_head = head->next;
    void* value = head->value;

    // I can probably use length == 1 here as well
    // Or just... head == list->tail I guess
    if (next_head == NULL) {
        // If no more head, that means no more tail as well
        list->tail = NULL;
    } else {
        // If no more nodes, you cannot do this
        next_head->prev = NULL;
    }
    // New head
    list->head = next_head;
    list->length--;

    free(head);

    return value;
}

void insertLast(List* list, void* value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->prev = NULL;
    node->next = NULL;
    node->value = value;

    // Tail can only be null if there's no entry
    if (list->tail == NULL) {
        // If tail is null, so is head
        list->tail = node;
        list->head = node;
    } else {
        Node* tail = list->tail;

        // New node will be new tail
        node->prev = tail;
        // Old tail's next is new node
        tail->next = node;
        // Update list's new head
        list->tail = node;
    }
    list->length++;
}

void* removeLast(List* list) {
    Node* tail = list->tail;
    Node* next_tail = tail->prev;
    void* value = tail->value;

    // I can probably use length == 1 here as well
    // Or just... tail == list->head I guess
    if (next_tail == NULL) {
        // If no more tail, that means no more head as well
        list->head = NULL;
    } else {
        // If no more nodes, you cannot do this
        next_tail->next = NULL;
    }
    // New tail
    list->tail = next_tail;
    list->length--;

    free(tail);

    return value;
}

void printList(List* list, listFunc func) {
    Node *node;
    
    node = list->head;
    while (node != NULL) {
        func(node->value);
        node = node->next;
    }
}

void printListReverse(List* list, listFunc func) {
    Node *node;
    
    node = list->tail;
    while (node != NULL) {
        func(node->value);
        node = node->prev;
    }
}

void freeList(List* list, listFunc func) {
    Node *node, *next_node;
    
    node = list->head;
    while (node != NULL) {
        next_node = node->next;
        func(node->value);
        free(node);
        node = next_node;
    }
    
    free(list);
}

void print(char *msg) {
    printf("Printed with print(): %s", msg);
}
