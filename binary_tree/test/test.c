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
        return 1;
    }

    status = BinaryTree_add(bst, 3);
    if (status != 0) {
        printf("Status %d\n", status);
        return 1;
    }

    status = BinaryTree_add(bst, 7);
    if (status != 0) {
        printf("Status %d\n", status);
        return 1;
    }

    status = BinaryTree_add(bst, 1);
    if (status != 0) {
        printf("Status %d\n", status);
        return 1;
    }

    BinaryTree_print_preorder(bst->head);

    status = BinaryTree_free(bst);
    if (status != 0) {
        printf("Status %d\n", status);
        return 1;
    }

    return 0;
}
