#include "../array_list_imp.h"
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int main(void) {
    int16_Array_List_status status = ARRAY_LIST_OK;
    int16_Array_List* al = int16_Array_List_make(5);
    if (!al) {
        return EXIT_FAILURE;
    }

    int16_Array_List_append(al, 1);
    int16_Array_List_append(al, 2);
    int16_Array_List_append(al, 3);
    int16_Array_List_append(al, 4);
    int16_Array_List_append(al, 5);
    int16_Array_List_append(al, 6);

    status = int16_Array_List_print(al);
    if (status != ARRAY_LIST_OK)
        goto array_list_cleanup;

    size_t idx = 5;
    int16_t item = 0;
    status = int16_Array_List_get(al, idx, &item);
    if (status != ARRAY_LIST_OK)
        goto array_list_cleanup;
    printf("%" PRId16 "\n", item);

    status = int16_Array_List_swap(al, 0, al->length - 1);
    if (status != ARRAY_LIST_OK)
        goto array_list_cleanup;

    int16_Array_List_print(al);

    status = int16_Array_List_remove(al, al->length-1);
    if (status != ARRAY_LIST_OK)
        goto array_list_cleanup;

    status = int16_Array_List_remove(al, 5);
    if (status != ARRAY_LIST_OK)
        goto array_list_cleanup;

    int16_Array_List_print(al);
    printf("cap: %zu\n", al->capacity);
    printf("len: %zu\n", al->length);

    int16_Array_List_free(&al);
    return EXIT_SUCCESS;

array_list_cleanup:
    printf("status: %d", status);
    if (al)
        int16_Array_List_free(&al);

    return EXIT_FAILURE;
}
