#include <stdio.h>
#include "../list_imp.h"

int main() {
    const size_t list_size = 20;
    IntList* lst = list_make(20);
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

    list_free(lst);
    return 0;
}

