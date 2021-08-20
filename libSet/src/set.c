//
// Created by thahnen on 12.02.20.
//

#include <stdlib.h>
#include "set.h"


/**
 *  Creates a new set with one value from given type
 *
 *  @param value    void pointer to the item to use on creation
 *  @param type     the type of the item behind the pointer
 *  @return         true if operation successful, false otherwise
 */
static set* set_create_(void* value, TYPE type) {
    set* new = (set*) malloc(sizeof(set));
    new->type = type;

    if (value == NULL || type == NONE) {
        new->size = 0;
        new->root = NULL;
    } else {
        new->size = 1;
        new->root = node_create(value, getSize(type));
    }

    return new;
}

/// Creates an empty set
set* set_empty() {
    return set_create_(NULL, NONE);
}


#define set_create_i(powerOfTwo) \
    inline set* set_create_i##powerOfTwo (int##powerOfTwo##_t value) { \
        return set_create_((void*) &value, INT##powerOfTwo ); \
    }

#define set_create_u(powerOfTwo) \
    inline set* set_create_u##powerOfTwo (uint##powerOfTwo##_t value) { \
        return set_create_((void*) &value, UINT##powerOfTwo ); \
    }

#define set_create_f(powerOfTwo) \
    inline set* set_create_f##powerOfTwo (float##powerOfTwo value) { \
        return set_create_((void*) &value, FLOAT##powerOfTwo ); \
    }

/// Creates a new set with one 8/16/32/64-bit signed integer
set_create_i(8)
set_create_i(16)
set_create_i(32)
set_create_i(64)

/// Creates a new set with one 8/16/32/64-bit unsigned integer
set_create_u(8)
set_create_u(16)
set_create_u(32)
set_create_u(64)

/// Creates a new set with one 32/64-bit floating point
set_create_f(32)
set_create_f(64)


/**
 *  Adds a value to given set with given type
 *
 *  @param cur      the existing set to add to
 *  @param value    void pointer to the item to add
 *  @param type     the type of the item behind the pointer
 *  @return         true if operation successful, false otherwise
 *
 *  TODO: add pair support
 *  TODO: add to empty set
 */
static bool set_add_(set* restrict cur, void* restrict value, TYPE type) {
    // 1) Check if set pointer is not null
    if (cur == NULL) return false;

    // 2) check if set type equals type of new value
    if (cur->type != type && cur->type != NONE) return false;

    // 3) check if value already in set
    node_t* curNode = cur->root;
    if (curNode != NONE) {
        while (curNode->next != NULL) {
            switch (type) {
            case INT8:
            case UINT8:
                if (*(int8_t*)curNode->data == *(int8_t*)value)     return true;
                break;
            case INT16:
            case UINT16:
                if (*(int16_t*)curNode->data == *(int16_t*)value)   return true;
                break;
            case INT32:
            case UINT32:
            case FLOAT32:
                if (*(int32_t*)curNode->data == *(int32_t*)value)   return true;
                break;
            case INT64:
            case UINT64:
            case FLOAT64:
                if (*(int64_t*)curNode->data == *(int64_t*)value)   return true;
                break;
            case PAIR:
                // not implemented yet
                return false;
            }

            curNode = curNode->next;
        }
    }

    // 4) value not in set, needs to be added
    node_t* new = node_create(value, getSize(type));
    if (cur->size == 0) {
        cur->type = type;
        cur->root = new;

        return true;
    }

    curNode->next = new;
    cur->size++;

    return true;
}


#define set_add_i(powerOfTwo) \
    inline bool set_add_i##powerOfTwo (set* cur, int##powerOfTwo##_t value) { \
        return set_add_(cur, (void*) &value, INT##powerOfTwo );\
    }

#define set_add_u(powerOfTwo) \
    inline bool set_add_u##powerOfTwo (set* cur, uint##powerOfTwo##_t value) { \
        return set_add_(cur, (void*) &value, UINT##powerOfTwo );\
    }

#define set_add_f(powerOfTwo) \
    inline bool set_add_f##powerOfTwo (set* cur, float##powerOfTwo value) { \
        return set_add_(cur, (void*) &value, FLOAT##powerOfTwo ); \
    }

