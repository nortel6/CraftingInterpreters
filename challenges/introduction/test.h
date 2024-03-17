#ifndef TEST_H
#define TEST_H

#include "list.h"

typedef struct {
    int value;
} Data;

void fillList(List* list, int rawData[], int size);
void printData(void* data);
void freeData(void* data);
#endif