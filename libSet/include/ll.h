//
// Created by thahnen on 12.02.20.
//

#ifndef LIBSET_LL_H
#define LIBSET_LL_H


typedef struct node {
    void* data;
    struct node* next;
} node_t;


node_t* node_create(void* ndata) {
    node_t* new = (node_t*) malloc(sizeof(node_t));
    new->data = ndata;
    new->next = NULL;
    return new;
}


#endif //LIBSET_LL_H
