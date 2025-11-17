#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    STACK_OK,
    STACK_NULL_PTR,
} stack_status_t;

typedef struct IntNode {
    int val;
    struct IntNode* next;
} IntNode;

typedef struct {
    IntNode* top;
    size_t len;
} IntStack;

stack_status_t stack_init(IntStack** s) {
    if (s == NULL) {
        return STACK_NULL_PTR;
    }

    IntStack* new = malloc(sizeof(IntStack));
    if (new == NULL) {
        return STACK_NULL_PTR;
    }

    new->len = 0;
    new->top = NULL;
    *s = new;
    return STACK_OK;
}

stack_status_t stack_free(IntStack** s) {
    if (s == NULL || *s == NULL) {
        return STACK_NULL_PTR;
    }

    IntNode* cur = (*s)->top;
    while (cur != NULL) {
        IntNode* next = cur->next;
        free(cur);
        cur = next;
    }

    free(*s);
    *s = NULL;
    return STACK_OK;
}

stack_status_t stack_push(IntStack* s, int val) {
    if (s == NULL) {
        return STACK_NULL_PTR;
    }

    IntNode* new_top = malloc(sizeof(IntNode));
    if (new_top == NULL) {
        return STACK_NULL_PTR;
    }

    new_top->val = val;
    new_top->next = s->top;
    s->top = new_top;
    s->len++;

    return STACK_OK;
}

stack_status_t stack_pop(IntStack* s, int* out) {
    if (s == NULL || s->top == NULL) {
        return STACK_NULL_PTR;
    }

    IntNode* old_top = s->top;
    if (out != NULL) *out = old_top->val;
    s->top = old_top->next;
    free(old_top);
    s->len--;

    return STACK_OK;
}

stack_status_t stack_peek(IntStack* s, int* out) {
    if (s == NULL || out == NULL) {
        return STACK_NULL_PTR;
    }

    if (out != NULL) {
        *out = s->top->val;
    }

    return STACK_OK;
}

stack_status_t stack_print(IntStack* s) {
    if (s == NULL) {
        return STACK_NULL_PTR;
    }

    IntNode* cur = s->top;
    printf("[ ");
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("]\n");
    return STACK_OK;
}

