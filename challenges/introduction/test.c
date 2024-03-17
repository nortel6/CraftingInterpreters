#include "test.h"
#include <stdio.h>
#include <stdlib.h>

void fillList(List* list, int rawData[], int size) {
    for (int i = 0; i < size; i++) {
        // Using Data struct to make things easier
        Data* data = (Data*) malloc(sizeof(Data));
        data->value = rawData[i];
        insertStart(list, data);
    }    
}

void printData(void* data) {
    printf("%d ", ((Data*) data)->value);
}

void freeData(void* data) {
    free((Data*) data);
}

/*
* Just some simple tests
*/
int main() {
    const int size = 5;
    int rawData[] = { 1, 2, 3, 4, 5 };

    printf("Creating list...\n");
    List* list = createList();

    printf("Filling data:\n");
    fillList(list, rawData, size);
    printf("\n");
    
    printf("Printing data:\n");
    printList(list, printData);
    printf("\n");
    printf("Printing data in reverse:\n");
    printListReverse(list, printData);
    printf("\n");

    printf("Remove start:\n");
    Data* start = removeStart(list);
    printf("Data removed: %d\n", start->value);
    printList(list, printData);
    free(start);
    printf("\n");

    printf("Remove Last:\n");
    Data* last = removeLast(list);
    printf("Data removed: %d\n", last->value);
    printList(list, printData);
    free(last);
    printf("\n");
    
    printf("Remove start:\n");
    Data* start2 = removeStart(list);
    printf("Data removed: %d\n", start2->value);
    printList(list, printData);
    free(start2);
    printf("\n");

    printf("Remove Last:\n");
    Data* last2 = removeLast(list);
    printf("Data removed: %d\n", last2->value);
    printList(list, printData);
    free(last2);
    printf("\n");

    if (list->head == list->tail && list->length == 1) {
        printf("Head == Tails\n");
        printf("Length: 1\n");
    } else {
        print("Test fails :(");
    }

    printf("Freeing data:\n");
    freeList(list, freeData);

    return 0;
}