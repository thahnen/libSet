//
// Created by thahnen on 04.10.21.
//

#include "Unittests.h"


/// test cases on set_min* function
START_TEST(test_set_min_i8) {
    int8_t value = INT8_MIN;
    set* t1 = set_create_i8(value);
    set_add_i8(t1, INT8_MAX);
    
    int8_t minimum = 1;
    set_min_i8(t1, &minimum);
    
    ck_assert_int_eq(minimum, INT8_MIN);
    
    
} END_TEST

START_TEST(test_set_min_u8) {
    uint8_t value = 0;
    set* t1 = set_create_u8(value);
    set_add_u8(t1, UINT8_MAX);
    
    uint8_t minimum = 1;
    set_min_u8(t1, &minimum);
    
    ck_assert_int_eq(minimum, 0);
} END_TEST


START_TEST(test_set_min_i16) {
    int16_t value = INT16_MIN;
    set* t1 = set_create_i16(value);
    set_add_i16(t1, INT16_MAX);
    
    int16_t minimum = 1;
    set_min_i16(t1, &minimum);
    
    ck_assert_int_eq(minimum, INT16_MIN);
    
    
} END_TEST

START_TEST(test_set_min_u16) {
    uint16_t value = 0;
    set* t1 = set_create_u16(value);
    set_add_u16(t1, UINT16_MAX);
    
    uint16_t minimum = 1;
    set_min_u16(t1, &minimum);
    
    ck_assert_int_eq(minimum, 0);
} END_TEST


START_TEST(test_set_min_i32) {
    int32_t value = INT32_MIN;
    set* t1 = set_create_i32(value);
    set_add_i32(t1, INT32_MAX);
    
    int32_t minimum = 1;
    set_min_i32(t1, &minimum);
    
    ck_assert_int_eq(minimum, INT32_MIN);
    
    
} END_TEST

START_TEST(test_set_min_u32) {
    uint32_t value = 0;
    set* t1 = set_create_u32(value);
    set_add_u32(t1, UINT32_MAX);
    
    uint32_t minimum = 1;
    set_min_u32(t1, &minimum);
    
    ck_assert_int_eq(minimum, 0);
} END_TEST


START_TEST(test_set_min_i64) {
    int64_t value = INT64_MIN;
    set* t1 = set_create_i64(value);
    set_add_i64(t1, INT64_MAX);
    
    int64_t minimum = 1;
    set_min_i64(t1, &minimum);
    
    ck_assert_int_eq(minimum, INT64_MIN);
    
    
} END_TEST

START_TEST(test_set_min_u64) {
    uint64_t value = 0;
    set* t1 = set_create_u64(value);
    set_add_u64(t1, UINT64_MAX);
    
    uint64_t minimum = 1;
    set_min_u64(t1, &minimum);
    
    ck_assert_int_eq(minimum, 0);
} END_TEST


START_TEST(test_set_min_f32) {
    float32 value = FLT_MIN;
    set* t1 = set_create_f32(value);
    set_add_f32(t1, FLT_MAX);
    
    float32 minimum = 1;
    set_min_f32(t1, &minimum);
    
    ck_assert_float_eq(minimum, FLT_MIN);
} END_TEST

START_TEST(test_set_min_f64) {
    float64 value = DBL_MIN;
    set* t1 = set_create_f64(value);
    set_add_f64(t1, DBL_MAX);
    
    float64 minimum = 1;
    set_min_f64(t1, &minimum);
    
    ck_assert_double_eq(minimum, DBL_MIN);
} END_TEST


// create & add tests
void min_testcases(void) {
    min_i8 = tcase_create("set_min_i8");
    tcase_add_test(min_i8, test_set_min_i8);
    suite_add_tcase(test_suite, min_i8);

    min_u8 = tcase_create("set_min_u8");
    tcase_add_test(min_u8, test_set_min_u8);
    suite_add_tcase(test_suite, min_u8);
    
    min_i16 = tcase_create("set_min_i16");
    tcase_add_test(min_i16, test_set_min_i16);
    suite_add_tcase(test_suite, min_i16);

    min_u16 = tcase_create("set_min_u16");
    tcase_add_test(min_u16, test_set_min_u16);
    suite_add_tcase(test_suite, min_u16);
    
    min_i32 = tcase_create("set_min_i32");
    tcase_add_test(min_i32, test_set_min_i32);
    suite_add_tcase(test_suite, min_i32);

    min_u32 = tcase_create("set_min_u32");
    tcase_add_test(min_u32, test_set_min_u32);
    suite_add_tcase(test_suite, min_u32);
    
    min_i64 = tcase_create("set_min_i64");
    tcase_add_test(min_i64, test_set_min_i64);
    suite_add_tcase(test_suite, min_i64);

    min_u64 = tcase_create("set_min_u64");
    tcase_add_test(min_u64, test_set_min_u64);
    suite_add_tcase(test_suite, min_u64);
    
    min_f32 = tcase_create("set_min_f32");
    tcase_add_test(min_f32, test_set_min_f32);
    suite_add_tcase(test_suite, min_f32);

    min_f64 = tcase_create("set_min_f64");
    tcase_add_test(min_f64, test_set_min_f64);
    suite_add_tcase(test_suite, min_f64);
}
