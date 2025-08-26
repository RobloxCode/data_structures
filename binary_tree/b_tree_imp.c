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
    size_t _size;
} BinaryIntTree;

BinaryIntTree* BinaryTree_make() {
    BinaryIntTree* bst = malloc(sizeof(BinaryIntTree));
    if (bst == NULL) {
        return NULL;
    }

    bst->root = NULL;
    bst->_size = 0;
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

static IntNode* BinaryTree_remove_node(IntNode* root, int val, int* status) {
    if (root == NULL) {
        *status = 3;
        return NULL;
    }

    if (val < root->val) {
        root->left = BinaryTree_remove_node(root->left, val, status);
    } else if (val > root->val) {
        root->right = BinaryTree_remove_node(root->right, val, status);
    } else {
        *status = 0;

        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            IntNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            IntNode* temp = root->left;
            free(root);
            return temp;
        }
        else {
            IntNode* succ = root->right;
            while (succ->left != NULL) {
                succ = succ->left;
            }
            root->val = succ->val;
            root->right = BinaryTree_remove_node(root->right, succ->val, status);
        }
    }

    return root;
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
        bst->_size++;
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
                bst->_size++;
                return 0;
            }
            cur = cur->left;
        } else {
            if (cur->right == NULL) {
                cur->right = new;
                bst->_size++;
                return 0;
            }
            cur = cur->right;
        }
    }
}

int BinaryTree_remove(BinaryIntTree* bst, const int val) {
    if (bst == NULL) {
        return 1;
    }

    int status = 0;
    bst->root = BinaryTree_remove_node(bst->root, val, &status);
    if (status == 0) {
        bst->_size--;
    }
    return status;
}

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

int BinaryTree_size(const BinaryIntTree* bst, size_t* out) {
    if (bst == NULL || out == NULL) {
        return 1;
    }

    if (bst->root == NULL) {
        *out = 0;
        return 4;
    }

    *out = bst->_size;
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

