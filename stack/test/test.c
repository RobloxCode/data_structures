#include <stdio.h>
#include "../stack_imp.h"

int main() {
    stack_status_t status;
    IntStack* s;
    int top;

    status = stack_init(&s);
    if (status != STACK_OK)
        goto stack_cleanup;

    status = stack_push(s, 1);
    if (status != STACK_OK)
        goto stack_cleanup;

    status = stack_push(s, 2);
    if (status != STACK_OK)
        goto stack_cleanup;

    status = stack_push(s, 3);
    if (status != STACK_OK)
        goto stack_cleanup;

    status = stack_print(s);
    if (status != STACK_OK)
        goto stack_cleanup;

    status = stack_pop(s, &top);
    if (status != STACK_OK)
        goto stack_cleanup;

    printf("popped item: %d\n", top);

    status = stack_print(s);
    if (status != STACK_OK)
        goto stack_cleanup;

    status = stack_peek(s, &top);
    if (status != STACK_OK)
        goto stack_cleanup;

    printf("peeked item: %d\n", top);

    status = stack_print(s);
    if (status != STACK_OK)
        goto stack_cleanup;

    status = stack_push(s, 4);
    if (status != STACK_OK)
        goto stack_cleanup;

    status = stack_push(s, 5);
    if (status != STACK_OK)
        goto stack_cleanup;

    status = stack_print(s);
    if (status != STACK_OK)
        goto stack_cleanup;

    status = stack_free(&s);
    return 0;

stack_cleanup:
    printf("status: %d\n", status);

    if (s)
        stack_free(&s);

    return 1;
}

