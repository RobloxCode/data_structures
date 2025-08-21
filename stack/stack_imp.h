/**
 * @file stack_imp.h
 * @brief Simple singly linked stack implementation for integers.
 *
 * Provides a basic stack with push, pop, peek, print, create, and free.
 *
 * ## Status Codes:
 * - 0: No errors.
 * - 1: Null pointer passed where a valid pointer is required.
 * - 2: Operation not possible (e.g., pop/peek on empty stack).
 */

#ifndef STACK_H
#define STACK_H
#include <stddef.h>

/**
 * @struct IntNode
 * @brief A single node in the stack.
 */
typedef struct IntNode {
    int val;                 /**< Value stored at the node */
    struct IntNode* next;    /**< Pointer to the next node, or NULL */
} IntNode;

/**
 * @struct IntStack
 * @brief IntStack container.
 */
typedef struct {
    IntNode* top;    /**< Pointer to the top node */
    size_t len;      /**< Number of elements in the stack */
} IntStack;

/** Create a new empty stack. */
IntStack* stack_make();

/** Print stack contents as [ val1 val2 ... ]. */
int stack_print(const IntStack* s);

/** Free all nodes and the stack container. */
int stack_free(IntStack* s);

/** Push a value onto the stack. */
int stack_push(IntStack* s, int val);

/** Pop the top value into `out`. Returns 2 if the stack is empty. */
int stack_pop(IntStack* s, int* out);

/** Peek at the top value into `out` without removing it. Returns 2 if empty. */
int stack_peek(const IntStack* s, int* out);

#endif
