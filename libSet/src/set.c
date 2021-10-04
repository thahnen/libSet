//
// Created by thahnen on 12.02.20.
//

#include <stdlib.h>
#include "set.h"


/* ==============================================================================================
                                    HELPER FUNCTIONS & MACROS
   ============================================================================================== */

/**
 *  Creates a deep copy of a set
 *
 *  @param input set to be copied
 *  @return true if element contained in set, false otherwise
 *
 *  TODO: Add support for pair!
 */
static set* deepCopy(NOT$NULL set* input) {
    set* output = set_empty();
    
    TYPE type = input->type;
    if (type != NONE) {
        node_t* curNode = input->root;
        
        do {
            switch(type) {
                case INT8:    set_add_i8(output,  *(int8_t*)curNode->data);   break;
                case UINT8:   set_add_u8(output,  *(uint8_t*)curNode->data);  break;
                case INT16:   set_add_i16(output, *(int16_t*)curNode->data);  break;
                case UINT16:  set_add_u16(output, *(uint16_t*)curNode->data); break;
                case INT32:   set_add_i32(output, *(int32_t*)curNode->data);  break;
                case UINT32:  set_add_u32(output, *(uint32_t*)curNode->data); break;
                case INT64:   set_add_i64(output, *(int64_t*)curNode->data);  break;
                case UINT64:  set_add_u64(output, *(uint64_t*)curNode->data); break;
                case FLOAT32: set_add_f32(output, *(float32*)curNode->data);  break;
                case FLOAT64: set_add_f64(output, *(float64*)curNode->data);  break;
            }
            
            curNode = curNode->next;
        } while (curNode);
    }
    
    return output;
}


/**
 *  Checks if a element is containd in set
 *
 *  @param other_set void pointer to the item to use on creation
 *  @param data the elements data to check agains
 *  @param type the maximum type, NONE / PAIR is not allowed
 *  @return true if element contained in set, false otherwise
 *
 *  TODO: Add support for pair!
 */
static bool elementOf(NOT$NULL set* other_set, NOT$NULL void* data, TYPE type) {
    node_t* curNode = other_set->root;

    do {
        if (type == INT8 || type == UINT8)                           { if ((*(int8_t*)curNode->data)  == (*(int8_t*)data))  return true; } \
        else if (type == INT16 || type == UINT16)                    { if ((*(int16_t*)curNode->data) == (*(int16_t*)data)) return true; } \
        else if (type == INT32 || type == UINT32 || type == FLOAT32) { if ((*(int32_t*)curNode->data) == (*(int32_t*)data)) return true; } \
        else if (type == INT64 || type == UINT64 || type == FLOAT64) { if ((*(int64_t*)curNode->data) == (*(int64_t*)data)) return true; } \
        
        curNode = curNode->next;
    } while (curNode);
    
    return false;
}


/* ==============================================================================================
                                    ACTUAL IMPLEMENTATION
   ============================================================================================== */

/**
 *  Creates a new set with one value from given type
 *
 *  @param value void pointer to the item to use on creation
 *  @param type the type of the item behind the pointer
 *  @return true if operation successful, false otherwise
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
    set* set_create_i##powerOfTwo (int##powerOfTwo##_t value) { \
        return set_create_((void*) &value, INT##powerOfTwo ); \
    }

#define set_create_u(powerOfTwo) \
    set* set_create_u##powerOfTwo (uint##powerOfTwo##_t value) { \
        return set_create_((void*) &value, UINT##powerOfTwo ); \
    }

#define set_create_f(powerOfTwo) \
    set* set_create_f##powerOfTwo (float##powerOfTwo value) { \
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
 *  @param cur the existing set to add to
 *  @param value void pointer to the item to add
 *  @param type the type of the item behind the pointer
 *  @return true if operation successful, false otherwise
 *
 *  TODO: Add support for pair!
 */
