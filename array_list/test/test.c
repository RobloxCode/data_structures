#include "../array_list_imp.h"
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

void print_arr_list_info(int16_Array_List* al) {
    printf("capacity: %zu\nlength: %zu\n",
           al->capacity,
           al->length);
}

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

    print_arr_list_info(al);
    status = int16_Array_List_print(al);

    size_t idx = 5;
    int16_t item = 0;
    status = int16_Array_List_get_item(al, idx, &item);
    if (status != ARRAY_LIST_OK)
        goto array_list_cleanup;
    printf("idx: %zu\n", idx);
    printf("value: %" PRId16 "\n", item);

    status = int16_Array_List_swap(al, 0, al->length - 1);
    if (status != ARRAY_LIST_OK)
        goto array_list_cleanup;

    print_arr_list_info(al);
    int16_Array_List_print(al);

    status = int16_Array_List_remove(al, 0);
    if (status != ARRAY_LIST_OK)
        goto array_list_cleanup;

    print_arr_list_info(al);
    int16_Array_List_print(al);

    status = int16_Array_List_remove(al, al->length - 1);
    if (status != ARRAY_LIST_OK)
        goto array_list_cleanup;

    print_arr_list_info(al);
    int16_Array_List_print(al);

    return EXIT_SUCCESS;

array_list_cleanup:
    printf("status: %d", status);
    if (al)
        int16_Array_List_free(&al);

    return EXIT_FAILURE;
}
