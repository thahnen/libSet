//
// Created by thahnen on 12.02.20.
//

#include <stdlib.h>
#include "set.h"


/// Creates an empty set
set* set_empty() {
    set* new = (set*) malloc(sizeof(set));
    new->type = VOID;
    new->size = 0;
    new->root = NULL;
    new->last = NULL;
    return new;
}


// TODO: maybe merge this later with an append function!
static void set_value(set* set_, void* value) {
    set_->root = node_create(value);
    set_->last = set_->root;
}


/// Creates a new set with one value from given type
static set* set_create_(void* value, enum TYPE ntype) {
    if (ntype == VOID) {
        return NULL;
    }

    set* new = (set*) malloc(sizeof(set));
    new->type = ntype;
    new->size = 1;
    set_value(new, value);

    return new;
}

/// Creates a new set with one 8-Bit integer item
set* set_create_i8(int8_t value) {
    return set_create_((void*)&value, INT8);
}

/// Creates a new set with one unsigned 8-Bit integer item
set* set_create_u8(uint8_t value) {
    return set_create_((void*)&value, UINT8);
}

/// Creates a new set with one 16-Bit integer item
set* set_create_i16(int16_t value) {
    return set_create_((void*)&value, INT16);
}

/// Creates a new set with one unsigned 16-Bit integer item
set* set_create_u16(uint16_t value) {
    return set_create_((void*)&value, UINT16);
}

/// Creates a new set with one 32-Bit integer item
set* set_create_i32(int32_t value) {
    return set_create_((void*)&value, INT32);
}

/// Creates a new set with one unsigned 32-Bit integer item
set* set_create_u32(uint32_t value) {
    return set_create_((void*)&value, UINT32);
}

/// Creates a new set with one 64-Bit integer item
set* set_create_i64(int64_t value) {
    return set_create_((void*)&value, INT64);
}

/// Creates a new set with one unsigned 64-Bit integer item
set* set_create_u64(uint64_t value) {
    return set_create_((void*)&value, UINT64);
}

/// Creates a new set with one 32-Bit floating point item
set* set_create_f32(float32 value) {
    return set_create_((void*)&value, FLOAT32);
}

/// Creates a new set with one 64-Bit floating point item
set* set_create_f64(float64 value) {
    return set_create_((void*)&value, FLOAT64);
}