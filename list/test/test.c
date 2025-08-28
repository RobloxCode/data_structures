#include <stdio.h>
#include "../list_imp.h"

int main() {
    const size_t list_size = 20;
    IntList* lst = list_make(list_size);
    int status = 0;

    for (size_t i = 0; i < list_size; ++i) {
        status = list_set_value(lst, i, i+1);
        if (status != 0) {
            printf("Status: %d", status);
            list_free(lst);
            return 1;
        }
    }

    status = list_print(lst);
    if (status != 0) {
        printf("Status: %d", status);
        list_free(lst);
        return 1;
    }

    size_t idx = lst->len-1;
    int val = 0;
    status = list_get_val(lst, idx, &val);
    if (status != 0) {
        printf("Status: %d", status);
        list_free(lst);
        return 1;
    }
    printf("var at index: %zu, is: %d\n", idx, val);

    int to_search = 10;
    size_t bs_idx = 0;
    status = list_search(lst, to_search, &bs_idx);
    if (status != 0) {
        printf("Status: %d", status);
        list_free(lst);
        return 1;
    }
    printf("Num to search: %d is at idx: %zu\n\n", to_search, bs_idx);

    status = list_reverse(lst);
    if (status != 0) {
        printf("Status: %d", status);
        list_free(lst);
        return 1;
    }

    status = list_print(lst);
    if (status != 0) {
        printf("Status: %d", status);
        list_free(lst);
        return 1;
    }

    status = list_reverse(lst);
    if (status != 0) {
        printf("Status: %d", status);
        list_free(lst);
        return 1;
    }

    status = list_print(lst);
    if (status != 0) {
        printf("Status: %d", status);
        list_free(lst);
        return 1;
    }

    for (size_t i = 0; i < 10; ++i) {
        status = list_remove(lst, lst->len-1-i);
        if (status != 0) {
            printf("Status: %d", status);
            list_free(lst);
            return 1;
        }
    }

    status = list_append(lst, 100);
    if (status != 0) {
        printf("Status: %d", status);
        list_free(lst);
        return 1;
    }

    status = list_print(lst);
    if (status != 0) {
        printf("Status: %d", status);
        list_free(lst);
        return 1;
    }

    status = list_swap_values(lst, 0, 1);
    if (status != 0) {
        printf("Status: %d", status);
        list_free(lst);
        return 1;
    }

    status = list_swap_values(lst, 0, lst->len-1);
    if (status != 0) {
        printf("Status: %d", status);
        list_free(lst);
        return 1;
    }

    if (list_reverse(lst) != 0) {
        printf("Status: %d", status);
        list_free(lst);
        return 1;
    }

    status = list_print(lst);
    if (status != 0) {
        printf("Status: %d", status);
        list_free(lst);
        return 1;
    }

    printf("SIZE: %zu\n", list_len(lst));
    printf("SIZE: %zu\n", lst->len);

    // list_set_value(lst, 0, 0);
    // list_set_value(lst, 1, 4);
    // list_set_value(lst, 2, 6);
    // list_set_value(lst, 3, 9);
    // list_set_value(lst, 4, 1);
    // list_set_value(lst, 5, -1);
    // list_set_value(lst, 6, -4);
    // list_set_value(lst, 7, 2);
    // list_set_value(lst, 8, 7);
    // list_set_value(lst, 9, 3);
    // list_set_value(lst, 10, 10);
    // list_set_value(lst, 11, 9);
    // list_set_value(lst, 12, 2);
    // list_set_value(lst, 13, 12);
    // list_set_value(lst, 14, 20);
    // list_set_value(lst, 15, -5);
    // list_set_value(lst, 16, 0);
    // list_set_value(lst, 17, 11);
    // list_set_value(lst, 18, 14);
    // list_set_value(lst, 19, 23);
    //
    // if ((status = list_print(lst)) != 0) {
    //     printf("Status: %d", status);
    //     list_free(lst);
    //     return 1;
    // }
    //
    // if ((lst = list_sort(lst)) != 0) {
    //     printf("Status: %d", status);
    //     list_free(lst);
    //     return 1;
    // }
    //
    // if ((status = list_print(lst)) != 0) {
    //     printf("Status: %d", status);
    //     list_free(lst);
    //     return 1;
    // }

    list_free(lst);
    return 0;
}

