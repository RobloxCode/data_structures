#include <stdio.h>
#include "../list_imp.h"

int main() {
    const size_t list_size = 20;
    IntList* lst = list_make(list_size);
    int status = 0;

    for (size_t i = 0; i < list_size; ++i) {
        status = list_set_value(lst, i, i+1);
        if (status != 0)
            goto list_cleanup;
    }

    status = list_print(lst);
    if (status != LIST_OK)
        goto list_cleanup;

    size_t idx = lst->len-1;
    int val = 0;
    status = list_get_val(lst, idx, &val);
    if (status != LIST_OK)
        goto list_cleanup;

    printf("var at index: %zu, is: %d\n", idx, val);

    int to_search = 10;
    size_t bs_idx = 0;
    status = list_search(lst, to_search, &bs_idx);
    if (status != LIST_OK)
        goto list_cleanup;

    printf("Num to search: %d is at idx: %zu\n\n", to_search, bs_idx);

    status = list_reverse(lst);
    if (status != LIST_OK)
        goto list_cleanup;

    status = list_print(lst);
    if (status != LIST_OK)
        goto list_cleanup;

    status = list_reverse(lst);
    if (status != LIST_OK)
        goto list_cleanup;

    status = list_print(lst);
    if (status != LIST_OK)
        goto list_cleanup;

    for (size_t i = 0; i < 10; ++i) {
        status = list_remove(lst, lst->len-1-i);
        if (status != LIST_OK)
            goto list_cleanup;
    }

    status = list_print(lst);
    if (status != LIST_OK)
        goto list_cleanup;

    status = list_swap_values(lst, 0, 1);
    if (status != LIST_OK)
        goto list_cleanup;

    status = list_swap_values(lst, 0, lst->len-1);
    if (status != LIST_OK)
        goto list_cleanup;

    if (list_reverse(lst) != LIST_OK)
        goto list_cleanup;

    status = list_print(lst);
    if (status != LIST_OK)
        goto list_cleanup;

    printf("SIZE: %zu\n", list_len(lst));
    printf("SIZE: %zu\n", lst->len);

    status = list_sort(lst);
    if (status != LIST_OK)
        goto list_cleanup;

    status = list_free(lst);
    return 0;

list_cleanup:
    printf("status: %d", status);
    if (lst)
        list_free(lst);

    return 1;
}

