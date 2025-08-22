#include <stdbool.h>
#include "../b_tree_imp.h"
#include <stdio.h>

int main() {
    int status = 0;
    BinaryIntTree* bst = BinaryTree_make();
    if (bst == NULL) {
        return 1;
    }

    status = BinaryTree_add(bst, 5);
    if (status != 0) {
        printf("Status %d\n", status);
        BinaryTree_free(bst);
        return 1;
    }

    status = BinaryTree_add(bst, 3);
    if (status != 0) {
        printf("Status %d\n", status);
        BinaryTree_free(bst);
        return 1;
    }

    status = BinaryTree_add(bst, 7);
    if (status != 0) {
        printf("Status %d\n", status);
        BinaryTree_free(bst);
        return 1;
    }

    status = BinaryTree_add(bst, 1);
    if (status != 0) {
        printf("Status %d\n", status);
        BinaryTree_free(bst);
        return 1;
    }

    BinaryTree_print_preorder(bst->root);

    status = BinaryTree_search(bst, 1);
    if (status != 0) {
        printf("Status %d\n", status);
        BinaryTree_free(bst);
        return 1;
    } else {
        printf("\nfound item: %d\n", 1);
    }

    status = BinaryTree_free(bst);
    if (status != 0) {
        printf("Status %d\n", status);
        return 1;
    }

    return 0;
}
