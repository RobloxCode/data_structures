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
 * - 3: Item not found
 */

#ifndef INTLIST_H
#define INTLIST_H

#include <stddef.h>  // for size_t

/**
 * @struct IntNode
 * @brief A single node of the integer linked list.
 *
 * Each node stores:
 * - `val`: The integer value of the node.
 * - `next`: Pointer to the next node in the list (or NULL if end of list).
 */
typedef struct IntNode {
    int val;                 /**< Integer value stored in the node. */
    struct IntNode* next;    /**< Pointer to the next node, or NULL. */
} IntNode;

/**
 * @struct IntList
 * @brief The integer linked list container.
 *
 * Stores:
 * - `len`: The number of nodes in the list.
 * - `start`: Pointer to the first node in the list.
 */
typedef struct {
    size_t len;      /**< Number of nodes currently in the list. */
    IntNode* start;  /**< Pointer to the first node, or NULL if empty. */
} IntList;

/**
 * @brief Create a new integer list with a given initial size.
 *
 * Allocates memory for the list and the requested number of nodes,
 * initializing all node values to 0.
 *
 * @param init_size Initial number of nodes to create.
 * @return Pointer to the newly created IntList, or NULL on allocation failure.
 */
IntList* list_make(const size_t init_size);

/**
 * @brief Free all memory associated with an IntList.
 *
 * Frees all nodes and then the list container itself.
 *
 * @param lst Pointer to the list to free.
 * @return 0 on success, 1 if lst is NULL.
 */
int list_free(IntList* lst);

/**
 * @brief Remove an element at a given index.
 *
 * Adjusts the list to remove the element and updates length.
 *
 * @param lst Pointer to the list.
 * @param idx Index of the element to remove (0-based).
 * @return Status code (0 success, 1 NULL pointer, 2 index out of bounds).
 */
int list_remove(IntList* lst, const size_t idx);

/**
 * @brief Set the value of an element at a given index.
 *
 * @param lst Pointer to the list.
 * @param idx Index of the element to update (0-based).
 * @param new_val New integer value to set.
 * @return Status code (0 success, 1 NULL pointer, 2 index out of bounds).
 */
int list_set_value(IntList* lst, const size_t idx, const int new_val);

/**
 * @brief Print the list to stdout in [ val1 val2 ... ] format.
 *
 * @param lst Pointer to the list.
 * @return 0 on success, 1 if lst is NULL.
 */
int list_print(const IntList* lst);

/**
 * @brief stores the item at a given index in a given output variable
 *
 * @param lst Poitner to the list
 * @param idx Index of the element to store
 * @param out pointer to the variable where the element will be stored
 */
int list_get_val(const IntList* lst, const size_t idx, int* out);

/**
 * @brief searches the index of a given value
 *
 * @param lst Poitner to the list
 * @param target value to search for in the list
 * @param out pointer to the variable where the index if find will be stored
 * @return Status code (0 success, 1 NULL pointer, 2 index out of bounds, 3 not found value).
 */
int list_search(const IntList* lst, const int target, size_t* out);

/**
 * @brief reverses the list by shifting the pointers of the list
 *
 * @param lst Poitner to the list
 */
int list_reverse(IntList* lst);

/**
 * @brief adds a node at the end of the list
 *
 * @param lst Poitner to the list
 * @param val Value to add at the end of the list
 */
int list_append(IntList* lst, int val);

/**
 * @brief returns the size of the list
 *
 * @param lst Poitner to the list
 */
size_t list_len(const IntList* lst);

int list_swap_values(IntList* lst, size_t idx1, size_t idx2);

int list_sort(IntList* lst);

#endif // INTLIST_H
