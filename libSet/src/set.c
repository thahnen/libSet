//
// Created by thahnen on 12.02.20.
//

#include <stdlib.h>
#include "set.h"


/// Creates an empty set
// TODO: merge with set_create_ function!
set* set_empty() {
    set* new = (set*) malloc(sizeof(set));
    new->type = NONE;
    new->size = 0;
    new->root = NULL;
    new->last = NULL;
    return new;
}


/**
 *  Creates a new set with one value from given type
 *
 *  @param value    void pointer to the item to use on creation
 *  @param type     the type of the item behind the pointer
 *  @return         true if operation successful, false otherwise
 */
static set* set_create_(void* value, TYPE type) {
    if (type == NONE) return NULL;

    set* new = (set*) malloc(sizeof(set));
    new->type = type;
    new->size = 1;
    new->root = node_create(value, getSize(type));
    new->last = new->root;

    return new;
}

/// Creates a new set with one 8-Bit integer item
set* set_create_i8(int8_t value) {
    return set_create_((void*) &value, INT8);
}

/// Creates a new set with one unsigned 8-Bit integer item
set* set_create_u8(uint8_t value) {
    return set_create_((void*) &value, UINT8);
}

/// Creates a new set with one 16-Bit integer item
set* set_create_i16(int16_t value) {
    return set_create_((void*) &value, INT16);
}

/// Creates a new set with one unsigned 16-Bit integer item
set* set_create_u16(uint16_t value) {
    return set_create_((void*) &value, UINT16);
}

/// Creates a new set with one 32-Bit integer item
set* set_create_i32(int32_t value) {
    return set_create_((void*) &value, INT32);
}

/// Creates a new set with one unsigned 32-Bit integer item
set* set_create_u32(uint32_t value) {
    return set_create_((void*) &value, UINT32);
}

/// Creates a new set with one 64-Bit integer item
set* set_create_i64(int64_t value) {
    return set_create_((void*) &value, INT64);
}

/// Creates a new set with one unsigned 64-Bit integer item
set* set_create_u64(uint64_t value) {
    return set_create_((void*) &value, UINT64);
}

/// Creates a new set with one 32-Bit floating point item
set* set_create_f32(float32 value) {
    return set_create_((void*) &value, FLOAT32);
}

/// Creates a new set with one 64-Bit floating point item
set* set_create_f64(float64 value) {
    return set_create_((void*) &value, FLOAT64);
}


/**
 *  Adds a value to given set with given type
 *
 *  @param cur      the existing set to add to
 *  @param value    void pointer to the item to add
 *  @param type     the type of the item behind the pointer
 *  @return         true if operation successful, false otherwise
 *
 *  TODO: handle same values!
 */
static bool set_add_(set* cur, void* value, TYPE type) {
    // 1) Check if set pointer is not null
    if (cur == NULL) return false;

    // 2) check if set type equals type of new value
    if (cur->type != type && cur->type != NONE) {
        return false;
    }

    node_t* new = node_create(value, getSize(type));
    if (cur->size == 0) {
        cur->type = type;
        cur->root = new;
        cur->last = new;

        return true;
    }

    node_t* curNode = cur->root;
    while (curNode->next != NULL) {
        curNode = curNode->next;
    }

    curNode->next = new;
    cur->last = new;
    cur->size++;

    return true;
}

/// Adds a value to given set if it contains 8-Bit integer
bool set_add_i8(set* cur, int8_t value) {
    return set_add_(cur, (void*) &value, INT8);
}

/// Adds a value to given set if it contains unsigned 8-Bit integer
bool set_add_u8(set* cur, uint8_t value) {
    return set_add_(cur, (void*) &value, UINT8);
}

/// Adds a value to given set if it contains 16-Bit integer
bool set_add_i16(set* cur, int16_t value) {
    return set_add_(cur, (void*) &value, INT16);
}

/// Adds a value to given set if it contains unsigned 16-Bit integer
bool set_add_u16(set* cur, uint16_t value) {
    return set_add_(cur, (void*) &value, UINT16);
}

/// Adds a value to given set if it contains 32-Bit integer
bool set_add_i32(set* cur, int32_t value) {
    return set_add_(cur, (void*) &value, INT32);
}

/// Adds a value to given set if it contains unsigned 32-Bit integer
bool set_add_u32(set* cur, uint32_t value) {
    return set_add_(cur, (void*) &value, UINT32);
}

/// Adds a value to given set if it contains 64-Bit integer
bool set_add_i64(set* cur, int64_t value) {
    return set_add_(cur, (void*) &value, INT64);
}

