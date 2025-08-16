#include <stdio.h>
#include "../stack_imp.h"

int main() {
    int status = 0;
    Stack* s = stack_make();
    if (s == NULL) {
        printf("Status code: %d\n", 1);
        return 1;
    }

    status = stack_print(s);
    if (status != 0) {
        printf("Status: %d\n", status);
        stack_free(s);
        return 1;
    }

    status = stack_push(s, 1);
    if (status != 0) {
        printf("Status: %d\n", status);
        stack_free(s);
        return 1;
    }

    status = stack_push(s, 2);
    if (status != 0) {
        printf("Status: %d\n", status);
        stack_free(s);
        return 1;
    }

    status = stack_push(s, 3);
    if (status != 0) {
        printf("Status: %d\n", status);
        stack_free(s);
        return 1;
    }

    status = stack_print(s);
    if (status != 0) {
        printf("Status: %d\n", status);
        stack_free(s);
        return 1;
    }

    int top;
    status = stack_pop(s, &top);
    if (status != 0) {
        printf("Status: %d\n", status);
        stack_free(s);
        return 1;
    }
    printf("popped item: %d\n", top);

    status = stack_print(s);
    if (status != 0) {
        printf("Status: %d\n", status);
        stack_free(s);
        return 1;
    }

    status = stack_peek(s, &top);
    if (status != 0) {
        printf("Status: %d\n", status);
        stack_free(s);
        return 1;
    }
    printf("peeked item: %d\n", top);

    status = stack_print(s);
    if (status != 0) {
        printf("Status: %d\n", status);
        stack_free(s);
        return 1;
    }

    stack_free(s);
    return 0;
}

