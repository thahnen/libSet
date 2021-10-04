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

#define NOT$NULL


/* ==============================================================================================
                                    ACTUAL IMPLEMENTATION
   ============================================================================================== */

/// Struct holds an item as set stores data in single linked lists
typedef struct node {
    void* data;
    struct node* next;
} node_t;


/**
 *  Creates a new node for the set
 *
 *  @param ndata    void pointer to given data (to make it more generic)
 *  @return         new node holding the given data, has no successor
 */
static node_t* node_create(NOT$NULL void* ndata, size_t size) {
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
static node_t* node_delete(NOT$NULL node_t* cur) {
    node_t* next = cur->next;
    free(cur->data);
    cur->data = NULL;
    free(cur);
    cur = NULL;
    return next;
}


#endif //LIBSET_LL_H
