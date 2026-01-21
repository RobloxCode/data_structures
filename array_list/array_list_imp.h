#ifndef ARRAY_LIST_IMP
#define ARRAY_LIST_IMP
#include <stddef.h>
#include <stdint.h>

typedef enum {
    ARRAY_LIST_OK,
    ARRAY_LIST_WRONG_PTR,
    ARRAY_LIST_ERR_MALLOC,
    ARRAY_LIST_ERR_REALLOC,
    ARRAY_LIST_OVERFLOW,
    ARRAY_LIST_INVALID_SIZE,
    ARRAY_LIST_IDX_OUT_OF_BOUNDS,
} int16_Array_List_status;

typedef struct {
    int16_t* items;
    size_t capacity;
    size_t length;
} int16_Array_List;

int16_Array_List* int16_Array_List_make(size_t init_capacity);
int16_Array_List_status int16_Array_List_free(int16_Array_List** al);
int16_Array_List_status int16_Array_List_append(
    int16_Array_List* al,
    int16_t item);
int16_Array_List_status int16_Array_List_remove(
    int16_Array_List* al,
    size_t index);
int16_Array_List_status int16_Array_List_print(int16_Array_List* al);
int16_Array_List_status int16_Array_List_get_item(
    int16_Array_List* al,
    size_t idx,
    int16_t* buff);
int16_Array_List_status int16_Array_List_swap(
    int16_Array_List* al,
    size_t index1,
    size_t index2);
#endif