/// Adds a value to given set if it contains unsigned 64-Bit integer
bool set_add_u64(set* cur, uint64_t value) {
    return set_add_(cur, (void*) &value, UINT64);
}

/// Adds a value to given set if it contains 32-Bit floating points
bool set_add_f32(set* cur, float32 value) {
    return set_add_(cur, (void*) &value, FLOAT32);
}

/// Adds a value to given set if it contains 64-Bit floating points
bool set_add_f64(set* cur, float64 value) {
    return set_add_(cur, (void*) &value, FLOAT64);
}


/// Gets the minimum value from given set
/// TODO: change to cur->root->data !!!
bool set_min_i8(set* cur, int8_t* result) {
    if (cur == NULL || cur->size == 0) return false;

    *result = *((int8_t*) cur->root->data);
    node_t* cur_node = cur->root->next;

    while (cur_node != NULL) {
        int8_t now = *((int8_t*)cur_node->data);
        *result = *result < now ? *result : now;
        cur_node = cur_node->next;
    }

    return true;
}

bool set_min_u8(set* cur, uint8_t* result) {
    if (cur == NULL || cur->size == 0) return false;

    *result = *((uint8_t*) cur->root->data);
    node_t* cur_node = cur->root->next;

    while (cur_node != NULL) {
        uint8_t now = *((uint8_t*) cur_node->data);
        *result = *result < now ? *result : now;
        cur_node = cur_node->next;
    }

    return true;
}

bool set_min_i16(set* cur, int16_t* result) {
    if (cur == NULL || cur->size == 0) return false;

    *result = *((int16_t*) cur->root->data);
    node_t* cur_node = cur->root->next;

    while (cur_node != NULL) {
        int16_t now = *((int16_t*)cur_node->data);
        *result = *result < now ? *result : now;
        cur_node = cur_node->next;
    }

    return true;
}

bool set_min_u16(set* cur, uint16_t* result) {
    if (cur == NULL || cur->size == 0) return false;

    *result = *((uint16_t*) cur->root->data);
    node_t* cur_node = cur->root->next;

    while (cur_node != NULL) {
        uint16_t now = *((uint16_t*) cur_node->data);
        *result = *result < now ? *result : now;
        cur_node = cur_node->next;
    }

    return true;
}

bool set_min_i32(set* cur, int32_t* result) {
    if (cur == NULL || cur->size == 0) return false;

    *result = *((int32_t*) cur->root->data);
    node_t* cur_node = cur->root->next;

    while (cur_node != NULL) {
        int32_t now = *((int32_t*) cur_node->data);
        *result = *result < now ? *result : now;
        cur_node = cur_node->next;
    }

    return true;
}

bool set_min_u32(set* cur, uint32_t* result) {
    if (cur == NULL || cur->size == 0) return false;

    *result = *((uint32_t*) cur->root->data);
    node_t* cur_node = cur->root->next;

    while (cur_node != NULL) {
        uint32_t now = *((uint32_t*) cur_node->data);
        *result = *result < now ? *result : now;
        cur_node = cur_node->next;
    }

    return true;
}

bool set_min_i64(set* cur, int64_t* result) {
    if (cur == NULL || cur->size == 0) return false;

    *result = *((int64_t*) cur->root->data);
    node_t* cur_node = cur->root->next;

    while (cur_node != NULL) {
        int64_t now = *((int64_t*)cur_node->data);
        *result = *result < now ? *result : now;
        cur_node = cur_node->next;
    }

    return true;
}

bool set_min_u64(set* cur, uint64_t* result) {
    if (cur == NULL || cur->size == 0) return false;

    *result = *((uint64_t*) cur->root->data);
    node_t* cur_node = cur->root->next;

    while (cur_node != NULL) {
        uint64_t now = *((uint64_t*) cur_node->data);
        *result = *result < now ? *result : now;
        cur_node = cur_node->next;
    }

    return true;
}

bool set_min_f32(set* cur, float32* result) {
    if (cur == NULL || cur->size == 0) return false;

    *result = *((float32*) cur->root->data);
    node_t* cur_node = cur->root->next;

    while (cur_node != NULL) {
        float32 now = *((float32*)cur_node->data);
        *result = *result < now ? *result : now;
        cur_node = cur_node->next;
    }

    return true;
}

bool set_min_f64(set* cur, float64* result) {
    if (cur == NULL || cur->size == 0) return false;

    *result = *((float64*) cur->root->data);
    node_t* cur_node = cur->root->next;

    while (cur_node != NULL) {
        float64 now = *((float64*) cur_node->data);
        *result = *result < now ? *result : now;
        cur_node = cur_node->next;
    }

    return true;
}