/// Adds a value to given set if it contains 8/16/32/64-bit signed integer
set_add_i(8)
set_add_i(16)
set_add_i(32)
set_add_i(64)

/// Adds a value to given set if it contains 8/16/32/64-bit unsigned integer
set_add_u(8)
set_add_u(16)
set_add_u(32)
set_add_u(64)

/// Adds a value to given set if it contains 32/64-bit floating point
set_add_f(32)
set_add_f(64)


#define set_min_i(powerOfTwo) \
    bool set_min_i##powerOfTwo (set* restrict cur, int##powerOfTwo##_t* restrict result) { \
        if (cur == NULL || cur->type != INT##powerOfTwo || cur->size == 0) return false; \
        *result = *((int##powerOfTwo##_t*) cur->root->data); \
        node_t* cur_node = cur->root->next; \
        while (cur_node != NULL) { \
            int##powerOfTwo##_t now = *((int##powerOfTwo##_t*) cur_node->data); \
            *result = *result < now ? *result : now; \
            cur_node = cur_node->next; \
        } \
        return true; \
    }

#define set_min_u(powerOfTwo) \
    bool set_min_u##powerOfTwo (set* restrict cur, uint##powerOfTwo##_t* restrict result) { \
        if (cur == NULL || cur->type != UINT##powerOfTwo || cur->size == 0) return false; \
        *result = *((uint##powerOfTwo##_t*) cur->root->data); \
        node_t* cur_node = cur->root->next; \
        while (cur_node != NULL) { \
            uint##powerOfTwo##_t now = *((uint##powerOfTwo##_t*) cur_node->data); \
            *result = *result < now ? *result : now; \
            cur_node = cur_node->next; \
        } \
        return true; \
    }

#define set_min_f(powerOfTwo) \
    bool set_min_f##powerOfTwo (set* restrict cur, float##powerOfTwo * restrict result) { \
        if (cur == NULL || cur->type != FLOAT##powerOfTwo || cur->size == 0) return false; \
        *result = *((float##powerOfTwo *) cur->root->data); \
        node_t* cur_node = cur->root->next; \
        while (cur_node != NULL) { \
            float##powerOfTwo now = *((float##powerOfTwo *) cur_node->data); \
            *result = *result < now ? *result : now; \
            cur_node = cur_node->next; \
        } \
        return true; \
    }

/// Gets the minumum value from given set with 8/16/32/64-bit signed integer
set_min_i(8)
set_min_i(16)
set_min_i(32)
set_min_i(64)

/// Gets the minimum value from given set with 8/16/32/64-bit unsigned integer
set_min_u(8)
set_min_u(16)
set_min_u(32)
set_min_u(64)

/// Gets the minimum value from given set with 32/64-bit floating point
set_min_f(32)
set_min_f(64)


#define set_max_i(powerOfTwo) \
    bool set_max_i##powerOfTwo (set* restrict cur, int##powerOfTwo##_t* restrict result) { \
        if (cur == NULL || cur->type != INT##powerOfTwo || cur->size == 0) return false; \
        *result = *((int##powerOfTwo##_t*) cur->root->data); \
        node_t* cur_node = cur->root->next; \
        while (cur_node != NULL) { \
            int##powerOfTwo##_t now = *((int##powerOfTwo##_t*) cur_node->data); \
            *result = *result > now ? *result : now; \
            cur_node = cur_node->next; \
        } \
    }

#define set_max_u(powerOfTwo) \
    bool set_max_u##powerOfTwo (set* restrict cur, uint##powerOfTwo##_t* restrict result) { \
        if (cur == NULL || cur->type != UINT##powerOfTwo || cur->size == 0) return false; \
        *result = *((uint##powerOfTwo##_t*) cur->root->data); \
        node_t* cur_node = cur->root->next; \
        while (cur_node != NULL) { \
            uint##powerOfTwo##_t now = *((uint##powerOfTwo##_t*) cur_node->data); \
            *result = *result > now ? *result : now; \
            cur_node = cur_node->next; \
        } \
    }

#define set_max_f(powerOfTwo) \
    bool set_max_f##powerOfTwo (set* restrict cur, float##powerOfTwo * restrict result) { \
        if (cur == NULL || cur->type != FLOAT##powerOfTwo || cur->size == 0) return false; \
        *result = *((float##powerOfTwo *) cur->root->data); \
        node_t* cur_node = cur->root->next; \
        while (cur_node != NULL) { \
            float##powerOfTwo now = *((float##powerOfTwo *) cur_node->data); \
            *result = *result > now ? *result : now; \
            cur_node = cur_node->next; \
        } \
    }

/// Gets the maximum value from given set with 8/16/32/64-bit signed integer
set_max_i(8)
set_max_i(16)
set_max_i(32)
set_max_i(64)

/// Gets the maximum value from given set with 8/16/32/64-bit unsigned integer
set_max_u(8)
set_max_u(16)
set_max_u(32)
set_max_u(64)

/// Gets the maximum value from given set with 32/64-bit floating point
set_max_f(32)
set_max_f(64)



/// Adds two sets together
bool set_union(set* A, set* B, set* out) {
    // Null-Pointer not allowed
    if (out == NULL || (A == NULL && B == NULL)) {
        return false;
    }

    // Both are empty or both are pairs
    if (A->type == NONE && B->type == NONE) {
        *out = *set_empty();
        return true;
    } else if (A->type == PAIR && B->type == PAIR) {
        // Pairs not implemented yet!
        return false;
    }

    // Only one is empty set
    // TODO: maybe create deep copy?
    if (A->type == NONE || A == NULL) {
        *out = *B;
        return true;
    } else if (B->type == NONE || B == NULL) {
        *out = *A;
        return true;
    }

    // All other values!
    TYPE otype = max(A->type, B->type);
    if (otype != NONE) {
        // 1) Create new set
        *out = *set_empty();

        // 2) Loop over A, adding values to new set
        node_t* cur = A->root;
        do {
            switch (otype) {
            case INT8:
                set_add_i8(out, *(int8_t*)cur->data);
                break;
            case UINT8:
                set_add_u8(out, *(uint8_t*)cur->data);
                break;
            case INT16:
                set_add_i16(out, *(int16_t*)cur->data);
                break;
            case UINT16:
                set_add_u16(out, *(uint16_t*)cur->data);
                break;
            case INT32:
                set_add_i32(out, *(int32_t*)cur->data);
                break;
            case UINT32:
                set_add_u32(out, *(uint32_t*)cur->data);
                break;
            case INT64:
                set_add_i64(out, *(int64_t*)cur->data);
                break;
            case UINT64:
                set_add_u64(out, *(uint64_t*)cur->data);
                break;
            case FLOAT32:
                set_add_f32(out, *(float32*)cur->data);
                break;
            case FLOAT64:
                set_add_f64(out, *(float64*)cur->data);
            }

            cur = cur->next;
        } while (cur);

        // 3) Loop over B, adding values to new set
        cur = B->root;
        do {
            switch (otype) {
            case INT8:
                set_add_i8(out, *(int8_t*)cur->data);
                break;
            case UINT8:
                set_add_u8(out, *(uint8_t*)cur->data);
                break;
            case INT16:
                set_add_i16(out, *(int16_t*)cur->data);
                break;
            case UINT16:
                set_add_u16(out, *(uint16_t*)cur->data);
                break;
            case INT32:
                set_add_i32(out, *(int32_t*)cur->data);
                break;
            case UINT32:
                set_add_u32(out, *(uint32_t*)cur->data);
                break;
            case INT64:
                set_add_i64(out, *(int64_t*)cur->data);
                break;
            case UINT64:
                set_add_u64(out, *(uint64_t*)cur->data);
                break;
            case FLOAT32:
                set_add_f32(out, *(float32*)cur->data);
                break;
            case FLOAT64:
                set_add_f64(out, *(float64*)cur->data);
            }

            cur = cur->next;
        } while (cur);

        return true;
    }

    return false;
}
