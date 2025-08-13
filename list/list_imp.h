#ifndef LIST_IMP_H
#define LIST_IMP_H

#include <stdlib.h>

typedef struct IntNode {
    int val;
    struct IntNode* next;
} IntNode;

typedef struct {
    size_t len;
    IntNode* start;
} IntList;

IntList*list_make(const size_t init_size);
int list_free(IntList* lst);
int list_print(IntList* lst);
int list_pop(IntList* lst, const size_t idx);
int list_set_value(IntList* lst, const size_t idx, const int new_val);

#endif

