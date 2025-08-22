#include <stdio.h>
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

void BinaryTree_free_node(IntNode* node) {
    if (node == NULL) {
        return;
    }

    BinaryTree_free_node(node->left);
    BinaryTree_free_node(node->right);
    free(node);
}

int BinaryTree_free(BinaryIntTree* bst) {
    if (bst == NULL) {
        return 1;
    }

    BinaryTree_free_node(bst->root);
    free(bst);
    return 0;
}

int BinaryTree_add(BinaryIntTree* bst, int val) {
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

