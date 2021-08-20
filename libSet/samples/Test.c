//
// Created by thahnen on 13.02.20.
//

#include <stdio.h>
#include <assert.h>
#include <set.h>
#include <check.h>


START_TEST(test_set_empty) {
    set* t1 = set_empty();
    
    ck_assert_int_eq(t1->size, 0);
    ck_assert_int_eq(t1->type, NONE);
    ck_assert_ptr_eq(t1->root, NULL);
} END_TEST


int main(void) {
    Suite* suite = suite_create("Set-Suite");
    
    TCase* empty = tcase_create("set_empty");
    tcase_add_test(empty, test_set_empty);
    
    suite_add_tcase(suite, empty);
    
    SRunner* runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
