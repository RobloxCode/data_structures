#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode {
    int val;
    struct IntNode* next;
} IntNode;

typedef struct {
    IntNode* top;
    size_t len;
} IntStack;

IntStack* stack_make() {
    IntStack* s = malloc(sizeof(IntStack));
    if (s == NULL) {
        return NULL;
    }

    s->top = NULL;
    s->len = 0;

    return s;
}

int stack_free(IntStack* s) {
    if (s == NULL) return 1;

    IntNode* cur = s->top;
    while (cur != NULL) {
        IntNode* next = cur->next;
        free(cur);
        cur = next;
    }

    free(s);
    return 0;
}

int stack_push(IntStack* s, int val) {
    if (s == NULL) return 1;

    IntNode* new_top = malloc(sizeof(IntNode));
    if (new_top == NULL) {
        return 1;
    }

    new_top->val = val;
    new_top->next = s->top;
    s->top = new_top;
    s->len++;

    return 0;
}

int stack_pop(IntStack* s, int* out) {
    if (s == NULL || s->top == NULL) return 1;

    IntNode* old_top = s->top;
    if (out != NULL) *out = old_top->val;
    s->top = old_top->next;
    free(old_top);
    s->len--;

   return 0;
}

int stack_peek(IntStack* s, int* out) {
    if (s == NULL || out == NULL) return 1;
    if (out != NULL) *out = s->top->val;
    return 0;
}

int stack_print(IntStack* s) {
    if (s == NULL) return 1;

    IntNode* cur = s->top;
    printf("[ ");
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("]\n");
    return 0;
}

