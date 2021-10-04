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

// test_set_add.c: test cases for set_add* functions
EXTERN TCase* add_i8;
EXTERN TCase* add_u8;
EXTERN TCase* add_i16;
EXTERN TCase* add_u16;
EXTERN TCase* add_i32;
EXTERN TCase* add_u32;
EXTERN TCase* add_i64;
EXTERN TCase* add_u64;
EXTERN TCase* add_f32;
EXTERN TCase* add_f64;
void add_testcases(void);

// test_set_min.c: test cases for set_min* functions
EXTERN TCase* min_i8;
EXTERN TCase* min_u8;
EXTERN TCase* min_i16;
EXTERN TCase* min_u16;
EXTERN TCase* min_i32;
EXTERN TCase* min_u32;
EXTERN TCase* min_i64;
EXTERN TCase* min_u64;
EXTERN TCase* min_f32;
EXTERN TCase* min_f64;
void min_testcases(void);

// test_set_max.c: test cases for set_max* functions
EXTERN TCase* max_i8;
EXTERN TCase* max_u8;
EXTERN TCase* max_i16;
EXTERN TCase* max_u16;
EXTERN TCase* max_i32;
EXTERN TCase* max_u32;
EXTERN TCase* max_i64;
EXTERN TCase* max_u64;
EXTERN TCase* max_f32;
EXTERN TCase* max_f64;
void max_testcases(void);

// test_set_union.c: test cases for set_union function
// TODO: Implement!
EXTERN TCase* union_i8;
EXTERN TCase* union_u8;
EXTERN TCase* union_i16;
EXTERN TCase* union_u16;
EXTERN TCase* union_i32;
EXTERN TCase* union_u32;
EXTERN TCase* union_i64;
EXTERN TCase* union_u64;
EXTERN TCase* union_f32;
EXTERN TCase* union_f64;
void union_testcases();

// test_set_intersect.c: test cases for set_intersect function
// TODO: Implement!
EXTERN TCase* intersect_i8;
EXTERN TCase* intersect_u8;
EXTERN TCase* intersect_i16;
EXTERN TCase* intersect_u16;
EXTERN TCase* intersect_i32;
EXTERN TCase* intersect_u32;
EXTERN TCase* intersect_i64;
EXTERN TCase* intersect_u64;
EXTERN TCase* intersect_f32;
EXTERN TCase* intersect_f64;
void intersect_testcases();

// test_set_difference.c: test cases for set_difference function
// TODO: Implement!
EXTERN TCase* difference_i8;
EXTERN TCase* difference_u8;
EXTERN TCase* difference_i16;
EXTERN TCase* difference_u16;
EXTERN TCase* difference_i32;
EXTERN TCase* difference_u32;
EXTERN TCase* difference_i64;
EXTERN TCase* difference_u64;
EXTERN TCase* difference_f32;
EXTERN TCase* difference_f64;
void difference_testcases();

// test_set_symdifference.c: test cases for set_symdifference function
// TODO: Implement!
EXTERN TCase* symdifference_i8;
EXTERN TCase* symdifference_u8;
EXTERN TCase* symdifference_i16;
EXTERN TCase* symdifference_u16;
EXTERN TCase* symdifference_i32;
EXTERN TCase* symdifference_u32;
EXTERN TCase* symdifference_i64;
EXTERN TCase* symdifference_u64;
EXTERN TCase* symdifference_f32;
EXTERN TCase* symdifference_f64;
void symdifference_testcases();


#endif //LIBSET_TEST_UNITTESTS_H
