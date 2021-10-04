//
// Created by thahnen on 04.10.21.
//

#include "Unittests.h"


/// test cases on set_max* function
START_TEST(test_set_max_i8) {
    int8_t value = INT8_MIN;
    set* t1 = set_create_i8(value);
    set_add_i8(t1, INT8_MAX);
    
    int8_t maximum = 1;
    set_max_i8(t1, &maximum);
    
    ck_assert_int_eq(maximum, INT8_MAX);
    
    
} END_TEST

START_TEST(test_set_max_u8) {
    uint8_t value = 0;
    set* t1 = set_create_u8(value);
    set_add_u8(t1, UINT8_MAX);
    
    uint8_t maximum = 1;
    set_max_u8(t1, &maximum);
    
    ck_assert_int_eq(maximum, UINT8_MAX);
} END_TEST


START_TEST(test_set_max_i16) {
    int16_t value = INT16_MIN;
    set* t1 = set_create_i16(value);
    set_add_i16(t1, INT16_MAX);
    
    int16_t maximum = 1;
    set_max_i16(t1, &maximum);
    
    ck_assert_int_eq(maximum, INT16_MAX);
    
    
} END_TEST

START_TEST(test_set_max_u16) {
    uint16_t value = 0;
    set* t1 = set_create_u16(value);
    set_add_u16(t1, UINT16_MAX);
    
    uint16_t maximum = 1;
    set_max_u16(t1, &maximum);
    
    ck_assert_int_eq(maximum, UINT16_MAX);
} END_TEST


START_TEST(test_set_max_i32) {
    int32_t value = INT32_MIN;
    set* t1 = set_create_i32(value);
    set_add_i32(t1, INT32_MAX);
    
    int32_t maximum = 1;
    set_max_i32(t1, &maximum);
    
    ck_assert_int_eq(maximum, INT32_MAX);
    
    
} END_TEST

START_TEST(test_set_max_u32) {
    uint32_t value = 0;
    set* t1 = set_create_u32(value);
    set_add_u32(t1, UINT32_MAX);
    
    uint32_t maximum = 1;
    set_max_u32(t1, &maximum);
    
    ck_assert_int_eq(maximum, UINT32_MAX);
} END_TEST


START_TEST(test_set_max_i64) {
    int64_t value = INT64_MIN;
    set* t1 = set_create_i64(value);
    set_add_i64(t1, INT64_MAX);
    
    int64_t maximum = 1;
    set_max_i64(t1, &maximum);
    
    ck_assert_int_eq(maximum, INT64_MAX);
    
    
} END_TEST

START_TEST(test_set_max_u64) {
    uint64_t value = 0;
    set* t1 = set_create_u64(value);
    set_add_u64(t1, UINT64_MAX);
    
    uint64_t maximum = 1;
    set_max_u64(t1, &maximum);
    
    ck_assert_int_eq(maximum, UINT64_MAX);
} END_TEST


START_TEST(test_set_max_f32) {
    float32 value = FLT_MIN;
    set* t1 = set_create_f32(value);
    set_add_f32(t1, FLT_MAX);
    
    float32 maximum = 1;
    set_max_f32(t1, &maximum);
    
    ck_assert_float_eq(maximum, FLT_MAX);
} END_TEST

START_TEST(test_set_max_f64) {
    float64 value = DBL_MIN;
    set* t1 = set_create_f64(value);
    set_add_f64(t1, DBL_MAX);
    
    float64 maximum = 1;
    set_max_f64(t1, &maximum);
    
    ck_assert_double_eq(maximum, DBL_MAX);
} END_TEST


// create & add tests
void max_testcases(void) {
    max_i8 = tcase_create("set_max_i8");
    tcase_add_test(max_i8, test_set_max_i8);
    suite_add_tcase(test_suite, max_i8);

    max_u8 = tcase_create("set_max_u8");
    tcase_add_test(max_u8, test_set_max_u8);
    suite_add_tcase(test_suite, max_u8);
    
    max_i16 = tcase_create("set_max_i16");
    tcase_add_test(max_i16, test_set_max_i16);
    suite_add_tcase(test_suite, max_i16);

    max_u16 = tcase_create("set_max_u16");
    tcase_add_test(max_u16, test_set_max_u16);
    suite_add_tcase(test_suite, max_u16);
    
    max_i32 = tcase_create("set_max_i32");
    tcase_add_test(max_i32, test_set_max_i32);
    suite_add_tcase(test_suite, max_i32);

    max_u32 = tcase_create("set_max_u32");
    tcase_add_test(max_u32, test_set_max_u32);
    suite_add_tcase(test_suite, max_u32);
    
    max_i64 = tcase_create("set_max_i64");
    tcase_add_test(max_i64, test_set_max_i64);
    suite_add_tcase(test_suite, max_i64);

    max_u64 = tcase_create("set_max_u64");
    tcase_add_test(max_u64, test_set_max_u64);
    suite_add_tcase(test_suite, max_u64);
    
    max_f32 = tcase_create("set_max_f32");
    tcase_add_test(max_f32, test_set_max_f32);
    suite_add_tcase(test_suite, max_f32);

    max_f64 = tcase_create("set_max_f64");
    tcase_add_test(max_f64, test_set_max_f64);
    suite_add_tcase(test_suite, max_f64);
}
