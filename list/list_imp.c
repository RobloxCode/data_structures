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
    lst = NULL;
    return 0;
}

int list_remove(IntList* lst, const size_t idx) {
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

int list_get_val(const IntList* lst, const size_t idx, int* out) {
    if (lst == NULL || out == NULL) return 1;
    if (idx >= lst->len) return 2;

    const IntNode* cur = lst->start;
    for (size_t i = 0; i < idx; ++i) {
        cur = cur->next;
    }

    *out = cur->val;
    return 0;
}

int list_print(const IntList* lst) {
    if (lst == NULL) {
        return 1;
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

int list_search(const IntList* lst, const int target, size_t* out) {
    if (lst == NULL || out == NULL) return 1;

    int left = 0;
    int right = (int)lst->len-1;
    int middle_val = 0;
    int status = 0;

    while (left <= right) {
        int middle_idx = (left + right) / 2;
        status = list_get_val(lst, (size_t)middle_idx, &middle_val);
        if (status != 0) {
            return status;
        }

        if (target == middle_val) {
            *out = (size_t)middle_idx;
            return 0;
        } else if (target > middle_val) {
            left = middle_idx + 1;
        } else {
            right = middle_idx - 1;
        }
    }

    *out = -1;
    return 3;
}

