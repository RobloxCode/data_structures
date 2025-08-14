#include <stdio.h>
#include "../list_imp.h"

int main() {
    IntList* lst = list_make(5);
    int status = 0;

    list_set_value(lst, 0, 1);
    list_set_value(lst, 1, 2);
    list_set_value(lst, 2, 3);
    list_set_value(lst, 3, 4);
    list_set_value(lst, 4, 5);

    status = list_print(lst);
    if (status != 0) {
        printf("%d\n", status);
        list_free(lst);
        return 1;
    }

    status = list_pop(lst, 0);
    if (status != 0) {
        printf("%d\n", status);
        list_free(lst);
        return 1;
    }

    status = list_pop(lst, lst->len-1);
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
