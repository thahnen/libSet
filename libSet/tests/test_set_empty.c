//
// Created by thahnen on 04.10.21.
//

#include "Unittests.h"


/// test cases on set_empty function
START_TEST(test_set_empty) {
    set* t1 = set_empty();
    
    ck_assert_int_eq(t1->size, 0);
    ck_assert_int_eq(t1->type, NONE);
    ck_assert_ptr_eq(t1->root, NULL);
} END_TEST


// create & add tests
void empty_testcases(void) {
    empty = tcase_create("set_empty");
    tcase_add_test(empty, test_set_empty);
    suite_add_tcase(test_suite, empty);
}
