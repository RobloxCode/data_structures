#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct IntNode {
    int val;
    struct IntNode* left;
    struct IntNode* right;
} IntNode;

typedef struct BinaryIntTree {
    IntNode* root;
} BinaryIntTree;

BinaryIntTree* BinaryTree_make() {
    BinaryIntTree* bst = malloc(sizeof(BinaryIntTree));
    if (bst == NULL) {
        return NULL;
    }

    bst->root = NULL;
    return bst;
}

static void BinaryTree_free_node(IntNode* node) {
    if (node == NULL) {
        return;
    }

    BinaryTree_free_node(node->left);
    BinaryTree_free_node(node->right);
    free(node);
}

static int BinaryTree_search_node(IntNode* node, int val) {
    if (node == NULL) {
        return 1;
    }

    if (val == node->val) {
        return 0;
    } else if (val < node->val) {
        return BinaryTree_search_node(node->left, val);
    } else {
        return BinaryTree_search_node(node->right, val);
    }
}

int BinaryTree_free(BinaryIntTree* bst) {
    if (bst == NULL) {
        return 1;
    }

    BinaryTree_free_node(bst->root);
    free(bst);
    return 0;
}

int BinaryTree_search(const BinaryIntTree* bst, int val) {
    if (bst == NULL) {
        return 1;
    }
    return BinaryTree_search_node(bst->root, val);
}

int BinaryTree_add(BinaryIntTree* bst, const int val) {
    if (bst == NULL) {
        return 1;
    }

    IntNode* new = malloc(sizeof(IntNode));
    if (new == NULL) {
        return 1;
    }
    new->val = val;
    new->left = NULL;
    new->right = NULL;

    if (bst->root == NULL) {
        bst->root = new;
        return 0;
    }

    IntNode* cur = bst->root;
    for (;;) {
        if (val == cur->val) {
            free(new);
            return 2;
        } else if (val < cur->val) {
            if (cur->left == NULL) {
                cur->left = new;
                return 0;
            }
            cur = cur->left;
        } else {
            if (cur->right == NULL) {
                cur->right = new;
                return 0;
            }
            cur = cur->right;
        }
    }
}

// int BinaryTree_remove(BinaryIntTree* bst, const int val) {
//     if (bst == NULL) {
//         return 1;
//     }
//
//
//
// }

int BinaryTree_min(const BinaryIntTree* bst, int* out) {
    if (bst == NULL || out == NULL) {
        return 1;
    }

    IntNode* cur = bst->root;
    while (cur->left != NULL) {
        cur = cur->left;
    }

    *out = cur->val;
    return 0;
}

int BinaryTree_max(const BinaryIntTree* bst, int* out) {
    if (bst == NULL || out == NULL) {
        return 1;
    }

    IntNode* cur = bst->root;
    while (cur->right != NULL) {
        cur = cur->right;
    }

    *out = cur->val;
    return 0;
}

void BinaryTree_print_preorder(const IntNode* cur_node) {
    if (cur_node == NULL) {
        printf("* ");
        return;
    }

    printf("[ %d ", cur_node->val);
    BinaryTree_print_preorder(cur_node->left);
    BinaryTree_print_preorder(cur_node->right);
    printf("] ");
}

void BinaryTree_print_inorder(const IntNode* cur_node) {
    if (cur_node == NULL) {
        printf("* ");
        return;
    }

    printf("[ ");
    BinaryTree_print_inorder(cur_node->left);
    printf("%d ", cur_node->val);
    BinaryTree_print_inorder(cur_node->right);
    printf("] ");
}

void BinaryTree_print_postorder(const IntNode* cur_node) {
    if (cur_node == NULL) {
        printf("* ");
        return;
    }

    printf("[ ");
    BinaryTree_print_postorder(cur_node->left);
    BinaryTree_print_postorder(cur_node->right);
    printf("%d ", cur_node->val);
    printf("] ");
}

