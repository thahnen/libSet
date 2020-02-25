//
// Created by thahnen on 12.02.20.
//

#ifndef LIBSET_LL_H
#define LIBSET_LL_H

#include <stdlib.h>


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
node_t* node_create(void* ndata, size_t size) {
    node_t* new = (node_t*) malloc(sizeof(node_t));
    new->next = NULL;

    // Copy byte per byte (we do not know which data type given!)
    new->data = malloc(size);
    for (int i = 0; i < size; i++) {
        *((uint8_t*)(new->data+i)) = *((uint8_t*)(ndata+i));
    }

    return new;
}


/**
 *  Deletes the given node and returns its successor
 *  Also sets data to NULL but does not free cur->next!
 *
 *  @param cur      the node to destroy
 *  @return         the next node
 */
node_t* node_delete(node_t* cur) {
    node_t* next = cur->next;
    free(cur->data);
    cur->data = NULL;
    free(cur);
    return next;
}


#endif //LIBSET_LL_H
