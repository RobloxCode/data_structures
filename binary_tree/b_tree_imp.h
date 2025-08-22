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
 * - 2: Item already on the tree
 * - 3: Item not found
 */

#ifndef B_TREE_IMP_H
#define B_TREE_IMP_H

typedef struct IntNode {
    int val;
    struct IntNode* left;
    struct IntNode* right;
} IntNode;

typedef struct BinaryIntTree {
    IntNode* head;
} BinaryIntTree;

BinaryIntTree* BinaryTree_make();
int BinaryTree_add(BinaryIntTree* bst, int val);
void BinaryTree_print_preorder(const IntNode* cur_node);
void BinaryTree_free_node(IntNode* node);
int BinaryTree_free(BinaryIntTree* bst);

#endif