static bool set_add_(NOT$NULL set* restrict cur, NOT$NULL void* restrict value, TYPE type) {
    // 1) type not allowed to be NONE
    if (type == NONE) return false;
    
    // 2) if set is empty create new set of given type and return success
    if (cur->type == NONE) {
        *cur = *set_create_(value, type);
        return true;
    }
    
    // 3) check if types of set and new value doesn't match
    //    TODO: Maybe handle in future using maximum of both types!
    if (cur->type != type) return false;

    // 4) check if value already in set
    node_t* curNode = cur->root;
    while (curNode->next != NULL) {
        switch (type) {
        case INT8:
        case UINT8:
            if (*(int8_t*)curNode->data == *(int8_t*)value)   return true;
            break;
        case INT16:
        case UINT16:
            if (*(int16_t*)curNode->data == *(int16_t*)value) return true;
            break;
        case INT32:
        case UINT32:
        case FLOAT32:
            if (*(int32_t*)curNode->data == *(int32_t*)value) return true;
            break;
        case INT64:
        case UINT64:
        case FLOAT64:
            if (*(int64_t*)curNode->data == *(int64_t*)value) return true;
            break;
        default:
            // pair not implemented yet & NONE impossible
            return false;
        }

        curNode = curNode->next;
    }

    // 4) value not in set, needs to be added
    curNode->next = node_create(value, getSize(type));
    cur->size++;

    return true;
}


#define set_add_i(powerOfTwo) \
    bool set_add_i##powerOfTwo (NOT$NULL set* cur, int##powerOfTwo##_t value) { \
        return set_add_(cur, (void*) &value, INT##powerOfTwo );\
    }

#define set_add_u(powerOfTwo) \
    bool set_add_u##powerOfTwo (NOT$NULL set* cur, uint##powerOfTwo##_t value) { \
        return set_add_(cur, (void*) &value, UINT##powerOfTwo );\
    }

