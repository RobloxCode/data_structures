/**
 * @file stack_imp.h
 * @brief Simple singly linked stack implementation for integers.
 *
 * Provides a basic stack with push, pop, peek, print, create, and free.
 *
 */

#ifndef STACK_H
#define STACK_H
#include <stddef.h>

/*
 * @enum stack_status_t
 * @brief An enum for a the possible return status 
 * of the stack implementation
*/
typedef enum {
    STACK_OK,
    STACK_NULL_PTR,
} stack_status_t;

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

/* Initializes a stack*/
stack_status_t stack_init(IntStack** s);

/** Print stack contents as [ val1 val2 ... ]. */
stack_status_t stack_print(IntStack* s);

/** Free all nodes and the stack container. */
stack_status_t stack_free(IntStack** s);

/** Push a value onto the stack. */
stack_status_t stack_push(IntStack* s, int val);

/** Pop the top value into `out`. Returns 2 if the stack is empty. */
stack_status_t stack_pop(IntStack* s, int* out);

/** Peek at the top value into `out` without removing it. Returns 2 if empty. */
stack_status_t stack_peek(IntStack* s, int* out);

#endif
