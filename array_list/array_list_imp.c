#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    ARRAY_LIST_OK                   = 0,

    ARRAY_LIST_WRONG_PTR            = 10,

    ARRAY_LIST_ERR_MALLOC           = 20,
    ARRAY_LIST_ERR_REALLOC          = 21,
    ARRAY_LIST_OVERFLOW             = 22,
    ARRAY_LIST_INVALID_SIZE         = 23,

    ARRAY_LIST_IDX_OUT_OF_BOUNDS    = 30,
} int16_Array_List_status;

typedef struct {
    int16_t* items;
    size_t capacity;
    size_t length;
} int16_Array_List;

int16_Array_List* int16_Array_List_make(size_t init_capacity) {
    if (init_capacity == 0) {
        return NULL;
    }

    int16_Array_List* al = malloc(sizeof *al);
    if (!al) {
        return NULL;
    }

    int16_t* items = calloc(init_capacity, sizeof *items);
    if (!items) {
        free(al);
        return NULL;
    }

    al->items = items;
    al->capacity = init_capacity;
    al->length = 0;

    return al;
}

int16_Array_List_status int16_Array_List_free(int16_Array_List** al) {
    if (!al || !*al) {
        return ARRAY_LIST_WRONG_PTR;
    }

    free((*al)->items);
    free(*al);
    *al = NULL;

    return ARRAY_LIST_OK;
}

int16_Array_List_status int16_Array_List_append(
    int16_Array_List* al,
    int16_t item) {
    if (!al) {
        return ARRAY_LIST_WRONG_PTR;
    }

    if (al->length >= al->capacity) {
        if (al->capacity > SIZE_MAX / 2) {
            return ARRAY_LIST_OVERFLOW;
        }

        size_t new_capacity = al->capacity * 2;
        int16_t* new_items = realloc(al->items, new_capacity * sizeof *new_items);
        if (!new_items) {
            return ARRAY_LIST_ERR_MALLOC;
        }

        al->items = new_items;
        al->capacity = new_capacity;
        al->items[al->length] = item;
        al->length++;
        return ARRAY_LIST_OK;
    }

    al->items[al->length] = item;
    al->length++;
    return ARRAY_LIST_OK;
}

int16_Array_List_status int16_Array_List_swap(
    int16_Array_List* al,
    size_t idx1,
    size_t idx2) {
    if (!al) {
        return ARRAY_LIST_WRONG_PTR;
    }

    if (idx1 >= al->length || idx2 >= al->length) {
        return ARRAY_LIST_IDX_OUT_OF_BOUNDS;
    }

    int16_t tmp = al->items[idx1];
    al->items[idx1] = al->items[idx2];
    al->items[idx2] = tmp;

    return ARRAY_LIST_OK;
}

int16_Array_List_status int16_Array_List_remove(
    int16_Array_List* al,
    size_t idx) {
    if (!al) {
        return ARRAY_LIST_WRONG_PTR;
    }

    if (idx >= al->length) {
        return ARRAY_LIST_IDX_OUT_OF_BOUNDS;
    }

    int16_Array_List_status status = ARRAY_LIST_OK;
    for (size_t i = idx; i < al->length - 1; ++i) {
        status = int16_Array_List_swap(al, i, i + 1);
        if (status != ARRAY_LIST_OK) {
            return status;
        }
    }

    al->length--;
    return ARRAY_LIST_OK;
}

int16_Array_List_status int16_Array_List_print(int16_Array_List* al) {
    if (!al) {
        return ARRAY_LIST_WRONG_PTR;
    }

    for (size_t i = 0; i < al->length; ++i) {
        printf("%" PRId16 " ", al->items[i]);
    }

    printf("\n");
    return ARRAY_LIST_OK;
}

int16_Array_List_status int16_Array_List_get_item(
    int16_Array_List* al,
    size_t idx,
    int16_t* buff) {
    if (!al || !buff) {
        return ARRAY_LIST_WRONG_PTR;
    }

    if (idx >= al->length) {
        return ARRAY_LIST_IDX_OUT_OF_BOUNDS;
    }

    *buff = al->items[idx];
    return ARRAY_LIST_OK;
}

