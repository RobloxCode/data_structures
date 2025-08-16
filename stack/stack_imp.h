#ifndef STACK_IMP_H
#define STACK_IMP_H

typedef struct IntNode {
    int val;
    struct IntNode* next;
} IntNode;

IntNode* stack_make();

#endif
