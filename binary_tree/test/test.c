#include <stdbool.h>
#include "../b_tree_imp.h"
#include <stdio.h>

int main() {
    int status = 0;
    BinaryIntTree* bst = BinaryTree_make();
    if (bst == NULL) {
        return 1;
    }

    status = BinaryTree_add(bst, 7);
    if (status != 0) {
        printf("Status %d\n", status);
        BinaryTree_free(bst);
        return 1;
    }

    status = BinaryTree_add(bst, 5);
    if (status != 0) {
        printf("Status %d\n", status);
        BinaryTree_free(bst);
        return 1;
    }

    status = BinaryTree_add(bst, 9);
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

    status = BinaryTree_add(bst, 6);
    if (status != 0) {
        printf("Status %d\n", status);
        BinaryTree_free(bst);
        return 1;
    }

    status = BinaryTree_add(bst, 8);
    if (status != 0) {
        printf("Status %d\n", status);
        BinaryTree_free(bst);
        return 1;
    }

    status = BinaryTree_add(bst, 10);
    if (status != 0) {
        printf("Status %d\n", status);
        BinaryTree_free(bst);
        return 1;
    }

    BinaryTree_print_preorder(bst->root);

    status = BinaryTree_search(bst, 10);
    if (status != 0) {
        printf("Status %d\n", status);
        BinaryTree_free(bst);
        return 1;
    }

    if (status == 0) {
        printf("item 10 found\n");
    }

    int min = 0;
    status = BinaryTree_min(bst, &min);
    if (status != 0) {
        printf("Status %d\n", status);
        BinaryTree_free(bst);
        return 1;
    }
    printf("the minimun number of this tree is: %d\n", min);

    int max = 0;
    status = BinaryTree_max(bst, &max);
    if (status != 0) {
        printf("Status %d\n", status);
        BinaryTree_free(bst);
        return 1;
    }
    printf("the maximun number of this tree is: %d\n", max);

    status = BinaryTree_remove(bst, 10);
    if (status != 0) {
        printf("Status %d\n", status);
        BinaryTree_free(bst);
        return 1;
    }
    BinaryTree_print_preorder(bst->root);
    printf("\n10 removed\n");

    // status = BinaryTree_remove(bst, 10);
    // if (status != 0) {
    //     printf("Status %d\n", status);
    //     return 1;
    // }
    // BinaryTree_print_preorder(bst->root);
    // printf("\n10 removed\n");
    // STATUS 3 because 10 is not on the tree anymore

    status = BinaryTree_remove(bst, 7);
    if (status != 0) {
        printf("Status %d\n", status);
        BinaryTree_free(bst);
        return 1;
    }
    BinaryTree_print_preorder(bst->root);
    printf("\n7 removed\n");

    status = BinaryTree_remove(bst, 6);
    if (status != 0) {
        printf("Status %d\n", status);
        BinaryTree_free(bst);
        return 1;
    }
    BinaryTree_print_preorder(bst->root);
    printf("\n6 removed\n");

    status = BinaryTree_free(bst);
    if (status != 0) {
        printf("Status %d\n", status);
        return 1;
    }
    return 0;
}

