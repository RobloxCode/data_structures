/**
 * @file b_tree_imp.h
 * @brief Simple binary tree implementation for integers.
 *
 * This library provides a basic binary tree for integers, with
 * operations to make, free, add elements and print.
 *
 * ## Status Codes:
 * - 0: No errors.
 * - 1: Wrong pointer (NULL pointer passed where a valid pointer is required).
 * - 2: Item already on the tree.
 * - 3: Item not found.
 */

#ifndef B_TREE_IMP_H
#define B_TREE_IMP_H

/**
 * @struct IntNode
 * @brief Represents a single node in the binary tree.
 *
 * Each node contains an integer value and pointers
 * to its left and right children.
 */
typedef struct IntNode {
    int val;               /**< Value stored in the node. */
    struct IntNode* left;  /**< Pointer to the left child node. */
    struct IntNode* right; /**< Pointer to the right child node. */
} IntNode;

/**
 * @struct BinaryIntTree
 * @brief Represents a binary tree of integers.
 *
 * This structure holds the root node of the tree.
 */
typedef struct BinaryIntTree {
    IntNode* root; /**< Pointer to the root node of the tree. */
} BinaryIntTree;

/**
 * @brief Creates an empty binary tree.
 *
 * @return Pointer to a newly created BinaryIntTree,
 *         or NULL if memory allocation fails.
 */
BinaryIntTree* BinaryTree_make();

/**
 * @brief Inserts a value into the binary tree.
 *
 * @param bst Pointer to the binary tree.
 * @param val The integer value to insert.
 * @return Status code:
 *         - 0: Success.
 *         - 1: Invalid tree pointer (NULL).
 *         - 2: Value already exists in the tree.
 */
int BinaryTree_add(BinaryIntTree* bst, const int val);

/**
 * @brief Prints the tree in preorder traversal.
 *
 * Traversal order: root -> left -> right.
 * Uses `*` to mark NULL pointers.
 *
 * @param cur_node Pointer to the current node.
 */
void BinaryTree_print_preorder(const IntNode* cur_node);

/**
 * @brief Prints the tree in preorder traversal.
 *
 * Traversal order: left -> right -> root.
 * Uses `*` to mark NULL pointers.
 *
 * @param cur_node Pointer to the current node.
 */
void BinaryTree_print_postorder(const IntNode* cur_node);

/**
 * @brief Prints the tree in preorder traversal.
 *
 * Traversal order: left -> root -> right.
 * Uses `*` to mark NULL pointers.
 *
 * @param cur_node Pointer to the current node.
 */
void BinaryTree_print_inorder(const IntNode* cur_node);

/**
 * @brief Frees all nodes in a subtree.
 *
 * @param node Pointer to the root of the subtree to free.
 */
static void BinaryTree_free_node(IntNode* node);

/**
 * @brief Frees the entire binary tree.
 *
 * @param bst Pointer to the binary tree.
 * @return Status code:
 *         - 0: Success.
 *         - 1: Invalid tree pointer (NULL).
 */
int BinaryTree_free(BinaryIntTree* bst);

static int BinaryTree_search_node(IntNode* node, int val);
int BinaryTree_search(const BinaryIntTree* bst, int val);

#endif
