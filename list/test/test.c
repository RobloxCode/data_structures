#include <stdio.h>
#include "../list_imp.h"

int main() {
    IntList* lst = list_make(5);
    int status = 0;

    for (size_t i = 0; i < lst->len; ++i) {
        status = list_set_value(lst, i, i+1);
        if (status != 0) {
            printf("%d\n", status);
            list_free(lst);
            return 1;
        }
    }

    status = list_print(lst);
    if (status != 0) {
        printf("%d\n", status);
        list_free(lst);
        return 1;
    }

    status = list_pop(lst, 1);
    if (status != 0) {
        printf("%d\n", status);
        list_free(lst);
        return 1;
    }

    status = list_print(lst);
    if (status != 0) {
        printf("%d\n", status);
        list_free(lst);
        return 1;
    }

    printf("len: %zu\n", lst->len);

    status = list_free(lst);
    if (status != 0) {
        printf("%d\n", status);
        return 1;
    }
    return 0;
}