/// Gets the maximum value from given set
/// TODO: change to cur->last->data !!!
bool set_max_i8(set* cur, int8_t* result) {
    if (cur == NULL || cur->size == 0) return false;

    *result = *((int8_t*) cur->root->data);
    node_t* cur_node = cur->root->next;

    while (cur_node != NULL) {
        int8_t now = *((int8_t*) cur_node->data);
        *result = *result > now ? *result : now;
        cur_node = cur_node->next;
    }

    return true;
}

bool set_max_u8(set* cur, uint8_t* result) {
    if (cur == NULL || cur->size == 0) return false;

    *result = *((uint8_t*) cur->root->data);
    node_t* cur_node = cur->root->next;

    while (cur_node != NULL) {
        uint8_t now = *((uint8_t*) cur_node->data);
        *result = *result > now ? *result : now;
        cur_node = cur_node->next;
    }

    return true;
}

bool set_max_i16(set* cur, int16_t* result) {
    if (cur == NULL || cur->size == 0) return false;

    *result = *((int16_t*) cur->root->data);
    node_t* cur_node = cur->root->next;

    while (cur_node != NULL) {
        int16_t now = *((int16_t*) cur_node->data);
        *result = *result > now ? *result : now;
        cur_node = cur_node->next;
    }

    return true;
}

bool set_max_u16(set* cur, uint16_t* result) {
    if (cur == NULL || cur->size == 0) return false;

    *result = *((uint16_t*) cur->root->data);
    node_t* cur_node = cur->root->next;

    while (cur_node != NULL) {
        uint16_t now = *((uint16_t*) cur_node->data);
        *result = *result > now ? *result : now;
        cur_node = cur_node->next;
    }

    return true;
}

bool set_max_i32(set* cur, int32_t* result) {
    if (cur == NULL || cur->size == 0) return false;

    *result = *((int32_t*) cur->root->data);
    node_t* cur_node = cur->root->next;

    while (cur_node != NULL) {
        int32_t now = *((int32_t*) cur_node->data);
        *result = *result > now ? *result : now;
        cur_node = cur_node->next;
    }

    return true;
}

bool set_max_u32(set* cur, uint32_t* result) {
    if (cur == NULL || cur->size == 0) return false;

    *result = *((uint32_t*) cur->root->data);
    node_t* cur_node = cur->root->next;

    while (cur_node != NULL) {
        uint32_t now = *((uint32_t*) cur_node->data);
        *result = *result > now ? *result : now;
        cur_node = cur_node->next;
    }

    return true;
}

bool set_max_i64(set* cur, int64_t* result) {
    if (cur == NULL || cur->size == 0) return false;

    *result = *((int64_t*) cur->root->data);
    node_t* cur_node = cur->root->next;

    while (cur_node != NULL) {
        int64_t now = *((int64_t*) cur_node->data);
        *result = *result > now ? *result : now;
        cur_node = cur_node->next;
    }

    return true;
}

bool set_max_u64(set* cur, uint64_t* result) {
    if (cur == NULL || cur->size == 0) return false;

    *result = *((uint64_t*) cur->root->data);
    node_t* cur_node = cur->root->next;

    while (cur_node != NULL) {
        uint64_t now = *((uint64_t*) cur_node->data);
        *result = *result > now ? *result : now;
        cur_node = cur_node->next;
    }

    return true;
}

bool set_max_f32(set* cur, float32* result) {
    if (cur == NULL || cur->size == 0) return false;

    *result = *((float32*) cur->root->data);
    node_t* cur_node = cur->root->next;

    while (cur_node != NULL) {
        float32 now = *((float32*) cur_node->data);
        *result = *result > now ? *result : now;
        cur_node = cur_node->next;
    }

    return true;
}

bool set_max_f64(set* cur, float64* result) {
    if (cur == NULL || cur->size == 0) return false;

    *result = *((float64*) cur->root->data);
    node_t* cur_node = cur->root->next;

    while (cur_node != NULL) {
        float64 now = *((float64*) cur_node->data);
        *result = *result > now ? *result : now;
        cur_node = cur_node->next;
    }

    return true;
}


/// Adds two sets together
// TODO: check if pointer is correct (no NULL pointer, etc)
bool set_union(set* A, set* B, set* out) {
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
    if (A->type == NONE) {
        *out = *B;
        return true;
    } else if (B->type == NONE) {
        *out = *A;
        return true;
    }

    // Float values
    TYPE otype = max(A->type, B->type);
    if (otype != NONE) {
        // 1) Create new set
        // 2) Loop over A, adding values to new set
        // 3) Loop over B, adding values to new set
    }
}