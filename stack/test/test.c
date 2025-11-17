#include <stdio.h>
#include "../stack_imp.h"

int main() {
    stack_status_t status;
    IntStack* s;
    int top;

    status = stack_init(&s);
    if (status != STACK_OK) {
        printf("status: %d\n", status);
        stack_free(&s);
        return 1;
    }

    status = stack_push(s, 1);
    if (status != STACK_OK) {
        printf("status: %d\n", status);
        stack_free(&s);
        return 1;
    }

    status = stack_push(s, 2);
    if (status != STACK_OK) {
        printf("status: %d\n", status);
        stack_free(&s);
        return 1;
    }

    status = stack_push(s, 3);
    if (status != STACK_OK) {
        printf("Status: %d\n", status);
        stack_free(&s);
        return 1;
    }

    status = stack_print(s);
    if (status != STACK_OK) {
        printf("Status: %d\n", status);
        stack_free(&s);
        return 1;
    }

    status = stack_pop(s, &top);
    if (status != STACK_OK) {
        printf("Status: %d\n", status);
        stack_free(&s);
        return 1;
    }
    printf("popped item: %d\n", top);

    status = stack_print(s);
    if (status != STACK_OK) {
        printf("Status: %d\n", status);
        stack_free(&s);
        return 1;
    }

    status = stack_peek(s, &top);
    if (status != STACK_OK) {
        printf("Status: %d\n", status);
        stack_free(&s);
        return 1;
    }
    printf("peeked item: %d\n", top);

    status = stack_print(s);
    if (status != STACK_OK) {
        printf("Status: %d\n", status);
        stack_free(&s);
        return 1;
    }

    status = stack_push(s, 4);
    if (status != STACK_OK) {
        printf("Status: %d\n", status);
        stack_free(&s);
        return 1;
    }

    status = stack_push(s, 5);
    if (status != STACK_OK) {
        printf("Status: %d\n", status);
        stack_free(&s);
        return 1;
    }

    status = stack_print(s);
    if (status != STACK_OK) {
        printf("Status: %d\n", status);
        stack_free(&s);
        return 1;
    }

    status = stack_free(&s);
    if (status != STACK_OK) {
        printf("Status: %d\n", status);
        stack_free(&s);
        return 1;
    }
    return 0;
}

