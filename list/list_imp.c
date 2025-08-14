#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode {
    int val;
    struct IntNode* next;
} IntNode;

typedef struct {
    size_t len;
    IntNode* start;
} IntList;

IntList* list_make(const size_t init_size) {
    IntList* lst = malloc(sizeof(IntList));
    if (lst == NULL) return NULL;

    lst->len = 0;
    lst->start = NULL;

    IntNode* prev = NULL;
    for (size_t i = 0; i < init_size; ++i) {
        IntNode* node = malloc(sizeof(IntNode));
       if (node == NULL) {
            IntNode* cur = lst->start;
            while (cur != NULL) {
                IntNode* next = cur->next;
                free(cur);
                cur = next;
            }
            free(lst);
            return NULL;
        }

        node->val = 0;
        node->next = NULL;

        if (lst->start == NULL)
            lst->start = node;
        else
            prev->next = node;

        prev = node;
        lst->len++;
    }

    return lst;
}

int list_free(IntList* lst) {
    if (lst == NULL) return 1;

    IntNode* cur = lst->start;
    while (cur != NULL) {
        IntNode* next = cur->next;
        free(cur);
        cur = next;
    }

    free(lst);
    return 0;
}

int list_pop(IntList* lst, const size_t idx) {
    if (lst == NULL) return 1;
    if (idx >= lst->len) return 2;

    IntNode* to_delete;

    if (idx == 0) {
        to_delete = lst->start;
        lst->start = to_delete->next;
    } else {
        IntNode* cur = lst->start;
        for (size_t i = 0; i < idx - 1; ++i) {
            cur = cur->next;
        }
        to_delete = cur->next;
        cur->next = to_delete->next;
    }

    free(to_delete);
    lst->len--;
    return 0;
}

int list_set_value(IntList* lst, const size_t idx, const int new_val) {
    if (lst == NULL || lst->start == NULL) return 1;
    if (idx >= lst->len) return 2;

    IntNode* cur = lst->start;
    for (size_t i = 0; i < idx; ++i) {
        cur = cur->next;
    }

    cur->val = new_val;
    return 0;
}

int list_print(IntList* lst) {
    if (lst == NULL) {
        return 1;
    }

    if (lst->start == NULL) {
        printf("[]\n");
        return 0;
    }

    IntNode* cur = lst->start;
    printf("[ ");
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("]\n");

    return 0;
}