#define set_add_f(powerOfTwo) \
    bool set_add_f##powerOfTwo (NOT$NULL set* cur, float##powerOfTwo value) { \
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
    bool set_min_i##powerOfTwo (NOT$NULL set* restrict cur, NOT$NULL int##powerOfTwo##_t* restrict result) { \
        if (cur == NULL || result == NULL || cur->type != INT##powerOfTwo || cur->size == 0) return false; \
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
    bool set_min_u##powerOfTwo (NOT$NULL set* restrict cur, NOT$NULL uint##powerOfTwo##_t* restrict result) { \
        if (cur == NULL || result == NULL || cur->type != UINT##powerOfTwo || cur->size == 0) return false; \
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
    bool set_min_f##powerOfTwo (NOT$NULL set* restrict cur, NOT$NULL float##powerOfTwo * restrict result) { \
        if (cur == NULL || result == NULL || cur->type != FLOAT##powerOfTwo || cur->size == 0) return false; \
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
    bool set_max_i##powerOfTwo (NOT$NULL set* restrict cur, NOT$NULL int##powerOfTwo##_t* restrict result) { \
        if (cur->type != INT##powerOfTwo || cur->size == 0) return false; \
        *result = *((int##powerOfTwo##_t*) cur->root->data); \
        node_t* cur_node = cur->root->next; \
        while (cur_node != NULL) { \
            int##powerOfTwo##_t now = *((int##powerOfTwo##_t*) cur_node->data); \
            *result = *result > now ? *result : now; \
            cur_node = cur_node->next; \
        } \
    }

#define set_max_u(powerOfTwo) \
    bool set_max_u##powerOfTwo (NOT$NULL set* restrict cur, NOT$NULL uint##powerOfTwo##_t* restrict result) { \
        if (cur->type != UINT##powerOfTwo || cur->size == 0) return false; \
        *result = *((uint##powerOfTwo##_t*) cur->root->data); \
        node_t* cur_node = cur->root->next; \
        while (cur_node != NULL) { \
            uint##powerOfTwo##_t now = *((uint##powerOfTwo##_t*) cur_node->data); \
            *result = *result > now ? *result : now; \
            cur_node = cur_node->next; \
        } \
    }

#define set_max_f(powerOfTwo) \
    bool set_max_f##powerOfTwo (NOT$NULL set* restrict cur, NOT$NULL float##powerOfTwo * restrict result) { \
        if (cur->type != FLOAT##powerOfTwo || cur->size == 0) return false; \
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
bool set_union(NOT$NULL set* A, NOT$NULL set* B, NOT$NULL set* out) {
    // Return empty set if A and B is empty and return B if A is empty and return A if B is empty
    if (A->type == NONE && B->type == NONE) {
        *out = *set_empty();
        return true;
    } else if (A->type == NONE) {
        *out = *deepCopy(B);
        return true;
    } else if (B->type == NONE) {
        *out = *deepCopy(A);
        return true;
    } else if (A->type == PAIR || B->type == PAIR) {
        // TODO: Pairs not implemented yet!
        return false;
    }

    // All other values!
    TYPE otype = max(A->type, B->type);
    if (otype != NONE) {
        // 1) Create new set
        *out = *set_empty();
        
        // 2) define macro
#define loop(element, output_set, type) \
        do { \
            switch(type) { \
                case INT8:    set_add_i8(output_set,  *(int8_t*)element->data);   break; \
                case UINT8:   set_add_u8(output_set,  *(uint8_t*)element->data);  break; \
                case INT16:   set_add_i16(output_set, *(int16_t*)element->data);  break; \
                case UINT16:  set_add_u16(output_set, *(uint16_t*)element->data); break; \
                case INT32:   set_add_i32(output_set, *(int32_t*)element->data);  break; \
                case UINT32:  set_add_u32(output_set, *(uint32_t*)element->data); break; \
                case INT64:   set_add_i64(output_set, *(int64_t*)element->data);  break; \
                case UINT64:  set_add_u64(output_set, *(uint64_t*)element->data); break; \
                case FLOAT32: set_add_f32(output_set, *(float32*)element->data);  break; \
                case FLOAT64: set_add_f64(output_set, *(float64*)element->data);  break; \
            } \
            element = element->next; \
        } while (element);

        // 3) Loop over A, adding values to new set
        node_t* cur = A->root;
        loop(cur, out, otype)

        // 4) Loop over B, adding values to new set
        cur = B->root;
        loop(cur, out, otype)
        
        // 5) undefine macro
#undef loop

        return true;
    }

    return false;
}


/// intersects to sets
bool set_intersect(NOT$NULL set* A, NOT$NULL set* B, NOT$NULL set* out) {
    // Return empty set if A or B is empty set
    if (A->type == NONE || B->type == NONE) {
        *out = *set_empty();
        return true;
    } else if (A->type == PAIR || B->type == PAIR) {
        // TODO: Pairs not implemented yet!
        return false;
    }
    
    // Get maximum type
    TYPE otype = max(A->type, B->type);
    if (otype != NONE) {
        // 1) create new set
        *out = *set_empty();
        
        // 2) define macro
#define loop(element, other_set, output_set, type) \
        do { \
            if (elementOf(other_set, element->data, type)) { \
                switch(type) { \
                    case INT8:    set_add_i8(output_set,  *(int8_t*)element->data);   break; \
                    case UINT8:   set_add_u8(output_set,  *(uint8_t*)element->data);  break; \
                    case INT16:   set_add_i16(output_set, *(int16_t*)element->data);  break; \
                    case UINT16:  set_add_u16(output_set, *(uint16_t*)element->data); break; \
                    case INT32:   set_add_i32(output_set, *(int32_t*)element->data);  break; \
                    case UINT32:  set_add_u32(output_set, *(uint32_t*)element->data); break; \
                    case INT64:   set_add_i64(output_set, *(int64_t*)element->data);  break; \
                    case UINT64:  set_add_u64(output_set, *(uint64_t*)element->data); break; \
                    case FLOAT32: set_add_f32(output_set, *(float32*)element->data);  break; \
                    case FLOAT64: set_add_f64(output_set, *(float64*)element->data);  break; \
                } \
            } \
            element = element->next; \
        } while (element);
        
        // 3) loop over A
        node_t* cur = A->root;
        loop(cur, B, out, otype)
        
        // 4) loop over B
        cur = B->root;
        loop(cur, A, out, otype)
        
        // 5) undefine macro
#undef loop
        
        return true;
    }
    
    return false;
}


/// difference of two sets
bool set_difference(NOT$NULL set* A, NOT$NULL set* B, NOT$NULL set* out) {
    // Return empty set if A is empty and return A if B is empty
    if (A->type == NONE) {
        *out = *set_empty();
        return true;
    } else if (B->type == NONE) {
        *out = *deepCopy(A);
        return true;
    } else if (A->type == PAIR || B->type == PAIR) {
        // TODO: Pairs not implemented yet!
        return false;
    }
    
    // Get maximum type
    TYPE otype = max(A->type, B->type);
    if (otype != NONE) {
        // 1) create new set
        *out = *set_empty();
        
        // 2) loop over A
        node_t* cur = A->root;
        do {
            if (!elementOf(out, cur->data, otype)) {
                switch(otype) {
                    case INT8:    set_add_i8(out,  *(int8_t*)cur->data);   break;
                    case UINT8:   set_add_u8(out,  *(uint8_t*)cur->data);  break;
                    case INT16:   set_add_i16(out, *(int16_t*)cur->data);  break;
                    case UINT16:  set_add_u16(out, *(uint16_t*)cur->data); break;
                    case INT32:   set_add_i32(out, *(int32_t*)cur->data);  break;
                    case UINT32:  set_add_u32(out, *(uint32_t*)cur->data); break;
                    case INT64:   set_add_i64(out, *(int64_t*)cur->data);  break;
                    case UINT64:  set_add_u64(out, *(uint64_t*)cur->data); break;
                    case FLOAT32: set_add_f32(out, *(float32*)cur->data);  break;
                    case FLOAT64: set_add_f64(out, *(float64*)cur->data);  break;
                }
            }
            
            cur = cur->next;
        } while (cur);
        
        return true;
    }
    
    return false;
}


/// symmetric difference of two sets
bool set_symdifference(NOT$NULL set* A, NOT$NULL set* B, NOT$NULL set* out) {
    // Return B if A is empty and return A if B is empty
    if (A->type == NONE) {
        *out = *deepCopy(B);
        return true;
    } else if (B->type == NONE) {
        *out = *deepCopy(A);
        return true;
    } else if (A->type == PAIR || B->type == PAIR) {
        return false;
    }
    
    // Get maximum type
    TYPE otype = max(A->type, B->type);
    if (otype != NONE) {
        // 1) create new set
        *out = *set_empty();
        
        // 2) define macro
#define loop(element, other_set, output_set, type) \
        do { \
            if (!elementOf(other_set, element->data, type)) { \
                switch(type) { \
                    case INT8:    set_add_i8(output_set,  *(int8_t*)element->data);   break; \
                    case UINT8:   set_add_u8(output_set,  *(uint8_t*)element->data);  break; \
                    case INT16:   set_add_i16(output_set, *(int16_t*)element->data);  break; \
                    case UINT16:  set_add_u16(output_set, *(uint16_t*)element->data); break; \
                    case INT32:   set_add_i32(output_set, *(int32_t*)element->data);  break; \
                    case UINT32:  set_add_u32(output_set, *(uint32_t*)element->data); break; \
                    case INT64:   set_add_i64(output_set, *(int64_t*)element->data);  break; \
                    case UINT64:  set_add_u64(output_set, *(uint64_t*)element->data); break; \
                    case FLOAT32: set_add_f32(output_set, *(float32*)element->data);  break; \
                    case FLOAT64: set_add_f64(output_set, *(float64*)element->data);  break; \
                } \
            } \
            element = element->next; \
        } while (element);
        
        // 3) loop over A
        node_t* cur = A->root;
        loop(cur, B, out, otype)
        
        // 4) loop over B
        cur = B->root;
        loop(cur, A, out, otype)
        
        // 5) undefine macro
#undef loop
        
        return true;
    }
    
    return false;
}
