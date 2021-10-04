//
// Created by thahnen on 04.10.21.
//

#define MAIN
#include "Unittests.h"


/// init variables
void init_unittests(void) {
    // main test suite
    test_suite = suite_create("Set-Suite");

    // add test cases to suite
    empty_testcases();
    create_testcases();
}


/// run test cases and return number of failed tests
int run_unittests(void) {
    SRunner* runner = srunner_create(test_suite);
    srunner_run_all(runner, CK_NORMAL);
    
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}


/// main test runner
int main(void) {
    printf("Test environment: %d bit\n", (int)(CHAR_BIT * sizeof(void*)));

    init_unittests();
    int failed = run_unittests();

    return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
