//
// Created by thahnen on 04.10.21.
//

#pragma once
#ifndef LIBSET_TEST_UNITTESTS_H
#define LIBSET_TEST_UNITTESTS_H

#include <assert.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <set.h>
#include <check.h>

#ifndef MAIN
#   define EXTERN extern
#else
#   define EXTERN
#endif


// Unittests.c: main test suite
EXTERN Suite* test_suite;

// test_set_empty.c: test cases for set_empty function
EXTERN TCase* empty;
void empty_testcases(void);

// test_set_create.c: test cases for set_create* functions
EXTERN TCase* create_i8;
EXTERN TCase* create_u8;
EXTERN TCase* create_i16;
EXTERN TCase* create_u16;
EXTERN TCase* create_i32;
EXTERN TCase* create_u32;
EXTERN TCase* create_i64;
EXTERN TCase* create_u64;
EXTERN TCase* create_f32;
EXTERN TCase* create_f64;
void create_testcases(void);

// test_set_add.c: test cases fot set_add* functions
EXTERN TCase* add;
void add_testcases(void);


#endif //LIBSET_TEST_UNITTESTS_H
