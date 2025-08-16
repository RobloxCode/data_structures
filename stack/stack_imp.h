/**
 * @file intlist.h
 * @brief Simple singly linked list implementation for integers.
 *
 * This library provides a basic linked list for integers, with
 * operations to create, free, remove elements, set values, and print.
 *
 * ## Status Codes:
 * - 0: No errors.
 * - 1: Wrong pointer (NULL pointer passed where a valid pointer is required).
 * - 2: Index out of bounds (idx >= list length).
 */

#ifndef STACK_IMP_H
#define STACK_IMP_H

#include <stddef.h>

typedef struct IntNode {
    int val;
    struct IntNode* next;
} IntNode;

typedef struct {
    IntNode* top;
    size_t len;
} Stack;

Stack* stack_make();
int stack_print(Stack* s);
int stack_free(Stack* s);
int stack_push(Stack* s, int val);
int stack_pop(Stack* s, int* out);
int stack_peek(Stack* s, int* out);

#endif
