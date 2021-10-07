//
// Created by thahnen on 12.02.20.
//

#pragma once
#ifndef LIBSET_LL_H
#define LIBSET_LL_H

#include <stdlib.h>
#include <string.h>


/* ==============================================================================================
                                    HELPER FUNCTIONS & MACROS
   ============================================================================================== */

#if defined(__clang__)
#   define NONNULL(arr)     __attribute__ ((nonnull arr))
#   define NONNULLRETURN    __attribute__ ((returns_nonnull))
#   define NULLABLE         _Nullable
#elif defined(__GNUC__)
#   define NONNULL(arr)     __attribute__ ((nonnull arr))
#   define NONNULLRETURN
#   define NULLABLE
#else
#   define NONNULL(arr)
#   define NULLABLE
#endif


/* ==============================================================================================
                                    ACTUAL IMPLEMENTATION
   ============================================================================================== */

/// Struct holds an item as set stores data in single linked lists
typedef struct node {
    void* data;
    struct node* next;
} node_t;


// forward definition
static node_t* node_create(void* ndata, size_t size) NONNULL((1)) NONNULLRETURN;
static node_t* node_delete(node_t* cur) NONNULL((1));


/**
 *  Creates a new node for the set
 *
 *  @param ndata    void pointer to given data (to make it more generic)
 *  @return         new node holding the given data, has no successor
 */
static node_t* node_create(void* ndata, size_t size) {
    node_t* new = (node_t*) malloc(sizeof(node_t));
    new->next = NULL;

    // Copy byte per byte
    new->data = malloc(size);
    memcpy(new->data, ndata, size);

    return new;
}


/**
 *  Deletes the given node and returns its successor
 *
 *  @param cur      the node to delete
 *  @return         the next node
 */
static node_t* node_delete(node_t* cur) {
    node_t* next = cur->next;
    free(cur->data);
    cur->data = NULL;
    free(cur);
    cur = NULL;
    return next;
}


#endif //LIBSET_LL_H
