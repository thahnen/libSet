//
// Created by thahnen on 13.02.20.
//

#include <stdio.h>
#include <assert.h>
#include <set.h>


int main(int argc, char* argv[]) {
    /*
     *  Assertions on custom structure sizes
     *
     *  1) enum TYPE        == 1 byte
     *  2) struct node_t    == 16 byte
     *  2) struct set       == 25 byte
     *      set->type = 1 byte (enum TYPE)
     *      set->size = 8 byte (unsigned long)
     *      set->root = 8 byte (node_t*)
     *      set->last = 8 byte (node_t*)
     */

    printf("Size of enum 'Type': %lu Byte\n", sizeof(TYPE));
    printf("Size of struct 'node_t': %lu Byte\n", sizeof(node_t));
    printf("Size of struct 'set': %lu Byte\n", sizeof(set));


    // All variables used!
    set* t1;
    int32_t first, second, third, min, max;

    /*
     *  Assertions on set_empty function!
     *
     *  1) set->size == 0
     *  2) set->type == NONE
     *  3) set->root == NULL
     */
    t1 = set_empty();
    assert(t1->size == 0);
    assert(t1->type == NONE);
    assert(t1->root == NULL);

    printf("t1 size: %lu \n", t1->size);


    /*
     *  Assertions on set_create_i32 function!
     *
     *  1) set->size == 1
     *  2) set->type == INT32
     *  3) set->root != NULL
     *      &&  set->root->data != NULL
     *      &&  *((int32_t*)set->root->data) == 100
     */
    t1 = set_create_i32(100);
    assert(t1->size == 1);
    assert(t1->type == INT32);
    assert(t1->root != NULL && t1->root->data != NULL && *((int32_t*)t1->root->data) == 100);

    first = *((int32_t*)t1->root->data);
    printf("t1 size: %lu \n", t1->size);
    printf("t1 first element value: %d \n", first);


    /*
     *  Assertions on set_add_i32 function!
     *
     *  1) set->size == 2
     *  2) set->type == INT32
     *  3) set->root != NULL
     *      &&  set->root->data != NULL
     *      &&  *((int32_t*)set->root->data) == 100
     *  4) set->root->next != NULL
     *      &&  set->root->next != NULL
     *      &&  *((int32_t*)set->root->next->data) == 101
     */
    if (!set_add_i32(t1, 101)) {
        printf("Adding value to set error!\n");
        return EXIT_FAILURE;
    }
    assert(t1->size == 2);
    assert(t1->type == INT32);
    assert(t1->root != NULL && t1->root->data != NULL && *((int32_t*)t1->root->data) == 100);
    assert(t1->root->next != NULL && t1->root->next->data != NULL && *((int32_t*)t1->root->next->data) == 101);

    first = *((int32_t*)t1->root->data);
    second = *((int32_t*)t1->root->next->data);
    printf("t1 size: %lu \n", t1->size);
    printf("t1 first element value: %d \n", first);
    printf("t1 second element value: %d \n", second);


    /*
     *  Assertions on set_add_i32 function!
     *
     *  1) set->size == 3
     *  2) set->type == INT32
     *  3) set->root != NULL
     *      &&  set->root->data != NULL
     *      &&  *((int32_t*)set->root->data) == 100
     *  4) set->root->next != NULL
     *      &&  set->root->next->data != NULL
     *      &&  *((int32_t*)set->root->next->data) == 101
     *  5) set->root->next->next != NULL
     *      &&  set->root->next->next->data != NULL
     *      &&  *((int32_t*)set->root->next->next->data) == 102
     */
    if (!set_add_i32(t1, 102)) {
        printf("Adding value to set error!\n");
        return EXIT_FAILURE;
    }
    assert(t1->size == 3);
    assert(t1->type == INT32);
    assert(t1->root != NULL && t1->root->data != NULL && *((int32_t*)t1->root->data) == 100);
    assert(t1->root->next != NULL && t1->root->next->data != NULL && *((int32_t*)t1->root->next->data) == 101);
    assert(t1->root->next->next != NULL && t1->root->next->next->data != NULL
            && *((int32_t*)t1->root->next->next->data) == 102);

    first = *((int32_t*)(t1->root->data));
    second = *((int32_t*)t1->root->next->data);
    third = *((int32_t*)(t1->root->next->next->data));
    printf("t1 size: %lu \n", t1->size);
    printf("t1 first element value: %d \n", first);
    printf("t1 middle element value: %d \n", second);
    printf("t1 last element value: %d \n", third);


    /*
     *  Assertions on set_min_i32 function!
     *
     *  1) min(set) = 100
     */
    if (!set_min_i32(t1, &min)) {
        printf("Getting minimum value does not work correctly!\n");
        return EXIT_FAILURE;
    }
    assert(min == 100);

    printf("t1 minimum element value: %d \n", min);


    /*
     *  Assertions on set_min_i32 function!
     *
     *  2) min(set) = 100
     */
    if (!set_max_i32(t1, &max)) {
        printf("Getting maximum value does not work correctly!\n");
        return EXIT_FAILURE;
    }
    assert(max == 102);

    printf("t1 maximum element value: %d \n", max);
}