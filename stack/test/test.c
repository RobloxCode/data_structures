#include <stdio.h>
#include "../stack_imp.h"

int main() {
    IntNode* stack = stack_make();
    if (stack == NULL) printf("is null\n");

    return 0;
}

