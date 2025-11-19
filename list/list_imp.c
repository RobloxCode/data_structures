#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    LIST_OK                = 0,
    LIST_WRONG_PTR         = 1,
    LIST_IDX_OUT_OF_BOUNDS = 2,
    LIST_ITEM_NOT_FOUND    = 3
} list_status_t;

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
    if (lst == NULL) {
        return NULL;
    }

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

list_status_t list_free(IntList* lst) {
    if (lst == NULL) {
        return LIST_WRONG_PTR;
    }

    IntNode* cur = lst->start;
    while (cur != NULL) {
        IntNode* next = cur->next;
        free(cur);
        cur = next;
    }

    free(lst);
    return LIST_OK;
}

list_status_t list_remove(IntList* lst, const size_t idx) {
    if (lst == NULL) {
        return LIST_WRONG_PTR;
    }

    if (idx >= lst->len) {
        return LIST_IDX_OUT_OF_BOUNDS;
    }

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
    return LIST_OK;
}

list_status_t list_set_value(IntList* lst, const size_t idx, const int new_val) {
    if (lst == NULL) {
        return LIST_WRONG_PTR;
    }

    if (idx >= lst->len) {
        return LIST_IDX_OUT_OF_BOUNDS;
    }

    IntNode* cur = lst->start;
    for (size_t i = 0; i < idx; ++i) {
        cur = cur->next;
    }

    cur->val = new_val;
    return LIST_OK;
}

list_status_t list_get_val(const IntList* lst, const size_t idx, int* out) {
    if (lst == NULL || out == NULL) {
        return LIST_WRONG_PTR;
    }

    if (idx >= lst->len) {
        return LIST_IDX_OUT_OF_BOUNDS;
    }

    const IntNode* cur = lst->start;
    for (size_t i = 0; i < idx; ++i) {
        cur = cur->next;
    }

    *out = cur->val;
    return LIST_OK;
}

list_status_t list_print(const IntList* lst) {
    if (lst == NULL) {
        return LIST_WRONG_PTR;
    }

    IntNode* cur = lst->start;
    printf("[ ");
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("]\n");

    return LIST_OK;
}

list_status_t list_search(const IntList* lst, const int target, size_t* out) {
    if (lst == NULL || out == NULL) {
        return LIST_WRONG_PTR;
    }

    int status = 0;
    int cur_val = 0;
    for (size_t i = 0; i < lst->len - 1; ++i) {
        if ((status = list_get_val(lst, i, &cur_val)) != 0) {
            return status;
        }

        if (target == cur_val) {
            *out = i;
            return LIST_OK;
        }
    }

    return 3;
}

list_status_t list_reverse(IntList* lst) {
    if (lst == NULL) {
        return LIST_WRONG_PTR;
    }

    IntNode* prev = NULL;
    IntNode* cur = lst->start;
    while (cur != NULL) {
        IntNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    lst->start = prev;
    return LIST_OK;
}

list_status_t list_append(IntList* lst, int val) {
    if (lst == NULL) {
        return LIST_WRONG_PTR;
    }

    IntNode* new = malloc(sizeof(IntNode));
    if (new == NULL) {
        return LIST_WRONG_PTR;
    }
    new->val = val;
    new->next = NULL;

    if (lst->start == NULL) {
        lst->start = new;
    } else {
        IntNode* cur = lst->start;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new;
    }

    lst->len++;
    return LIST_OK;
}

size_t list_len(const IntList* lst) {
    if (lst == NULL || lst->start == NULL) {
        return LIST_OK;
    }
    return lst->len;
}

list_status_t list_swap_values(IntList* lst, size_t idx1, size_t idx2) {
    if (lst == NULL) {
        return LIST_WRONG_PTR;
    }

    if (idx1 >= lst->len || idx2 >= lst->len) {
        return LIST_IDX_OUT_OF_BOUNDS;
    }

    int val1;
    int val2;
    int status;

    if ((status = list_get_val(lst, idx1, &val1)) != 0) {
        return status;
    }

    if ((status = list_get_val(lst, idx2, &val2)) != 0) {
        return status;
    }

    if ((status = list_set_value(lst, idx1, val2)) != 0) {
        return status;
    }

    if ((status = list_set_value(lst, idx2, val1)) != 0) {
        return status;
    }

    return LIST_OK;
}

list_status_t list_sort(IntList* lst) {
    if (lst == NULL || lst->start ==  NULL) {
        return LIST_WRONG_PTR;
    }

    int status = 0;
    size_t half_size = lst->len / 2;
    IntList* left_lst = list_make(half_size);
    IntList* right_lst = list_make(half_size);

    if (left_lst == NULL || right_lst == NULL) {
        return LIST_WRONG_PTR;
    }

    int left_cur_val = 0;
    for (size_t i = 0; i < half_size; ++i) {
        if ((status = list_get_val(lst, i, &left_cur_val)) != 0) {
            return status;
        }

        if ((status = list_set_value(left_lst, i, left_cur_val)) != 0) {
            return status;
        }
    }

    int right_cur_val = 0;
    for (size_t i = half_size; i < lst->len - 1; ++i) {
        if ((status = list_get_val(lst, i, &right_cur_val)) != 0) {
            return status;
        }

        if ((status = list_set_value(right_lst, i - half_size, right_cur_val) != 0)) {
            return status;
        }
    }

    list_print(left_lst);
    list_print(right_lst);

    return LIST_OK;
}

