//
// Created by thahnen on 13.02.20.
//

#include <stdio.h>
#include <set.h>


int main(int argc, char* argv[]) {
    set* t1 = set_empty();

    printf("t1 size: %lu \n", t1->size);

    t1 = set_create(100);
    printf("t1 size: %lu \n", t1->size);
    printf("t1 first element value: %d \n", *((int32_t*)(t1->root->data)));
    printf("t1 last element value: %d \n", *((int32_t*)(t1->last->data)));
}